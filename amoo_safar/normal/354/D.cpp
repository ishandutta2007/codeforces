// har ki ro didi goft mikhad beshe meslemon !
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
const int N = 1e5 + 10;
const ll Inf = 2242545357980376863LL;
const int Sqrt = 800;

vector<int> V[N];

int dp[2][Sqrt];

int f(int x){
	if(x == 0) return 0;
	return 2 + (x * (x + 1) / 2);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	int r, c;
	for(int i = 0; i < k; i++){
		cin >> r >> c;
		r = n + 1 - r;
		// cerr << "! " << r << ' ' << c << '\n';
		V[c].pb(r);
	}
	memset(dp, 31, sizeof dp);
	dp[0][0] = 0;
	int mn = 0;
	for(int i = 1; i <= n; i++){
		// debug(i);
		// debug(mn);
		// debug(f(i));
		int ii = i & 1;
		memset(dp[ii], 31, sizeof dp[ii]);
		int cnt = 0;
		sort(all(V[i]));
		
		for(int j = Sqrt - 2; j >= 0; j--){
			while(!V[i].empty() && V[i].back() > j){
				cnt ++;
				V[i].pop_back();
			}
			// if(i == 1 && j == 1) debug(cnt);
			dp[ii][j] = min(mn + f(j), dp[ii ^ 1][j + 1]) + 3 * cnt;
		}
		// cerr << "# ";
		// for(int j = 0; j <= n; j++) cerr << dp[ii][j] << ' ';
		// cerr << '\n';
		mn = *min_element(dp[ii], dp[ii] + Sqrt);
	}
	cout << mn << '\n';

	return 0;
}