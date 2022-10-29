#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <bitset>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <random>
#include <ctime>
#include <utility>

#pragma GCC optimize("O3")
#pragma comment(linker, "/STACK:256000000")
#pragma warning(disable:4996)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi1;
typedef vector<vi1> vi2;
typedef vector<ll> vll1;
typedef vector<vll1> vll2;

const int inf = 1e9, mod = 1000'000'007;
const ll llinf = 1e18;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define all(v) v.begin(), v.end()

int main() {
	srand(time(NULL));
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<pair<bool, int>> por(n);
	vector<int> z;
	for (int i = 0; i < n; ++i) {
		string s;
		int tmp;
		cin >> s >> tmp;
		if (s == "ADD") {
			por[i].first = 0;
		}
		else {
			por[i].first = 1;
		}
		por[i].second = tmp;
	}
	vector<int> nex(n, -1);
	int r = -1;
	for (int i = n - 1; i >= 0; --i) {
		if (por[i].first)
			r = i;
		nex[i] = r;
	}
	int i;
	int l = 0; r = inf;
	set<int> q;
	ll ans = 1;
	for (i = 0; i < n && nex[i] != -1 && ans; i = nex[i] + 1) {
		if (l > por[nex[i]].second || r < por[nex[i]].second) {
			ans = 0;
			break;
		}
		if (l != por[nex[i]].second && r != por[nex[i]].second) {
			ans *= 2;
			if (ans >= mod) ans -= mod;
		}
		for (int j = i; j < nex[i]; ++j)
			q.insert(por[j].second);
		q.erase(por[nex[i]].second);
		auto j = q.lower_bound(por[nex[i]].second);
		if (j == q.end()) r = inf;
		else r = *j;
		if (j == q.begin()) l = 0;	
		else {
			j--;
			l = *j;
		}
	}
	if (!ans) cout << 0;
	else {
		int tmp = 0;
		for (int j = i; j < n; ++j)
			if (por[j].second > l && por[j].second < r) tmp++;
		ans = ans * 1ll * (tmp + 1) % mod;
		ans = (ans + mod) % mod;
		cout << ans;
	}
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}