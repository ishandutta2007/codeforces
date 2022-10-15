#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define io input; output;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define sqr(a) ((a) * (a))
#define endl "\n"
#define mod % 1000000007
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;
typedef long double ld;
typedef map<int, int>::iterator mit;
const ld E = 1e-4;

#ifdef LOCAL
const ll MAX = 1000;
//#define DEBUG
#else
const ll MAX = 1e5 + 3;
#endif

vector<string> v;

bool bigger(string a, string b){
	for(int i = 0; i < (int) a.size(); i++)
		if(a[i] > b[i])
			return true;
	return false;
}

string solve(int l, int r) {
	if (l == r)
		return v[l];
	int x = (l + r) >> 1;
	string a = solve(l, x), b = solve(x + 1, r);
	if (a > b)
		swap(a, b);
	return a + b;
}

string solve2(int l, int r) {
	if (l == r)
		return v[l];
	int x = (l + r) >> 1;
	string a = solve(l, x), b = solve(x + 1, r);
	if (bigger(a, b))
		swap(a, b);
	return a + b;
}

int main() {

	sync;

#ifdef LOCAL
	input;
#else

#endif

	vector<string> ans;

	for(int i = 0; i < 2; i++) {

		string s;
		cin >> s;

		int n = (int) s.size();
		int g = 1;

		while(n % 2 == 0) {
			g++;
			n >>= 1;
		}

		int e = (int) s.size() / n;

		v.clear();
		v.reserve(e);

		for(int i = 0; i < e; i++) {
			v.push_back(s.substr(i * n, n));
		}

		ans.push_back(solve(0, e - 1));
		//cout << solve(0, e - 1) << endl << solve2(0, e - 1) << endl;

	}

	cout << (ans[0] == ans[1] ? "YES" : "NO");

}