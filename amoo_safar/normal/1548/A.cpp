// vaziat meshki-ghermeze !
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int ans = 0;
set<int> st[N];

bool Calc(int u){
	return (st[u].empty() ? -1 : *st[u].rbegin()) < u;
}

void Add(int u, int v){
	st[u].insert(v);
	st[v].insert(u);
}

void Del(int u, int v){
	st[u].erase(v);
	st[v].erase(u);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	ans = n;
	int u, v;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		ans -= Calc(u);
		ans -= Calc(v);
		Add(u, v);
		ans += Calc(u);
		ans += Calc(v);
	}
	int t, q;
	cin >> q;
	for(int i = 0; i < q; i++){
		cin >> t;
		if(t == 3){
			cout << ans << '\n';
			continue;
		}
		cin >> u >> v;
		ans -= Calc(u);
		ans -= Calc(v);
		if(t == 1)
			Add(u, v);
		else
			Del(u, v);
		ans += Calc(u);
		ans += Calc(v);
	}
	return 0;
}