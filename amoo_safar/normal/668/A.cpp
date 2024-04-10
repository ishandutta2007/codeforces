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
const int Maxn = 1e2 + 10;
const int Q = 1e4 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll a[Maxn][Maxn], f[Maxn][Maxn];
ll t[Q], r[Q], c[Q], x[Q];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m, q;
	cin >> n >> m >> q;
	for(int i = 0; i < q; i++){
		cin >> t[i];
		if(t[i] == 1) cin >> r[i];
		else if(t[i] == 2) cin >> c[i];
		else cin >> r[i] >> c[i] >> x[i]; 
	}
	for(int i = q- 1; i >=0;i--){
		if(t[i] == 1){
			for(int j = m - 1; j > 0; j--) swap(a[r[i]][j], a[r[i]][j + 1]);
		} else if(t[i] == 2){
			for(int j = n - 1; j > 0; j--) swap(a[j][c[i]], a[j + 1][c[i]]);
		} else {
			a[r[i]][c[i]] = x[i];
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++) cout << a[i][j] << " ";
		cout << '\n';
	}
	return 0;
}