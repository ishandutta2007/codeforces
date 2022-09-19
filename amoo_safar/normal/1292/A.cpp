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
const int Maxn = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int f[3][Maxn];

int cnt = 0;
int calc(int a, int b){
	int aa = 3 - a;
	int res = 0;
	for(int i = -1; i < 2; i++){
		if(f[a][b] == 1 && f[aa][b + i] == 1) res ++;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, q;
	cin >> n >> q;
	ll x, y;
	for(int i = 0; i < q; i++){
		cin >> x >> y;
		cnt -= calc(x, y);
		f[x][y] = 1 - f[x][y];
		cnt += calc(x, y);
		if(cnt == 0 && f[1][1] == 0 && f[2][n] == 0) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}