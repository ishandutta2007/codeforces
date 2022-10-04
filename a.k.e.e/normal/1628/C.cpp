#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define pb push_back
#define mp make_pair
template <typename T> bool chkmin(T &x,T y){return y<x?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template <typename T> void readint(T &x)
{
	int f=1;char c;x=0;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+(c-'0');
	x*=f;
}
const int MOD=998244353;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}
const int MAXN=1005;

int n;
void solve()
{
	readint(n);
	int res=0;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
		{
			int w;
			readint(w);
			if(i&1)
			{
				int m=n/2-1,x=i/2,y=((j&1)?j:n-1-j)/2;
				int t=min(min(x,y),min(m-x-1,m-y-1));
				if(i<n-1 && !(t&1))res^=w;
			}
			else
			{
				int m=n/2,x=i/2,y=((j&1)?j:n-1-j)/2;
				int t=min(min(x,y),min(m-x-1,m-y-1));
				if(!(t&1))res^=w;
			}
		}
	printf("%d\n",res);
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int T;
	readint(T);
	while(T--)solve();
	return 0;
}