#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll Mod = 1000000007LL;
const int Maxn = 1e3 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll cnt[Maxn][30], c2[30];

vector< pair<ll, pair<char, char> > > G[Maxn];

char ans[Maxn];

ll rt = -1;
str solve(int l, int r){
	memset(cnt, 0, sizeof cnt);
	if(r <= l) return "";
	cout << "? " << l + 1 << " " << r << endl;
	
	str s, t;
	ll len  = r - l;
	ll C = (len + 1) * (len) / 2LL;
	for(int i = 0; i < C; i++){
		cin >> t;
		int sz = t.size();
		for(auto x : t) cnt[sz][x - 'a'] ++;
	}
	ll it = (len + 1) / 2;
	
	str al = "";
	
	for(int i = 1, L = l +1, R = r; i <= it; L++,R--, i++){
		//cerr << i << '\n';
		memset(c2, 0, sizeof c2);
		for(int j = 0; j < 28; j++) c2[j] = cnt[i][j] + cnt[1][j];
		//cerr << i << '\n';
		for(auto x : al) c2[x - 'a'] --;
		
		str SS = "";
		for(int j = 0; j < 28; j++){
			while(c2[j] > cnt[i + 1][j]){
				c2[j] --;
				SS += ((char)(j + 'a'));
			}
		}
		if(L == R){
			ans[L] = SS[0];
			rt = L;
		} else {
			G[L].pb({R, {SS[0], SS[1]}});
			G[R].pb({L, {SS[0], SS[1]}});
		}
		al += SS;
		//cerr << "!!!" << SS << '\n';
	}
	return al;
}

ll mk[Maxn];

void DFS(int u){
	mk[u] = 1;
	int adj;
	for(auto e : G[u]){
		adj = e.F;
		if(!mk[adj]){
			ans[adj] = (ans[u] == e.S.F ? e.S.S : e.S.F);
			DFS(adj);
		}
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	if(n <= 3){
		for(int i = 1; i <= n; i++){
			cout << "? " << i << " " << i << endl;
			cin >> ans[i];
		}
		
		cout << "! ";
		for(int i = 1; i <= n; i++) cout << ans[i];
		cout << endl;
		return 0;
	}
	solve(0, n);
	solve(0, n / 2 + 1);
	solve(0, n / 2);
	assert(rt != -1);
	DFS(rt);
	cout << "! ";
	for(int i = 1; i <= n; i++) cout << ans[i];
	cout << endl;
	return 0;
}

/*
4

a b c d
ab bc cd
abc bcd
abcd


*/