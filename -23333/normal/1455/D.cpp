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
const int N=1000;
int a[N];
int n,x;
int cl(int pos,int x)
{
	 bool tf=0;
   	 rep(i,pos+1,n) if (a[i]<a[i-1]) tf=1;
   	 if (!tf)
     {
     	return 0;
     } else
     {
     	int jl=0,cnt=0;
     	rep(i,pos,n)
     	{
          if (a[i]>x)
          {
          	jl=i; break;
          }
          if (i!=pos&&a[i]<a[i-1]) return -1e9;
        }
        if (x>a[jl+1]) return -1e9;
        return cl(jl+1,a[jl])+1;
     }
}
int main()
{
   ios::sync_with_stdio(false);
   int T;
   cin>>T;
   while(T--)
   {
   	 cin>>n>>x;
   	 rep(i,1,n) cin>>a[i]; a[n+1]=1e9;
   	 int ans=cl(1,x);
   	 if (ans<0) cout<<-1<<endl;
   	 else cout<<ans<<endl;
   }
   return 0;
}