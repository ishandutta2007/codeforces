#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <deque>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std; using ll = long long; using pii = pair<int, int>; using vi = vector<int>; using ld = long double;

const int mod = (int)1e9 + 7;
const int N = (int)2e5 + 100;

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//ifstream cin("in.txt");
	vi a(6);
	for (int& x : a) {
		cin >> x;
	}
	cout << (a[0] + a[1] + a[2]) * (a[0] + a[1] + a[2]) - a[0] * a[0] - a[2] * a[2] - a[4] * a[4];
}