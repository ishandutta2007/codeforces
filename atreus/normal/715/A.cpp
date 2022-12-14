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
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;
typedef unsigned long long ull;
const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;
const int block = 700;

int main() {	
	ios_base::sync_with_stdio (false);
	int n;
	cin >> n;
	ull cur = 2;
	cout << 2 << endl;
	for (ull i = 2; i <= n; i++) {
		cout << i * (i + 1) * (i + 1) - (i - 1) << endl;
		cur = i * (i + 1);
	}
}