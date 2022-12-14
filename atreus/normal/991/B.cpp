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
const int Maxn = 5e3 + 50;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
int a[120];

int main() {
	ios_base::sync_with_stdio(false);
	long double sum = 0;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	sort (a + 1, a + n + 1);
	long double k = n * (4.5);
	int tmp = 0;
	for (int i = 1; i <= n and sum < k; i++) {
		sum += (5 - a[i]);
		tmp ++;
	}
	cout << tmp << endl;
}