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
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
const int maxn = 2e5 + 5;

int main () {
	ios_base::sync_with_stdio (false);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int n;
		string s;
		cin >> n >> s;
		bool cur = 1;
		for (int j = 0; j < n; j++) {
			int x = abs (int(s[j]) - int(s[n - j - 1]));
			if (x == 0 or x == 2) {
				continue;
			}
			else {
				cur = 0;
				break;
			}
		}
		if (cur)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}