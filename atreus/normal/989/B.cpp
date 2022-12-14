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
const int maxn = 2e3 + 50;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
bool cur;

int main() {
	ios_base::sync_with_stdio(false);
	int n, p;
	string s;
	cin >> n >> p >> s;
	for (int i = 0; i < n - p; i++) {
		if (s[i] == '1') {
			if (s[i + p] == '0')
				cur = 1;
			if (s[i + p] == '.') {
				cur = 1;
				s[i + p] = '0';
			}
		}
		if (s[i] == '0') {
			if (s[i + p] == '1')
				cur = 1;
			if (s[i + p] == '.') {
				cur = 1;
				s[i + p] = '1';
			}
		}
		if (s[i] == '.') {
			cur = 1;
			if (s[i + p] == '1')
				s[i] = '0';
			else
				s[i] = '1';
			if (s[i + p] == '.')
				s[i + p] = '0';
		}
	}
	for (int i = 0; i < s.size(); i++)
		if (s[i] == '.')
			s[i] = '1';
	if (cur)
		cout << s << endl;
	else
		cout << "No" << endl;
}