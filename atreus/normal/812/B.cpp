#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <iomanip>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
int last, l[30], r[30], n, m, ans = (1 << 30);
string s[100];

void check (string s) {
	int tmp = 0;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] != s[i - 1])
			tmp += m + 1;
		else
			if (s[i] == '1')
				tmp += 2 * l[i - 1];
			else
				tmp += 2 * r[i - 1];
		tmp ++;
	}
	if (s.back() == '0')
		tmp += r[last];
	else
		tmp += l[last];

	ans = min (ans, tmp);
}

void make_str (string s) {
	if (s.size() == last + 1) {
		check (s);
		return;
	}
	make_str (s + '0');
	make_str (s + '1');
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = n - 1; i >= 0; i--)
		cin >> s[i];

	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s[i][j] == '1') {
				l[i] = m - j + 1;
				break;
			}
		}
		for (int j = m; j >= 0; j--) {
			if (s[i][j] == '1') {
				r[i] = j;
				break;
			}
		}
	}

	for (int i = 0; i < n; i++)
		if (l[i] != 0)
			last = i;
	make_str ("0");
	
	cout << ans << endl;
}