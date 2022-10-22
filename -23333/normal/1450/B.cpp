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

const int N=10000;
struct re{
	int a,b,c;
}a[N];
int main()
{
   ios::sync_with_stdio(false);
   int T;
   cin>>T;
   while (T--)
   {
   	int n,k;
   	 cin>>n>>k;
   	 rep(i,1,n) cin>>a[i].a>>a[i].b;
   	 int g=0;
   	 rep(i,1,n)
   	 {
   	   bool tf=0;
   	   rep(j,1,n)
   	   {
   	     if (abs(a[i].a-a[j].a)+abs(a[i].b-a[j].b)>k) tf=1;
   	   }
   	   if (!tf)
   	   {
   	   	 g=1; cout<<1<<endl;
   	   	 break;
   	   }
     }
     if (!g) cout<<-1<<endl;
}
   return 0;
}