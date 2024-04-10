///
///    Hashire sori yo 
///    Kaze no you ni  
///    Tsukimihara wo  
///    PADORU PADORU   
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

const int mod = 1e9+7;
const int N = 1e6+10;
vector<int> divs[N], sfdivs[N];
int m[N];

void sieve(){
	fill(m, m+N, 1);
	for(ll x = 1; x < N; ++x){
		for(ll y = x; y < N; y+=x)
			divs[y].push_back(x);
		if(divs[x].size()==2){
			for(ll y = x; y < N; y+=x)
				m[y] *= -1;
			for(ll y = x*x; y < N; y+=x*x)
				m[y] = 0;
		}
		if(m[x])
			for(ll y = x; y < N; y+=x)
				sfdivs[y].push_back(x);
	}
}

#define int ll

int cnt[N], cntm[N];
ll ans;
int n, k, q;

const int M = 200'010;
ll mpow(ll x, ll y){ll ans=1;while(y){if(y&1)ans=ans*x%mod;x=x*x%mod;y>>=1;}return ans;}
int fct[M], rev[M];
int C[M];
void calc_fct(){
	fct[0]=1; Loop(i,1,M) fct[i]=fct[i-1]*i%mod;
	rev[M-1]=mpow(fct[M-1],mod-2);
	LoopR(i,0,M-1) rev[i] = rev[i+1]*(i+1)%mod;
	Loop(i,k-1,M) C[i] = (ll)fct[i]*rev[k-1]%mod*rev[i-k+1]%mod;
}


void add(int x){
	for(int z : divs[x]){
		ans -= cnt[z]*z%mod;
		for(int y : sfdivs[x/z]){
			cnt[z] += m[y]==1?C[cntm[z*y]]:-C[cntm[z*y]];
		}
		cnt[z] = (cnt[z]%mod+mod)%mod;
		ans += cnt[z]*z%mod;
	}
	for(int d : divs[x]) cntm[d]++;
	ans = (ans%mod+mod)%mod;
}

signed main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> k >> q;
	sieve(); calc_fct();
	while(n--){int x; cin >> x; add(x);}
	while(q--){int x; cin >> x; add(x); cout << ans << '\n';}
	//cout << clock() << '\n';
}