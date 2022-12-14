#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <cassert>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
#include <set>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 50;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
ll l[maxn], r[maxn], a[maxn], b[maxn];

void prnt (int L, int R) {
	ll mxx = 0;
	if (L == R)
		return;
	for (int i = L; i <= R; i++)
		mxx = max (mxx, a[i]);
	bool cur = 0;
	for (int i = L; i < R; i++) {
		if (a[i] == mxx and a[i + 1] < mxx) {
			for (int j = i + 1; j <= R; j++)
				cout << i << " R \n";
			int tmp = i;
			for (int j = i - 1; j >= L; j--)
				cout << tmp -- << " L \n";
			cur = 1;
			break;
		}
	}
	if (!cur) {
		for (int i = R; i > L; i--) {
			if (a[i] == mxx and a[i - 1] < mxx) {
				int tmp = i;
				for (int j = i - 1; j >= L; j--)
					cout << tmp -- << " L \n";
				for (int j = i + 1; j <= R; j++)
					cout << tmp << " R \n";
			}
		}
	}
}

bool check (int L, int R) {
	ll mxx = 0;
	for (int i = L; i <= R; i++)
		mxx = max (mxx, a[i]);
	for (int i = L; i <= R; i++)
		if (a[i] < mxx)
			return 1;
	return (R == L);
}

int main() {
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cin >> k;
	for (int i = 1; i <= k; i++)
		cin >> b[i];
	ll tmp = 1, sum = 0, last = 1;
	for (int i = 1; i <= n; i++) {
		if (tmp > k)
			return cout << "NO" << endl, 0;
		sum += a[i];
		if (sum > b[tmp])
			return cout << "NO" << endl, 0;
		else if (sum == b[tmp]) {
			sum = 0;
			if (!check (last, i))
				return cout << "NO" << endl, 0;
			l[tmp] = last;
			r[tmp] = i;
			last = i + 1;
			tmp ++;
			continue;
		}
		if (i == n)
			return cout << "NO" << endl, 0;
	}
	if (tmp <= k)
		return cout << "NO" << endl, 0;
	cout << "YES" << endl;
	for (int i = tmp - 1; i >= 1; i--)
		prnt (l[i], r[i]);
}