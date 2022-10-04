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
const int MOD=1000000007;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}
inline int inv(int x){return qmi(x,MOD-2);}
const int MAXN=200005;

int n;
pii a[MAXN];
bool cho[MAXN];
ll w;
void solve()
{
	readint(n),readint(w);
	for(int i=1;i<=n;++i)readint(a[i].x),a[i].y=i,cho[i]=0;
	for(int i=1;i<=n;++i)
		if(a[i].x>=(w+1)/2 && a[i].x<=w)
		{
			printf("1\n%d\n",a[i].y);
			return;
		}
	sort(a+1,a+n+1);
	ll s=0;bool flag=0;int cnt=0;
	for(int i=1;i<=n;++i)
	{
		s+=a[i].x;cho[a[i].y]=1;++cnt;
		if(s>=(w+1)/2 && s<=w){flag=1;break;}
	}
	if(!flag){printf("-1\n");return;}
	printf("%d\n",cnt);
	for(int i=1;i<=n;++i)if(cho[i])printf("%d ",i);
	putchar('\n');
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