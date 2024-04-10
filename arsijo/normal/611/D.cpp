#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x, y) memset(x, y, sizeof(x))
#define sqr(a) ((a) * (a))
#define endl "\n"
#define def(f) make(#f);
typedef long long ll;
typedef unsigned int ui;
#ifdef LOCAL
typedef double ld;
#else
typedef long double ld;
#endif
typedef pair<ll, ll> ii;
typedef pair<ii, ii> iii;
typedef vector<int>::iterator vit;
typedef set<ii>::iterator siit;
typedef pair<string, string> ss;
const ld E = 1e-10;
const ll MOD = 1e9 + 7;
#define mod % MOD

#ifdef LOCAL
//#define DEBUG
#endif

#ifdef LOCAL
const int MAX = 1e4 + 10;
#else
const int MAX = 2e4 + 10;
#endif
#ifdef DEBUG
#define dbg cout
#else
#define dbg if(0) cout
#endif

int dp[5001][5001], n, sum[5001][5001];
string s;
int keys[4] = {23, 13, 17, 19}, key;
int hash[5001], h[5001];

void build(){
	key = keys[rand() % 4];
	h[0] = 1;
	ll q = 1;
	for(int i = 1; i < n; i++)
		q = h[i] = (q * key) mod;
	q = 0;
	for(int i = 0; i <= n; i++)
		hash[i] = q = (q + (s[i] - '0' + 1) * 1LL * h[i]) mod;
}

int get_hash(int l, int r){
	ll h = hash[r] - (l == 0 ? 0 : hash[l - 1]);
	if(h < 0)
		h += MOD;
	h = (h * ::h[n - r - 1]) mod;
	return h;
}

bool check(int l1, int r1, int l2, int r2){
	while(l1 + 5 < r1){
		int x1 = (l1 + r1) >> 1;
		int x2 = (l2 + r2) >> 1;
		if(get_hash(l1, x1) != get_hash(l2, x2)){
			r1 = x1 + 1;
			r2 = x2 + 1;
		}else{
			l1 = x1;
			l2 = x2;
		}
	}
	for(int i = 0; l1 + i <= r1; i++){
		if(s[l1 + i] != s[l2 + i]){
			if(s[l1 + i] < s[l2 + i]){
				//cout << "OK" << endl;
			}
			return s[l1 + i] < s[l2 + i];
		}
	}
	return false;
}

void solve(int pos){
	dp[pos][pos] = sum[pos][pos] = 1;
	for(int i = 0; i < pos; i++){
		int len1 = i + 1;
		if(i != 0)
			sum[pos][i] = sum[pos][i - 1];
		if(s[pos - i] == '0')
			continue;
		if(pos >= 2 && len1 >= 2){
			dp[pos][i] = sum[pos - len1][len1 - 2];
		}
		if((len1 + len1 <= pos + 1) && check(pos - len1 * 2 + 1, pos - len1, pos - len1 + 1, pos)){
			//cout << "+ " << pos << " " << i << " " << dp[pos - len1][len1 - 1] << " " << len1 << endl;
			dp[pos][i] += dp[pos - len1][len1 - 1];
			if(dp[pos][i] >= MOD)
				dp[pos][i] -= MOD;
		}
		sum[pos][i] += dp[pos][i];
		if(sum[pos][i] >= MOD)
			sum[pos][i] -= MOD;
	}
	if(pos != 0){
		sum[pos][pos] += sum[pos][pos - 1];
		if(sum[pos][pos] >= MOD)
			sum[pos][pos] -= MOD;
	}
	for(int i = pos + 1; i < n; i++)
		sum[pos][i] = sum[pos][i - 1];
}

bool check(string a, string b){
	if(a.size() != b.size())
		return a.size() < b.size();
	for(int i = 0; i < (int) a.size(); i++)
		if(a[i] != b[i])
			return a[i] < b[i];
	return false;
}

int solve_long_2(string last, int pos){
	if(pos == n)
		return 1;
	if(s[pos] == '0')
		return 0;
	string t = "";
	int ans = 0;
	for(int i = pos; i < n; i++){
		t += s[i];
		if(check(last, t))
			ans += solve_long_2(t, i + 1);
	}
	return ans;
}

int solve_long(){
	return solve_long_2("", 0);
}

void rand_test(){
	ofstream cout("input.txt");
	int n = 20;
	srand(time(NULL));
	cout << n << endl;
	for(int i = 0; i < n; i++){
		cout << char(rand() % 10 + '0');
	}
	cout.close();
}

int main() {

	cout.precision(11);
	cout << fixed;
	sync;
#ifdef LOCAL
	//rand_test();
	input;
#else

#endif



	ms(dp, 0);
	cin >> n >> s;
	//cout << s << endl;
	build();
	for(int i = 0; i < n; i++)
		solve(i);
	if(0)
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << sum[n - 1][n - 1] << endl;

}