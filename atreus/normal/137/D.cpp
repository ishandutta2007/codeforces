#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
#include <iomanip>
#define F first
#define S second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 500 + 10;
const int mod = 12713;
int dp[maxn][maxn], c[maxn][maxn], par[maxn][maxn];
string b, s;

void fix (int l, string a) {
	for (int i = 0; i < a.size(); i++)
		if (a[i] != a[a.size() - i - 1])
			b[l + i] = b[l + a.size() - i - 1];
}

int find (string a) {
	int cnt = 0;
	for (int i = 0; i < a.size(); i++)
		cnt += (a[i] != a[a.size() - i - 1]);
	return cnt / 2;
}

string lower (string a) {
	string k;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] - 'A' < 26) 
			a[i] = (char)(a[i] - 'A' + 'a');
		k += a[i];
	}
	return k;
}

int main () {
	ios_base::sync_with_stdio (false);
	int k;
	cin >> b >> k;
	int n = b.size();
	s = b;
	b = " " + b;
	s = " " + s;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			c[i][j] = find (s.substr (i, j - i + 1));
		}
	}
	memset (dp, 63, sizeof dp);
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			for (int l = i; l >= 1; l--) {
				int tmp = dp[i][j];
				dp[i][j] = min (dp[i][j], c[l][i] + dp[l - 1][j - 1]);
				if (tmp != dp[i][j])
					par[i][j] = l - 1;
			}
		}
	}
	int idx = 0;
	for (int i = 1; i <= k; i++) {
		if (dp[n][i] < dp[n][idx])
			idx = i;
	}

	cout << dp[n][idx] << endl;
	int x = n;
	stack <int> a;
	while (x > 0) {
		a.push (x);
		x = par[x][idx];
		idx --;
	}
	a.push (0);
	
	while (a.top() != n) {
		int u = a.top();
		a.pop();
		fix (u + 1, s.substr (u + 1, a.top() - u));
		cout << b.substr (u + 1, a.top() - u);
		if (a.top() != n)
			cout << "+";
	}
	cout << endl;
}