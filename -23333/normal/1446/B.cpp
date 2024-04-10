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
const int N=5000+20;
char s1[N],s2[N];
int f[N][N],sum[N][N],n,m;
int main()
{
	cin>>n>>m;
	cin>>s1>>s2;
	int ans=0;
    rep(i,1,n)
      rep(j,1,m)
      {
        if (s1[i-1]==s2[j-1]) f[i][j]=f[i-1][j-1]+2;
	    f[i][j]=max(f[i][j-1]-1,f[i][j]);
	    f[i][j]=max(f[i-1][j]-1,f[i][j]);
	    ans=max(ans,f[i][j]);
      }
    cout<<ans<<endl;
	return 0; 
}