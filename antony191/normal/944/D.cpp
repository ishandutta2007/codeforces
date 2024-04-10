#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <bitset>


using namespace std;

struct pare {
	char a, b;
	int c;
};

bool operator <(const pare & a, const pare & b) {
	if (a.a != b.a)
		return a.a < b.a;
	if (a.b != b.b)
		return a.b < b.b;
	return a.c < b.c;
}
int main() {
	string s;
	cin >> s;
	int n = s.size();
	vector<vector<pare>> a(n, vector<pare>(n));
	for (int len = 0; len < n; ++len) {
		for (int i = 0; i < n; ++i) {
			int j = (i + len) % n;
			a[len][i] = { s[i], s[j], i };
		}
	}
	vector<int> b(26, 0);
	for (int len = 0; len < n; ++len) {
		vector<int> k(255);
		vector<vector<int>> k1(255, vector<int>(255, 0));
		for (int i = 0; i < n; ++i) {
			k[a[len][i].a]++;
			k1[a[len][i].a][a[len][i].b]++;
		}
		for (int i = 0; i < 26; ++i) {
			int ss = 0;
			for (int j = 0; j < 26; ++j)
				if (k1[i + 'a'][j + 'a'] == 1)
					++ss;
			b[i] = max(b[i], ss);
		}
	}
	long double sum = 0;
	for (int i = 0; i < 26; ++i)
		sum += b[i];
	cout << (double)sum / (double)n;
	return 0;
}