// That's How much we have in common
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

ll a[N];

ll nx[N];
int mk[N], sz;
vector<ll> G[N];

void DFS(int u){
	if(!mk[u]) sz ++;
	mk[u] = 2;
	for(auto adj : G[u])
		if(!mk[adj])
			DFS(adj);
}

ll f(ll x){
	ll res = 0;
	while(x > 1){
		res ++;
		x -= 3;
	}
	return res;
}

void Main(){
	ll n;
	cin >> n;
	str s;
	cin >> s;

	for(int i = 0; i < n; i++){
		if(s[i] == 'L') nx[i] = (i - 1 + n) % n;
		else nx[i] = (i+1) % n;
	}
	bool flg = false;
	for(int i = 0; i + 1  < n; i++){
		if(s[i] != s[i + 1]) flg = true;
	}
	if(!flg){
		cout << f(n - 2) + 1 << '\n';
		return ;
	}
	fill(mk, mk + n, 0);
	for(int i = 0; i < n; i++) G[i].clear();
	for(int i = 0; i < n; i++){
		if(nx[nx[i]] == i){
			mk[i] = 1;
		}
		G[nx[i]].pb(i);
	}

	ll ans = 0;
	for(int i = 0; i < n; i++) if(mk[i] == 1){
		sz = 0;
		DFS(i);
		ans += f(sz);
	}
	cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	for(int i = 1; i <= T; i++){
		Main();
	}
	return 0;
}