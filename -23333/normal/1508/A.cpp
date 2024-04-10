//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")

//#include <immintrin.h>
//#include <emmintrin.h>
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
template<class T>void maxa(T &x,T y)
{
	if (y>x) x=y;
}
template<class T>void mina(T &x,T y)
{
	if (y<x) x=y;
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
char s[3][N],p[3][N];
int f[3];
vector<char> ve;
int main()
{
   ios::sync_with_stdio(false);
   int T;
   cin>>T;
   while (T--)
   {
   	int n;
   	cin>>n;
   	cin>>(s[0]+1)>>(s[1]+1)>>(s[2]+1);
   	f[0]=f[1]=f[2]=0;
   	rep(j,0,2)
      rep(i,1,2*n) if (s[j][i]=='0') f[j]++;
    int ans=0,cnt=0;
    rep(i,0,2) ans+=(f[i]<=n);
    bool tt=0;
    ve.clear();
    if (ans<2)
    {
    	tt=1;
    	rep(j,0,2)
          rep(i,1,2*n) if (s[j][i]=='0') s[j][i]='1'; else s[j][i]='0';
    }
    rep(i,0,2) if ((!tt&&f[i]<=n)||(tt&&f[i]>=n))
    {
    	cnt++;
    	rep(j,1,2*n) p[cnt][j]=s[i][j];
    }
    	int now=1;
    	rep(j,1,2*n)
    	{
    	  if (p[1][j]=='1')
		  { 
    	    while(now<=2*n&&p[2][now]=='0') ve.push_back('0'),now++;
		    ve.push_back('1');
    	    now++;
    	  } else ve.push_back('0');
        }
        while(now<=2*n) ve.push_back(p[2][now]),now++;
        int nn=ve.size();
        rep(j,nn+1,3*n) ve.push_back('0');
    for (auto i:ve)
    {
    	if (tt)
    	{
    		if (i=='0') cout<<1; else cout<<0;
    	} else cout<<i;
    }
    cout<<endl;
   }
   return 0;
}