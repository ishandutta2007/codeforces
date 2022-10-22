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
const int N=5000;
int a[N],b[N];
bool f[N];
int main()
{
	ios::sync_with_stdio(false);
	int T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		rep(i,1,2*n) cin>>a[i];
		int now=1,cnt=0;
		rep(i,1,2*n)
		{
			if (a[i]>a[now])
			{ 
			  b[++cnt]=i-now;
			  now=i;
		    }
		}
		b[++cnt]=2*n-now+1;
		memset(f,0,sizeof(f));
		f[0]=1;
		rep(i,1,cnt)
		  dep(j,n,b[i])
		    f[j]|=f[j-b[i]];
		if (f[n]) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
    }
	return 0; 
}