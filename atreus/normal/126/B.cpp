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
const int maxn = 1e6 + 10;
int f[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	int k = 0;
	for (int i = 2; i <= s.size(); i++) {
		while (k != 0 and s[i - 1] != s[k])
			k = f[k];
		if (s[i - 1] == s[k])
			k ++;
		f[i] = k;
	}
	int n = s.size();
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (f[i] == f[n])
			cnt ++;
	if (f[n] > 0 and cnt > 1)
		return cout << s.substr (0, f[n]) << endl, 0;
	f[n] = f[f[n]];
	if (f[n] != 0)
		cout << s.substr (0, f[n]) << endl;
	else
		cout << "Just a legend" << endl;
}