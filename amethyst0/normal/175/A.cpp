#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

bool valid(const string& s) {
	assert(sz(s) > 0);
	if (s[0] == '0' && sz(s) > 1) {
		return false;
	}
	if (sz(s) > 9) {
		return false;
	}
	ll val = 0;
	for (int i = 0; i < sz(s); ++i) {
		val *= 10;
		val += (s[i] - '0');
	}
	return val <= int(1e6);
}

int convert(const string& s) {
	int ans = 0;
	for (int i = 0; i < sz(s); ++i) {
		ans *= 10;
		ans += (s[i] - '0');
	}
	return ans;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");
	//freopen("input.txt", "r", stdin);
	//ofstream cout("output.txt");
	
	string s;
	cin >> s;

	int ans = -1;

	for (int u = 0; u < sz(s); ++u) {
		for (int v = u + 1; v + 1 < sz(s); ++v) {
			string curr = "";
			for (int i = 0; i <= u; ++i) {
				curr += s[i];
			}
			if (!valid(curr)) {
				continue;
			}
			int sum = convert(curr);
			curr = "";
			for (int i = u + 1; i <= v; ++i) {
				curr += s[i];
			}
			if (!valid(curr)) {
				continue;
			}
			sum += convert(curr);
			curr = "";
			for (int i = v + 1; i < sz(s); ++i) {
				curr += s[i];
			}
			if (!valid(curr)) {
				continue;
			}
			sum += convert(curr);
			ans = max(ans, sum);
		}
	}

	cout << ans << "\n";

}