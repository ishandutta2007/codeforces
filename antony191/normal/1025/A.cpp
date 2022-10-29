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
typedef vector<ll> vll1;
typedef vector<vll1> vll2;

const int inf = 1e9;
const ll llinf = 1e18;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define all(v) v.begin(), v.end()

int main() {
	srand(time(NULL));
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> a(26, 0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n; ++i)
		a[s[i] - 'a']++;
	bool k = 0;
	int sum = 0;
	for (int i = 0; i < 26; ++i)
		if (a[i] > 1) {
			k = 1; break;
		}
		else
			if (a[i]) sum++;
	if (k || sum == 1)
		cout << "YES";
	else cout << "NO";
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}