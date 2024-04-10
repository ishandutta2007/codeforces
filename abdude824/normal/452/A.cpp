#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <bitset>
#include <numeric>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

string s[8] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

bool ff(string s, string t) {
	for (int i = 0; i < (int)t.length(); i ++) 
		if (t[i] != '.' && t[i] != s[i]) return 0;
	return 1;
}

int main()
{
	int l; string t;
	cin >> l >> t;
	for (int i = 0; i < 8; i ++) 
		if ((int)s[i].length() == l)
			if (ff(s[i],t))
				cout << s[i] << endl;
	return 0;
}