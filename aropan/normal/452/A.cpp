#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
string s;

bool check(string c)
{
	if (s.size() != c.size()) return 0;
	for (size_t i = 0; i < s.size(); ++i) {
		if (s[i] != '.' && s[i] != c[i]) {
			return 0;
		}
	}
	cout << c << endl;
	return 1;
}


int main()
{
	#ifdef MJUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	int n;
	cin >> n;
	cin >> s;
	check("vaporeon") ||
	check("jolteon") ||
	check("flareon") ||
	check("espeon") ||
	check("umbreon") ||
	check("leafeon") ||
	check("glaceon") ||
	check("sylveon");

	return 0;
}