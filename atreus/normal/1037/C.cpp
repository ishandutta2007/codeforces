#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <cassert>
#include <cmath>
#include <vector>
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
typedef long double ld;
typedef pair<int,int> pii;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 100;
const int inf = 1e9;
const int block = 400;

int main () { 
	ios::sync_with_stdio(false);
	int n;
	string s, t;
	cin >> n >> s >> t;
	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		if (s[i] != t[i] and s[i + 1] != t[i + 1] and s[i] != s[i + 1]) {
			ans ++;
			s[i] = t[i];
			s[i + 1] = t[i + 1];
		}
		if (s[i] != t[i])
			ans ++;
	}
	ans += (s[n - 1] != t[n - 1]);
	cout << ans << endl;
}