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
using namespace std;

struct frac{int first, second;};
bool operator<(frac a, frac b){return (ll)a.first*b.second < (ll)b.first*a.second;}

const int N = 100'010;
set<pair<frac,int>> s;
vector<int> A[N];
bool bad[N];
frac w[N];
int n, m, k;

void init(){
	s.clear();
	Loop(v,0,n){
		if(bad[v]) continue;
		w[v] = {0, A[v].size()};
		for(int u : A[v]) w[v].first += !bad[u];
		s.emplace(w[v],v);
	}
}

void rem(int v){
	s.erase({w[v],v});
	for(int u : A[v]) {
		if(s.count({w[u],u})){
			s.erase({w[u],u});
			w[u].first--;
			s.insert({w[u],u});
		}
	}
}

frac ans={0,1}; int ansi=0;

int main(){
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> m >> k;
	Loop(i,0,k) {int v; cin >> v; bad[v-1]=1;}
	Loop(i,0,m){
		int v, u;
		cin >> v >> u;
		v--; u--;
		A[v].push_back(u);
		A[u].push_back(v);
	}
	init();
	Loop(i,0,n-k){
		if(ans < s.begin()->first){
			ans = s.begin()->first;
			ansi = i;
		}
		rem(s.begin()->second);
	}
	init();
	while(ansi--) rem(s.begin()->second);
	//cout << ans.first <<' '<< ans.second << '\n';
	cout << s.size() << '\n';
	for(auto [_, v] : s) cout << v+1 << ' ';
	cout << '\n';
}