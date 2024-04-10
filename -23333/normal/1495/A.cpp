#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
#define me(x) memset(x,0,sizeof(x))
#define IL inline
#define rint register int
inline ll rd(){
	ll x=0;char c=getchar();bool f=0;
	while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f?-x:x;
}
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
const int N=3e5;
struct re{
	int a,b,c;
}a[N];
int d[N],c[N];
int main()
{
   ios::sync_with_stdio(false);
   int T;
   cin>>T;
   while (T--)
   {
   	int n;
   	 cin>>n;
   	 int n1=0,n2=0;
   	 rep(i,1,n*2)
   	 {
   	 	cin>>a[i].a>>a[i].b;
   	 	if (a[i].a==0) d[++n1]=abs(a[i].b);
   	 	else c[++n2]=abs(a[i].a);
     }
        	 	sort(c+1,c+n+1);
   	 	sort(d+1,d+n+1);
   	 	double ans=0;
   	 	rep(i,1,n)
   	 	{
   	 		ans+=sqrt(1.0*c[i]*c[i]+1.0*d[i]*d[i]);
   	 	}
   	 	printf("%.15lf\n",ans);
   }
   return 0;
}