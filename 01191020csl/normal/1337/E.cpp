#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
char s[3001], t[3001];
int f[3001][3001];
int main() {
	cin >> s + 1 >> t + 1;
	int ls = strlen(s + 1), lt = strlen(t + 1);
	for (int i = 1; i <= lt; i++)
		if (t[i] == s[1]) f[i][i] = 2;
	for (int i = lt + 1; i <= ls; i++) f[i][i] = 2;
	for (int j = 2; j <= ls; j++)
		for (int i = 1; i + j - 1 <= ls; i++) {
			int &p = f[i][i+j-1];
			if (i > lt || s[j] == t[i]) p = (p + f[i+1][i+j-1]) % mod;
			if (i + j - 1 > lt || s[j] == t[i+j-1]) p = (p + f[i][i+j-2]) % mod;
		}
	int ans = 0;
	for (int i = lt; i <= ls; i++) ans = (ans + f[1][i]) % mod;
	cout << ans << endl;
}