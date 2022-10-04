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
const int MAXN=100005;

int a[6],n,b[MAXN],c[MAXN];
priority_queue<pii,vector<pii>,greater<pii> > pq;
multiset<int> s;

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	for(int i=0;i<6;++i)readint(a[i]);
	sort(a,a+6);
	readint(n);
	int ans=1<<30;
	for(int j=1;j<=n;++j)
	{
		readint(b[j]);
		pq.push(mp(b[j]-a[c[j]=5],j));
		s.insert(b[j]-a[5]);
	}
	while(!pq.empty())
	{
		chkmin(ans,*(--s.end())-*s.begin());
		pii p=pq.top();pq.pop();
		int u=p.y;
		if(c[u]>0)
		{
			--c[u];
			s.erase(s.find(p.x));
			pq.push(mp(b[u]-a[c[u]],u));
			s.insert(b[u]-a[c[u]]);
		}
	}
	chkmin(ans,*(--s.end())-*s.begin());
	printf("%d\n",ans);
	return 0;
}