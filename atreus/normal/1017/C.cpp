#include <iostream>
#include <queue>
#include <stack>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <cmath>
#include <unordered_set>
#include <map>
#include <deque>
#include <unordered_map>
#include <fstream>
#include <set>
#include <algorithm>
#include <iomanip>
#define fin cin
#define fout cout
#define F first
#define S second
#define PB push_back
#define PF push_front
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
const int maxn = 4e5 + 10;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
const int block = 317;

int main () {
	ios_base::sync_with_stdio (false);
	int n;
	cin >> n;
	int mnn = n + 1, idx = 1;
	for (int i = 1; i <= n; i++) {
		if (i + (n + i - 1) / i < mnn) {
			mnn = i + (n + i - 1) / i;
			idx = i;
		}
	}
	for (int j = 1; (j - 1) * idx < n; j++) {
		for (int i = min (n, j * idx); i > (j - 1) * idx; i--)
			cout << i << " ";
	}
}