/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;
//#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define files(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define ll long long
#define x first
#define y second
#define sync ios_base::sync_with_stdio(0); cin.tie(0);
#define ms(x) memset(x, 0, sizeof(x));

int getInt(char c) {
	int g = c - 'a';
	if (g >= 0 && g < 26)
		return g;
	return (c - 'A' + 26);
}

int anotherInt(char c) {
	int g = c - 'a';
	if (g >= 0 && g < 26)
		return (g + 26);
	return (c - 'A');
}

int main() {

	string s, t;
	cin >> s >> t;
	int a[52];
	ms(a);

	for (int i = 0; i < t.length(); i++) {
		a[getInt(t[i])]++;
	}

	int a1 = 0, a2 = 0;

	string left = "";

	for (int i = 0; i < s.length(); i++) {
		if (a[getInt(s[i])]) {
			a[getInt(s[i])]--;
			a1++;
		} else {
			left += s[i];
		}
	}

	cout << a1 << " ";

	for (int i = 0; i < left.length(); i++) {
		if (a[anotherInt(left[i])]) {
			a[anotherInt(left[i])]--;
			a2++;
		}
	}

	cout << a2;

}