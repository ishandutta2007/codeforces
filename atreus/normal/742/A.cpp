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
ll a[10];

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	if (n == 0)
		return cout << 1 << endl, 0;
	n %= 4;
	if (n == 1)
		cout << 8 << endl, 0;
	else if (n == 2)
		cout << 4 << endl, 0;
	else if (n == 3)
		cout << 2 << endl, 0;
	else
		cout << 6 << endl, 0;
}