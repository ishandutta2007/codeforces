#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <map>
#include <cmath>

#define mp make_pair
#define pb push_back
#define fi(n) for(int i = 0; i < (int)n; ++i)
#define fie(n) for(int i = 1; i <= (int)n; ++i)
#define fir(l, r) for(int i = (int)l; i <= (int)r; ++i)
#define fj(n) for(int j = 0; j < (int)n; ++j)
#define fje(n) for(int j = 1; j <= (int)n; ++j)
#define fjr(l, r) for(int j = (int)l; j <= (int)r; ++j)
#define fv(i, n) for(int i = 0; i < (int)n; ++i)
#define fve(i, n) for(int i = 1; i <= (int)n; ++i)
#define fvr(i, l, r) for(int i = (int)l; i <= (int)r; ++i)
#define sqr(x) ((x) * (x))
#define rn(n) int n; cin >> n
//#define int ll

#pragma warning (disable : 4996)
//#pragma comment (linker, "STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<char> vc;

const ld EPS = 1e-8;
const int N = (int)1e5 + 10;
const int INF = (int)1e9 + 10;
const int MOD = (int)1e9 + 7;

bool check(string& p, string& q){
	string s = p + "#" + q;
	int n = s.length();
	vi z(n);
	int r = 0, j = 0;
	fie(n - 1){
		if (i <= r)
			z[i] = min(z[i - j], r - i + 1);
		while(i + z[i] < n && s[z[i]] == s[i + z[i]]){
			++z[i];
		}
		if (i + z[i] - 1 > r){
			r = i + z[i] - 1;
			j = i;
		}
	}
	fir(p.length(), n - 1){
		if (z[i] == p.length())
			return 1;
	}
	return 0;
}

signed main(){
#ifdef LOCALFILE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, a, b;
	cin >> n >> a >> b;
	string s;
	cin >> s;
	vi dp(n + 1);
	dp[1] = a;
	fir(2, n){
		int l = 0, r = i;
		while (r - l > 1){
			int m = (l + r) / 2;
			string s1 = s.substr(0, i - m);
			string s2 = s.substr(i - m, m);
			if (check(s2, s1))
				l = m;
			else
				r = m;
		}
		if (l != 0)
			dp[i] = min(dp[i - 1] + a, dp[i - l] + b);
		else
			dp[i] = dp[i - 1] + a;
	}
	cout << dp[n];

	return 0;
}