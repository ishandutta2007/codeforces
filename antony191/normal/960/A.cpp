#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <bitset>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <random>
#include <ctime>
#include <utility>

#pragma GCC optimize("O3")
#pragma comment(linker, "/STACK:256000000")
#pragma warning(disable:4996)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi1;
typedef vector<vi1> vi2;
typedef vector<vi2> vi3;
typedef vector<vi3> vi4;
typedef vector<vi4> vi5;

const int inf = 1e9;
const ll llinf = 1e18;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define all(v) v.begin(), v.end()

int main() {
	srand(time(NULL));
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	int sum[3] = { 0, 0, 0 };
	for (int i = 0, k = 0; i < (int)s.size(); ++i) {
		if (k > 2 || k != s[i] - 'a') {
			cout << "NO\n";
			return 0;
		}
		sum[k]++;
		if (i < (int)s.size() - 1 && s[i + 1] != s[i]) {
if (s[i + 1] != s[i] + 1) { cout << "NO"; return 0; }
			k++;
}
	}
	if ((sum[2] == sum[0] || sum[2] == sum[1]) && sum[2])
		cout << "YES\n";
	else
		cout << "NO\n";
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}