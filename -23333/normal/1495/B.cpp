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
int d[N],f1[N],f2[N];
int main()
{
   ios::sync_with_stdio(false);
   int n;
   cin>>n;
   rep(i,1,n) cin>>d[i];
   f1[1]=0; f2[n]=0;
   rep(i,2,n) if (d[i]>d[i-1]) f1[i]=f1[i-1]+1; else f1[i]=0;
   dep(i,n-1,1) if (d[i]>d[i+1]) f2[i]=f2[i+1]+1; else f2[i]=0;
   int ans=0;
   rep(i,1,n) ans=max(ans,f1[i]);
   rep(i,1,n) ans=max(ans,f2[i]);
   int cnt=0;
   rep(i,1,n) if (max(f1[i],f2[i])==ans) cnt++;
   int num=0;
   rep(i,1,n)
   {
   	 bool tt=1;
   	 if (max(f1[i],f2[i])!=ans) tt=0;
   	 if (cnt>1) tt=0;
   	 int x3=f1[i]%2==0?f1[i]-1:f1[i];
   	 int x4=f2[i]%2==0?f2[i]-1:f2[i];
   	 if (!(f1[i]>x4&&f2[i]>x3)) tt=0;
   	 if (tt) num++;
   }
   cout<<num<<endl;
   return 0;
}