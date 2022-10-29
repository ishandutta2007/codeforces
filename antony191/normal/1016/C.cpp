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

const int inf = 1e9;
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
	vector<int> a1(n), a2(n);
	for (int i = 0; i < n; ++i)
		cin >> a1[i];
	for (int i = 0; i < n; ++i)
		cin >> a2[i];
	vector<ll> suf1(n + 1), suf2(n + 1);
	for (int i = n - 1; i + 1; i--) {
		suf1[i] = suf1[i + 1] + a1[i] * 1ll;
		suf2[i] = suf2[i + 1] + a2[i] * 1ll;
	}
	vector<ll> pref1(n + n), pref2(n + n);
	for (int i = 1; i < n + n; ++i) {
		pref1[i] = pref1[i - 1];
		if (i < n) pref1[i] += a1[i] * 1ll * i;
		else pref1[i] += a2[n + n - i - 1] * 1ll * i;
	}
	for (int i = 1; i < n + n; ++i) {
		pref2[i] = pref2[i - 1];
		if (i < n) pref2[i] += a2[i] * 1ll * i;
		else pref2[i] += a1[n + n - i - 1] * 1ll * i;
	}
	ll ans = 0, mx = 0;
	bool k = 0;
	for (int i = 0; i < n; ++i, k ^= 1) {
		if (i != 0) {
			if (k)
				ans += a2[i - 1] * 1ll * (i + i - 1) + a2[i] * 1ll * (i + i);
			else
				ans += a1[i - 1] * 1ll * (i + i - 1) + a1[i] * 1ll * (i + i);
		}
		if (i == n - 1) {
			ans += (k ? a1[i] * 1ll * (i + i + 1) : a2[i] * 1ll * (i + i + 1));
			mx = max(mx, ans); break;
		}
		if (k) 
			mx = max(mx, ans + (pref2[n + n - i - 1] - pref2[i]) + (suf2[i + 1] + suf1[i]) * 1ll * i);
		else 
			mx = max(mx, ans + (pref1[n + n - i - 1] - pref1[i]) + (suf1[i + 1] + suf2[i]) * 1ll * i);
	}
	cout << mx;
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}