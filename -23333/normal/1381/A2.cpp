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
const int N=2e5;
char s1[N],s2[N];
int c[N];
int main()
{
	ios::sync_with_stdio(false);
	int T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		cin>>s1>>s2;
		int h=1,t=n,fz=0;
		int cnt=0; 
		dep(i,n,1)
		{
			if (!fz)
			{
				if (s1[h-1]==s2[i-1])
				{
					c[++cnt]=1; c[++cnt]=i;
				} else
				{
					c[++cnt]=i;
				}
				h++; fz^=1;
			} else
			{
				if (s1[t-1]!=s2[i-1])
				{
					c[++cnt]=1; c[++cnt]=i;
				} else
				{
					c[++cnt]=i;
				}
				t--; fz^=1;
			}
		}
		cout<<cnt<<" ";
		rep(i,1,cnt) cout<<c[i]<<" ";
		cout<<endl;
    }
	return 0; 
}