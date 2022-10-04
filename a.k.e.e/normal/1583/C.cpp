#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define pb push_back
#define mp make_pair
template <typename T> void chkmin(T &x,T y){y<x?x=y:T();}
template <typename T> void chkmax(T &x,T y){x<y?x=y:T();}
template <typename T> void readint(T &x)
{
	int f=1;char c;x=0;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+(c-'0');
	x*=f;
}
/*const int MOD=
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}*/
const int MAXN=1000005;

int n,m;
char a[MAXN];
int f[MAXN];

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n),readint(m);
	for(int i=0;i<n;++i)scanf("%s",a+i*m);
	for(int j=1;j<m;++j)
		for(int i=1;i<n;++i)
			if(a[i*m+j-1]=='X' && a[(i-1)*m+j]=='X'){f[j]=1;break;}
	for(int i=1;i<m;++i)f[i]+=f[i-1];
	int Q,l,r;
	readint(Q);
	while(Q--)
	{
		readint(l),readint(r);--l,--r;
		printf(f[r]>f[l]?"NO\n":"YES\n");
	}
	return 0;
}