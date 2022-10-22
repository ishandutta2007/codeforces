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
const int N=2e5;
char c[N];
int f[N];
int main()
{
   ios::sync_with_stdio(false);
   int T;
   cin>>T;
   while (T--)
   {
   	 int n,p,k;
   	 ll x,y; 
      ll ans=1e18;
   	 cin>>n>>p>>k;
   	 cin>>c;
   	 cin>>x>>y;
   	 dep(i,n,n-k+1) f[i]=(c[i-1]=='0');
   	 dep(i,n-k,1) f[i]=f[i+k]+(c[i-1]=='0');
   	 rep(i,p,n) ans=min(ans,(i-p)*y+f[i]*x);
   	 cout<<ans<<endl;
   }
   return 0;
}