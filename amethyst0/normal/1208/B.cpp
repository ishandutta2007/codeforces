#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <cstring>
#include <memory.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

const int maxn = 2010;
int v[maxn];

int cnt[maxn];

int main() {
	int n;

	cin >> n;

	vector <int> x;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		x.push_back(v[i]);
	}

	sort(x.begin(), x.end());
	x.resize(unique(x.begin(), x.end()) - x.begin());

	for (int i = 0; i < n; i++) {
		v[i] = lower_bound(x.begin(), x.end(), v[i]) - x.begin();
	}

	if ((int)x.size() == n) {
		cout << 0 << endl;
		return 0;
	}

	int ans = n;

	for (int i = 0; i < n; i++) {
		memset(cnt, 0, sizeof cnt);

		bool fl = true;

		for (int j = 0; j < i; j++) {
			cnt[v[j]]++;
			if (cnt[v[j]] > 1) {
				fl = false;
			}
		}

		for (int j = n - 1; j >= i; j--) {
			if (fl) {
				ans = min(ans, j - i + 1);
			}

			cnt[v[j]]++;
			if (cnt[v[j]] > 1) {
				fl = false;
			}
		}
	}

	cout << ans << endl;

	//system("pause");
	return 0;
}