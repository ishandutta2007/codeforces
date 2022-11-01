#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string.h>
#include <string>
#include <cassert>
#include <iomanip>
#include <unordered_set>
#include <unordered_map>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//ifstream cin("in.txt");
	int n, k;
	cin >> n >> k;
	int d = (n - k) / 2;
	string s(n, 'k');
	for (int i = 0; i < n; i++) {
		s[i] = char('0' + (i % (d + 1) == d));
	}
	cout << s;
}