#include <bits/stdc++.h>
using namespace std;
#define rint register int
#define IL inline
#define rep(i,h,t) for(int i=h;i<=t;i++)
#define dep(i,t,h) for(int i=t;i>=h;i--)
#define ll long long
#define me(x) memset(x,0,sizeof(x))
#define mep(x,y) memcpy(x,y,sizeof(y))
#define mid ((h+t)>>1)
namespace IO{
    char ss[1<<24],*A=ss,*B=ss;
    IL char gc()
    {
        return A==B&&(B=(A=ss)+fread(ss,1,1<<24,stdin),A==B)?EOF:*A++;
    }
    template<class T> void read(T &x)
    {
        rint f=1,c; while (c=gc(),c<48||c>57) if (c=='-') f=-1; x=(c^48);
        while (c=gc(),c>47&&c<58) x=(x<<3)+(x<<1)+(c^48); x*=f; 
    }
    char sr[1<<24],z[20]; int Z,C1=-1;
    template<class T>void wer(T x)
    {
        if (x<0) sr[++C1]='-',x=-x;
        while (z[++Z]=x%10+48,x/=10);
        while (sr[++C1]=z[Z],--Z);
    }
    IL void wer1()
    {
        sr[++C1]=' ';
    }
    IL void wer2()
    {
        sr[++C1]='\n';
    }
    template<class T>IL void maxa(T &x,T y) {if (x<y) x=y;}
    template<class T>IL void mina(T &x,T y) {if (x>y) x=y;} 
    template<class T>IL T MAX(T x,T y){return x>y?x:y;}
    template<class T>IL T MIN(T x,T y){return x<y?x:y;}
};
using namespace IO;
const int N=3.1e5;
const int N1=N*4;
struct re{
	int a,b;
};
bool cmp(re x,re y)
{
	return x.b<y.b;
}
vector<re> ve[N];
struct sgt{
	vector<re> ve1[N1];
	IL void updata(int x)
	{
		int l1=(int)(ve1[x*2].size())-1;
		int l2=(int)(ve1[x*2+1].size())-1;
	    int h1=0,h2=0,lst1=0,lst2=0;
	    while (h1<=l1||h2<=l2)
	    {
	    	int t;
			if (h1<=l1&&h2<=l2)
			  t=MIN(ve1[x*2][h1].b,ve1[x*2+1][h2].b);
			else if (h1<=l1) t=ve1[x*2][h1].b; else t=ve1[x*2+1][h2].b;
	    	while (h1<=l1&&ve1[x*2][h1].b==t)
	    	  maxa(lst1,ve1[x*2][h1].a),h1++;
	    	while (h2<=l2&&ve1[x*2+1][h2].b==t)
	    	  maxa(lst2,ve1[x*2+1][h2].a),h2++;
	    	ve1[x].push_back((re){MIN(lst1,lst2),t});
	    }
	}
	void build(int x,int h,int t)
	{
		if (h==t)
		{
		  int l=(int)(ve[h].size())-1;
		  rep(i,0,l) ve1[x].push_back(ve[h][i]);
		  sort(ve1[x].begin(),ve1[x].end(),cmp);
		  int lst=0;
		  rep(i,0,l)
		  {
		  	maxa(lst,ve1[x][i].a);
		    ve1[x][i].a=lst;
		  }
		  return;
	    }
		build(x*2,h,mid); build(x*2+1,mid+1,t);
		updata(x);
	}
	IL bool query(int x,int h,int t,int h1,int t1,int x1,int y)
	{
		if (h1<=h&&t<=t1)
		{
		  int h=0,t=(int)(ve1[x].size())-1;
		  if (t<0) return(0);
		  if (ve1[x][h].b>y) return(0);
		  while (h<t)
		  {
		  	int mid2=(h+t+1)/2;
		  	if (ve1[x][mid2].b<=y) h=mid2; else t=mid2-1;
		  }
		  if (ve1[x][h].a>=x1) return(1); else return(0);
	    }
		bool tt=1;
		if (h1<=mid) tt&=query(x*2,h,mid,h1,t1,x1,y);
		if (mid<t1) tt&=query(x*2+1,mid+1,t,h1,t1,x1,y);
		return tt; 
	}
}S;
int main()
{
	int n,m,k;
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	rep(i,1,k)
	{
		int x,y,z;
		cin>>x>>y>>z;
		ve[z].push_back((re){x,y});
	}
	S.build(1,1,n);
	rep(i,1,m)
	{
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		if (S.query(1,1,n,x1,y1,x2,y2)) cout.flush()<<"yes"<<endl;
		else cout.flush()<<"no"<<endl;
	}
	return 0;
}