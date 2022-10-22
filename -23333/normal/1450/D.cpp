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
const int N=4e5;
int a[N],b[N],l[N],r[N],g[N],cnt,p[N];
bool t[N];
multiset<int> S[N];
vector<re> ve[N];
bool cmp(re x,re y)
{
	return x.b-x.a+1>y.b-y.a+1;
}	
int main()
{
   ios::sync_with_stdio(false);
   int T; 
   cin>>T;
   while(T--)
   {
   	 int n;
   	 cin>>n;
   	 rep(i,1,n) cin>>a[i],g[a[i]]++;
   	 t[0]=1;
   	 rep(i,1,n) t[i]=t[i-1]&(g[i]>=1); 
   	 cnt=0; b[0]=0;
   	 rep(i,1,n)
   	 {
   	 	while(cnt>=1&&a[i]<=a[b[cnt]]) cnt--;
   	 	l[i]=b[cnt]+1; b[++cnt]=i;
   	 }
   	 cnt=0; b[0]=n+1;
   	 dep(i,n,1)
   	 {
   	 	while(cnt>=1&&a[i]<=a[b[cnt]]) cnt--;
   	 	r[i]=b[cnt]-1; b[++cnt]=i;
   	 }
   	 rep(i,1,n)
   	 {
   	 	ve[a[i]].push_back((re){l[i],r[i]});
   	 }
   	 int ans=0;
			  rep(i,1,n)
			  {
			  	sort(ve[i].begin(),ve[i].end(),cmp);
			  	int x=ve[i].size();
			  	if (x>1)
			  	{
			  		if (ve[i][0].a!=ve[i][1].a||ve[i][0].b!=ve[i][1].b) ans=max(ans,ve[i][0].b-ve[i][0].a+1);
			  		else ans=max(ans,ve[i][1].b-ve[i][1].a);
			  		rep(j,2,x-1) 
					  if (ve[i][0].a!=ve[i][1].a||ve[i][0].b!=ve[i][1].b)
					    ans=max(ans,ve[i][j].b-ve[i][j].a+1);
			  	}	
			  }	
     rep(i,1,n)
     {
     	if (i==l[i]||i==r[i])
   	 	{
   	 	} else
   	 	{
   	 		ans=max(ans,r[i]-l[i]);
   	 	}
     }
	 rep(i,1,n) if (t[n-i+1]&&(i>ans||i==1)) cout<<1; else cout<<0;
	 cout<<endl;
   	 rep(i,1,n) g[i]=0,ve[i].clear();
   }
   return 0;
}