#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <iomanip>
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
const int maxn = 200 + 50;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
int a[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	n *= 2;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	ll cnt = 0;
	for (int i = 1; i <= n; i += 2) {
		for (int j = i + 1; j <= n; j++) {
			if (a[j] == a[i]) {
				for (int k = j - 1; k >= i + 1; k --) {
					cnt ++;
					int tmp = a[k];
					a[k] = a[k + 1];
					a[k + 1] = tmp;
				}
			}
		}
	}
	cout << cnt << endl;
}