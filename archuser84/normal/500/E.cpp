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

const int N = 200'010;
int st[N], sp = N;
int v[N];
int p[N], h[N];
vector<pii> Q[N];
int n, q;

int fen[N+1];
void add(int i, ll x){
	++i;
	while(i <= N){
		fen[i] += x;
		i += i&-i;
	}
}
int get(int r){
	int ans = 0;
	while(r){
		ans += fen[r];
		r -= r&-r;
	}
	return ans;
}

int ans[N];

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n;
	Loop(i,0,n) cin >> p[i] >> h[i];
	cin >> q;
	Loop(i,0,q){
		int x, y;
		cin >> x >> y;
		Q[x-1].emplace_back(y-1,i);
	}
	LoopR(i,0,n){
		while(sp < N && p[st[sp]]+h[st[sp]] <= p[i]+h[i]){
			add(sp, -v[sp]);
			v[sp] = 0;
			++sp;
		}
		st[--sp] = i;
		if(sp+1<N) v[sp] = max(0, p[st[sp+1]]-(p[i]+h[i]));
		add(sp, v[sp]);
		for(auto [j, k] : Q[i]){
			int r = upper_bound(st+sp, st+N, j)-st-1;
			ans[k] = get(r);
		}
	}
	Loop(i,0,q) cout << ans[i] << '\n';
}