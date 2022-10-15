#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define output freopen("output.txt", "w", stdout);
#define io input; output;
#define ll long long
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define print(ar, n, m)	for(int i = 0; i < n; i++){ for(int j = 0; j < m; j++) cout << ar[i][j]; cout << endl; }
#define ld long double
#define sqr(a) ((a) * (a))
#define endl "\n"
#define mod % 1e9+7
const int MAX = 1e9;
const ld E = 1e-7;

int main() {

	string s;
	cin >> s;
	string st = "CODEFORCES";
	int l = 0, r = 0;
	while(l < st.length() && l < s.length() && st[l] == s[l])
		l++;
	while(r < st.length() && r < s.length() && st[st.length() - 1 - r] == s[s.length() - 1 - r])
		r++;
	cout << (l + r >= st.length() && st != s ? "YES" : "NO");

}