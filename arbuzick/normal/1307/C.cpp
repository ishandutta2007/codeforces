#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	vector<int> a(s.size());
	int i;
	for (i = 0; i < s.size(); i++) {
		if (s[i] == 'a')
			a[i] = 1;
		if (s[i] == 'b')
			a[i] = 2;
		if (s[i] == 'c')
			a[i] = 3;
		if (s[i] == 'd')
			a[i] = 4;
		if (s[i] == 'e')
			a[i] = 5;
		if (s[i] == 'f')
			a[i] = 6;
		if (s[i] == 'g')
			a[i] = 7;
		if (s[i] == 'h')
			a[i] = 8;
		if (s[i] == 'i')
			a[i] = 9;
		if (s[i] == 'j')
			a[i] = 10;
		if (s[i] == 'k')
			a[i] = 11;
		if (s[i] == 'l')
			a[i] = 12;
		if (s[i] == 'm')
			a[i] = 13;
		if (s[i] == 'n')
			a[i] = 14;
		if (s[i] == 'o')
			a[i] = 15;
		if (s[i] == 'p')
			a[i] = 16;
		if (s[i] == 'q')
			a[i] = 17;
		if (s[i] == 'r')
			a[i] = 18;
		if (s[i] == 's')
			a[i] = 19;
		if (s[i] == 't')
			a[i] = 20;
		if (s[i] == 'u')
			a[i] = 21;
		if (s[i] == 'v')
			a[i] = 22;
		if (s[i] == 'w')
			a[i] = 23;
		if (s[i] == 'x')
			a[i] = 24;
		if (s[i] == 'y')
			a[i] = 25;
		if (s[i] == 'z')
			a[i] = 26;
	}
	int j;
	long long ans;
	ans = 0;
	long long m;
	m = 0;
	for (i = 1; i <= 26; i++)
		for (j = 1; j <= 26; j++) {
			if (i != j) {
				long long v1, v2, s1, s2;
				v1 = 0;
				v2 = 0;
				s1 = 0;
				s2 = 0;
				long long l;
				for (l = 0; l < s.size(); l++) {
					if (a[l] == i)
						v1 += 1;
					if (a[l] == j)
						v2 += 1;
				}
				long long n;
				n = 0;
				for (l = 0; l < s.size(); l++) {
					if (a[l] == i) {
						n = n + (v2 - s2);
						s1 += 1;
					}if (a[l] == j) {
						s2 += 1;
					}
				}
				m = max(m, v1);
				ans = max(ans, n);
			}
			else {
				long long v1, s1;
				v1 = 0;
				s1 = 0;
				long long l;
				for (l = 0; l < s.size(); l++) {
					if (a[l] == i)
						v1 += 1;
				}
				long long n;
				n = 0;
				for (l = 0; l < s.size(); l++) {
					if (a[l] == i) {
						n = n + (v1 - s1 - 1);
						s1 += 1;
					}
				}
				m = max(m, v1);
				ans = max(ans, n);
			}
		}
	cout << max(ans, m);
	return 0;
}