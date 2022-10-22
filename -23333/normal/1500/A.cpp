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
const int N=5e5;
struct re{
	int a,b;
}a[N],b[N];
vector<re> f[N*11];
bool cmp(re x,re y)
{
	return x.a<y.a;
}
bool pd(int a,int b,int c,int d)
{
	if (a==c||a==d||b==c||b==d) return 0;
	return 1;
}
int main()
{
   ios::sync_with_stdio(false);
   int n;
   cin>>n;
   rep(i,1,n) cin>>a[i].a,a[i].b=i;
   sort(a+1,a+n+1,cmp);
   int cnt=3; b[1]=a[1]; b[2]=a[2]; b[3]=a[3];
   rep(i,4,n)
   {
   	 if (!(a[i-1].a==a[i].a&&a[i-2].a==a[i].a&&a[i-3].a==a[i].a&&a[i-4].a==a[i].a)) b[++cnt]=a[i];
   }
   n=min(n,min(cnt,4000));
   rep(i,1,n)
     rep(j,i+1,n)
         f[b[i].a+b[j].a].push_back((re){b[i].b,b[j].b});
   rep(i,1,5e6)
   {
   	int t=f[i].size(); t--;
   	rep(j,0,t)
   	  rep(k,j+1,t)
   	  {
   	  	if (pd(f[i][j].a,f[i][j].b,f[i][k].a,f[i][k].b))
   	  	{
   	  		cout<<"YES"<<endl;
   	  		cout<<f[i][j].a<<" "<<f[i][j].b<<" "<<f[i][k].a<<" "<<f[i][k].b<<endl;
			return 0;	  
   	  	}
   	  }
   }
   cout<<"NO"<<endl; 
   return 0;
}