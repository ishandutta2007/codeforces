#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define x first
#define y second
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x,T y){x<y?x=y:T();}
template <typename T> void chkmin(T &x,T y){x>y?x=y:T();}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
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
const int MAXN=100005;

char a[MAXN];
int n,cnt[30];
ll m;

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n),readint(m);
	scanf("%s",a+1);
	for(int i=1;i<=n-2;++i)++cnt[a[i]-'a'+1],m+=(1ll<<(a[i]-'a'));
	m+=(1ll<<(a[n-1]-'a')),m-=(1ll<<(a[n]-'a'));
	if(m<0)return 0*printf("No\n");
	for(int i=27;i>=0;--i)
		while(cnt[i] && m>=(1ll<<i))
			--cnt[i],m-=(1ll<<i);
	printf(m?"No\n":"Yes\n");
	return 0;
}