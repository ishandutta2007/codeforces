#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())

const ll MAXN = 1e5 + 10;
const ll MAXG = 32;
const ll SIG = 27;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n , q , mark[MAXG] , nxt[MAXN][SIG] , prv[MAXN][SIG] , gnxt[MAXN][SIG] , gprv[MAXN][SIG] , xr[MAXN];
string s;

int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> s >> q;
	n = SZ(s);
	s = string(1 , 123) + s + string(1 , 123);
	for(int i = 1 ; i <= n + 1 ; i++){
		for(int j = 0 ; j < SIG ; j++){
			prv[i][j] = prv[i - 1][j];
		}
		prv[i][s[i - 1] - 97] = i - 1;
	}
	fill(nxt[n + 1] , nxt[n + 1] + SIG , n + 1);
	for(int i = n ; i >= 0 ; i--){
		for(int j = 0 ; j < SIG ; j++){
			nxt[i][j] = nxt[i + 1][j];
		}
		nxt[i][s[i + 1] - 97] = i + 1;
	}
	for(int i = 1 ; i <= n + 1 ; i++){
		vector<pii> vec;
		for(int j = 0 ; j < SIG ; j++){
			vec.push_back({prv[i][j] , j});
		}
		sort(all(vec) , greater<pii>());
		int x = s[i] - 97;
		for(pii j : vec){
			int y = j.Y , pos = j.X;
			fill(mark , mark + MAXG , 0);
			for(int k = 0 ; k < SIG ; k++){
				if(prv[i][k] <= pos)	continue;
				mark[gprv[i][k] ^ xr[prv[i][k]] ^ xr[nxt[pos][k]] ^ gprv[nxt[pos][k]][y]] = 1;
			}
			for(int k = 0 ; k < MAXG ; k++){
				if(!mark[k]){
					gprv[i][y] = k;
					break;
				}
			}
		}
		xr[i] = xr[prv[i][x]] ^ gprv[i][x];
	}
	for(int i = n ; i >= 0 ; i--){
		vector<pii> vec;
		for(int j = 0 ; j < SIG ; j++){
			vec.push_back({nxt[i][j] , j});
		}
		sort(all(vec));
		int x = s[i] - 97;
		for(pii j : vec){
			int y = j.Y , pos = j.X;
			fill(mark , mark + MAXG , 0);
			for(int k = 0 ; k < SIG ; k++){
				if(nxt[i][k] >= pos)	continue;
				mark[gnxt[i][k] ^ xr[nxt[i][k]] ^ xr[prv[pos][k]] ^ gnxt[prv[pos][k]][y]] = 1;
			}
			for(int k = 0 ; k < MAXG ; k++){
				if(!mark[k]){
					gnxt[i][y] = k;
					break;
				}
			}
		}
	}
	while(q--){
		int l , r , ans = 0;
		cin >> l >> r; l--, r++;
		for(int i = 0 ; i < SIG ; i++){
			if(nxt[l][i] >= r)	continue;
			int val = gnxt[l][i] ^ xr[nxt[l][i]] ^ xr[prv[r][i]] ^ gprv[r][i];
			// cout << i << sep << val << sep << nxt[l][i] << endl;
			if(val == 0)	ans = 1;
		}
		cout << (ans ? "Alice" : "Bob") << endl;
	}

	return 0;
}
/*

*/