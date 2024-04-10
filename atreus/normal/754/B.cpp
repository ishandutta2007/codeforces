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
string s[10];

bool check (char a, char b, char c) {
	int x = 0, y = 0;
	x += (a == 'x') + (b == 'x') + (c == 'x');
	y += (a == '.') + (b == '.') + (c == '.');
	return (y == 1 and x == 2);
}

int main() {
	ios_base::sync_with_stdio(false);
	for (int i = 0; i < 4; i++)
		cin >> s[i];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 2; j++)
			if (check (s[i][j], s[i][j + 1], s[i][j + 2]))
				return cout << "YES" << endl, 0;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 4; j++)
			if (check (s[i][j], s[i + 1][j], s[i + 2][j]))
				return cout << "YES" << endl, 0;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			if (check (s[i][j], s[i + 1][j + 1], s[i + 2][j + 2]))
				return cout << "YES" << endl, 0;
	for (int i = 0; i < 2; i++)
		for (int j = 2; j < 4; j++)
			if (check (s[i][j], s[i + 1][j - 1], s[i + 2][j - 2]))
				return cout << "YES" << endl, 0;
	cout << "NO" << endl;
}