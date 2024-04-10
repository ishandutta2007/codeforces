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
	int n, k;
	string s;
	cin >> n >> k;
	cin >> s;
	vector<bool> used(n, 0);
	vector<int> stack, pos(n, -1);
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(')
			stack.push_back(i);
		else {
			pos[stack.back()] = i;
			stack.pop_back();
		}
	}
	int l = 0;
	while (k < n) {
		while (s[l] == ')') l++;
		used[l] = used[pos[l]] = 1;
		l++; k += 2;
	}
	for (int i = 0; i < n; ++i)
		if (!used[i])
			cout << s[i];
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}