#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
#define me(x) memset(x,0,sizeof(x))
#define IL inline
#define rint register int
char ss[1<<24],*A=ss,*B=ss;
IL char gc()
{
	return A==B&&(B=(A=ss)+fread(ss,1,1<<24,stdin),A==B)?EOF:*A++;
}
template<class T>void read(T &x)
{
	int f=1,c; while (c=gc(),c<48||c>57) if (c=='-') f=-1; x=(c^48);
	while(c=gc(),c>47&&c<58) x=x*10+(c^48); x*=f;
}
const int mo=1e9+7;
struct re{
	int a,b,c;
};
const int N=3e5;
int n,m;
#define updata(x) num[x]=num[x*2]+num[x*2+1]
#define mid ((h+t)/2) 
struct sgt{
	int lazy[N*5],num[N*5];
	void down(int x,int h,int t)
	{
		if (lazy[x]==-1) return;
		lazy[x*2]=lazy[x*2+1]=lazy[x];
		if (lazy[x])
		{
			num[x*2]=mid-h+1; num[x*2+1]=t-mid; 
		} else num[x*2]=num[x*2+1]=0;
		lazy[x]=-1;
	}
	void change(int x,int h,int t,int h1,int t1,int k)
	{
		if(h1<=h&&t<=t1)
		{
			lazy[x]=k;
			if (k) num[x]=t-h+1; else num[x]=0;
			return;
		}
		down(x,h,t);
		if (h1<=mid) change(x*2,h,mid,h1,t1,k);
		if (mid<t1) change(x*2+1,mid+1,t,h1,t1,k);
		updata(x);
	}
	int query(int x,int h,int t,int h1,int t1)
	{
		if (h1<=h&&t<=t1) return num[x];
		down(x,h,t);
		int ans=0;
		if (h1<=mid) ans+=query(x*2,h,mid,h1,t1);
		if (mid<t1) ans+=query(x*2+1,mid+1,t,h1,t1);
		return ans; 
	}
}S;
char s1[N],s2[N];
int a[N],b[N];
int main()
{
   ios::sync_with_stdio(false);
   int T;
   cin>>T;
   rep(i,0,4*N) S.lazy[i]=-1;
   while (T--)
   {
   	cin>>n>>m;
   	cin>>s1>>s2;
   	rep(i,1,n) S.change(1,1,n,i,i,s2[i-1]-'0');
   	rep(i,1,m)
   	{
   		cin>>a[i]>>b[i];
   	}
   	int tf=0;
   	dep(i,m,1)
   	{
   		int l=b[i]-a[i]+1; 
   		int t=S.query(1,1,n,a[i],b[i]);
   		bool tt=0;
   	    if (2*t>l)
	    {
	    	tt=1;
	    	S.change(1,1,n,a[i],b[i],1);
	    }
	    if (2*(l-t)>l)
	    {
	    	tt=1;
	    	S.change(1,1,n,a[i],b[i],0);
	    }
	    if (!tt)
	    {
	    	tf=1; break;
	    }
   	}
   	rep(i,1,n) if (s1[i-1]-'0'!=S.query(1,1,n,i,i)) tf=1;
   	if (!tf) cout<<"YES"<<endl;
   	else cout<<"NO"<<endl;
   	rep(i,1,5*n) S.lazy[i]=-1,S.num[i]=0;
   }
   return 0;
}