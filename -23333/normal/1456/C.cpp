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
const int N=6e5;
int a[N];
bool cmp(int x,int y)
{
	return x>y;
}
struct cmp2{
	bool operator () (ll x,ll y)
	{
		return x<y;
	}
};
priority_queue<ll,vector<ll>,cmp2> q;
int main()
{
   ios::sync_with_stdio(false);
   int n,k;
   cin>>n>>k;
   rep(i,1,n) cin>>a[i];
   sort(a+1,a+n+1,cmp);
   ll now=0,ans=0;
   int jl=0;
   rep(i,1,n)
   {
   	 ans+=now;
   	 now+=a[i];
   	 if (now<0)
   	 {
   	 	a[i]=now; jl=i; break;
   	 }
   }
   if (!jl)
   {  
     cout<<ans<<endl; return 0;
   }
   rep(i,1,k+1) q.push(0);
   rep(i,jl,n)
   {
   	 ll x=q.top(); ans+=x; q.pop();
   	 x+=a[i]; q.push(x);
   }
   cout<<ans<<endl;
   return 0;
}