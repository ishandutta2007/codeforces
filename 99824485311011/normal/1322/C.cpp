#include<bits/stdc++.h>
using namespace std;
#define lc (p<<1)
#define rc ((p<<1)|1)
typedef long long ll;
typedef unsigned long long ull;
mt19937 rnd(chrono::duration_cast<chrono::nanoseconds>(chrono::steady_clock::now().time_since_epoch()).count());
constexpr uint64_t mod =(1ull<<61)-1;
const ull bas=rnd()%500000+500001;
uint64_t mult(uint64_t a, uint64_t b)
{
	uint64_t l1 = (uint32_t)a, h1 = a>>32, l2 = (uint32_t)b, h2 = b>>32;
	uint64_t l = l1*l2, m = l1*h2 + l2*h1, h = h1*h2;
	uint64_t ret = (l&mod) + (l>>61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
	ret = (ret & mod) + (ret>>61);
	ret = (ret & mod) + (ret>>61);
	return ret-1;
}
inline ull add(ull a,ull b)
{
	if((a+=b)>=mod)a-=mod;
	return a;
}
int T;
int n,m;
ll c[500010],S[500010];
ull hs[500010];
vector<int> L[500010],R[500010];
map<ull,ll> mp;
void solve()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)L[i].clear(),R[i].clear();
	for(int i=1;i<=n;i++)scanf("%lld",&c[i]);
	for(int i=1,ti,tj;i<=m;i++)
	{
		scanf("%d%d",&ti,&tj);
		L[ti].push_back(tj);
		R[tj].push_back(ti);
	}
	for(int i=1;i<=n;i++)
	{
		S[i]=0;
		for(int &x:L[i])S[i]+=c[x];
	}
	ll g=S[1];
	for(int i=2;i<=n;i++)g=__gcd(g,S[i]);
	mp.clear();
	for(int i=1;i<=n;i++)
	{
		sort(R[i].begin(),R[i].end());
		hs[i]=0;
		for(auto &x:R[i])hs[i]=add(mult(hs[i],bas),x);
		mp[hs[i]]+=c[i];
	}
	for(auto &x:mp)if(x.first)g=__gcd(g,x.second);
	printf("%lld\n",g);
}
int main()
{
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}