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
const int Maxn = 5e2 + 10;
const int Maxm = 86500;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

char a[Maxn][Maxn];
ll ps1[Maxn][Maxn];
ll ps2[Maxn][Maxn];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll h, w;
	cin >> h >> w;
	for(int i = 1; i <= h; i++) for(int j = 1; j <= w; j++) cin >> a[i][j];
	for(int i = 1; i <= h; i++){
		for(int j = 1; j + 1 <= w; j++){
			ps1[i][j] = ps1[i - 1][j] + ps1[i][j - 1] - ps1[i - 1][j - 1] + (a[i][j] == '.' && a[i][j + 1] == '.');
		}
	}
	for(int i = 1; i + 1 <= h; i++){
		for(int j = 1; j <= w; j++){
			ps2[i][j] = ps2[i - 1][j] + ps2[i][j - 1] - ps2[i - 1][j - 1] + (a[i][j] == '.' && a[i + 1][j] == '.');
		}
	}
	ll q;
	cin >> q;
	ll r1,c1,r2,c2;
	for(int i = 0; i < q; i++){
		cin >> r1 >> c1 >> r2 >> c2;
		cout << ( ps1[r2][c2 - 1] + ps1[r1 - 1][c1 - 1] - ps1[r2][c1 - 1] - ps1[r1 - 1][c2 - 1]  ) + (ps2[r2 - 1][c2] + ps2[r1 - 1][c1 - 1] - ps2[r2 - 1][c1 - 1] - ps2[r1 - 1][c2]) << '\n';
	}
	return 0;
}