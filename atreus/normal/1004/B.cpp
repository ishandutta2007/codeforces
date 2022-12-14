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
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
bool mark1[maxn], mark2[maxn];
int par[maxn], a[maxn];

int main() {	
	ios_base::sync_with_stdio (false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int l, r;
		cin >> l >> r;
	}
	for (int i = 1; i <= n; i++)
		cout << i % 2;
	cout << endl;
}