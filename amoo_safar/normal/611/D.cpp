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
const int Maxn = 5e3 + 10;
const int Maxm = 86500;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int lcp[Maxn][Maxn];
ll dp[Maxn][Maxn];
ll ps[Maxn][Maxn];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	str s;
	cin >> n >> s;
	for(int i = n - 1; i >= 0; i--){
		for(int j = n - 1; j >= 0; j--) lcp[i][j] = (s[i] == s[j] ? 1 + lcp[i + 1][j + 1] : 0);
	}
	
	dp[0][0] = 1;
	fill(ps[0], ps[0] + Maxn, 1);
	
	int f, lc;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			if(s[i - j] == '0') continue;
			f = 1;
			if(dp[i - j][j] == 0) f = 0;
			else {
				lc = lcp[i - j][i - j - j];
				if(lc >= j) f = 0;
				else {
					if(s[i - j + lc] < s[i - j - j + lc]) f = 0;
				}
			}
			dp[i][j] = ps[i - j][j - 1] + dp[i - j][j] * f;
		}
		ps[i][0] = dp[i][0];
		for(int j = 1; j < Maxn; j++) ps[i][j] = (ps[i][j - 1] + dp[i][j]) % Mod;
	}
	
	cout << ps[n][n];
	return 0;
}