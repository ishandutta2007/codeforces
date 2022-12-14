#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <iomanip>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 1e3 + 10;
const int mod = 1e9 + 7;
int n, a[10], num[10], c[maxn], loc[10][maxn], par[maxn][10], k, ans = 0;

void get (string s) {
	int now = 1, idx = 0, ted = 0;
	for (int i = 1; i <= 8; i++) {
		int nm = par[idx][a[i]];
		ted += (int)(s[i - 1] - '0');
		if (k + (int)(s[i - 1] - '0') > 0)
			idx = loc[a[i]][nm + k + (int)(s[i - 1] - '0')];
		if (idx == 0)
			return;
	}
	ans = max (ans, ted + 8 * k);
}

void make_str (string s) {
	if (s.size() == 8) {
		get (s);
		return;
	}
	make_str (s + '0');
	make_str (s + '1');
}

bool check (int x) {
	int now = 1, idx = 0;
	for (int i = 1; i <= 8; i++) {
		int nm = par[idx][a[i]];
		idx = loc[a[i]][nm + x];
		if (idx == 0)
			return 0;
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		loc[c[i]][++ num[c[i]]] = i;
		for (int j = 1; j <= 8; j++)
			par[i][j] = par[i - 1][j] + (c[i] == j);
	}
	
	for (int i = 1; i <= 8; i++)
		a[i] = i;

	int mxx = 0;
	do {
		int l = 0, r = n;
		while (r - l > 1) {
			int mid = (l + r) / 2;
			if (check (mid))
				l = mid;
			else
				r = mid;
		}
		k = l;
		if (k < mxx)
			continue;
		mxx = k;
		make_str ("");
	} while (next_permutation (a + 1, a + 8 + 1));
	
	cout << ans << endl;
}