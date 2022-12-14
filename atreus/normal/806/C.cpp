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
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
const int block = 316;

ll a[maxn], num[50], n, fre[50], ted[50], mark[maxn];

bool tav[maxn];

bool check (int x) {
	ted[0] = x;
	for (int i = 1; i <= 45; i++) {
		ted[i] = min (ted[i - 1], num[i]);
		fre[i - 1] = ted[i - 1] - ted[i];
	}
	for (int i = 1; i <= n; i++) {
		if (tav[i]) {
			int k = mark[i];
			if (num[k] - ted[k]) {
				ted[k] ++;
				for (int j = k; j <= 45; j++) {
					if (fre[j]) {
						fre[j] --;
						break;
					}
					if (j == 45)
						return 0;
				}
			}
		}
		else {
			int k = mark[i];
			for (int j = k; j <= 45; j++) {
				if (fre[j]) {
					fre[j] --;
					break;
				}
				if (j == 45)
					return 0;
			}
		}
	}
	return 1;
}

int main () {
	ios_base::sync_with_stdio (false);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 0; i <= 45; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[j] == (1ll << i)) {
				num[i] ++;
				tav[j] = 1;
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		ll x = a[i];
		while (x > 1) {
			x /= 2;
			mark[i] ++;
		}
	}

	int l = 0, r = num[0] + 1;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		if (check (mid))
			r = mid;
		else
			l = mid;
	}
	if (l == num[0])
		return cout << -1 << endl, 0;
	for (int i = r; i <= num[0]; i++)
		cout << i << " ";
	cout << endl;
}