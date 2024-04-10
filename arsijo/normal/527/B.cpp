/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define output freopen("output.txt", "w", stdout);
#define io input; output;
#define ll long long
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define ld double
#define MAX 100001
#define si short int

int main() {

	int n;
	cin >> n;

	string s, t;
	cin >> s >> t;

	int ar[26][26];
	ms(ar);

	int ans = 0;
	for (int i = 0; i < n; i++)
		ans += (s[i] != t[i]);

	for (int i = 0; i < n; i++) {
		if (s[i] == t[i])
			continue;
		int a = s[i] - 'a', b = t[i] - 'a';
		if (ar[b][a] != 0) {
			cout << ans - 2 << "\n" << ar[b][a] << " " << i + 1 << "\n";
			return 0;
		}
		ar[a][b] = i + 1;
	}

	int a[26];
	ms(a);

	for (int i = 0; i < n; i++) {
		if (s[i] == t[i])
			continue;
		if (a[t[i] - 'a'] != 0) {
			cout << ans - 1 << "\n" << a[t[i] - 'a'] << " " << i + 1 << "\n";
			return 0;
		}
		a[s[i] - 'a'] = i + 1;
	}

	ms(a);

	swap(s, t);

	for (int i = 0; i < n; i++) {
		if (s[i] == t[i])
			continue;
		if (a[t[i] - 'a'] != 0) {
			cout << ans - 1 << "\n" << a[t[i] - 'a'] << " " << i + 1 << "\n";
			return 0;
		}
		a[s[i] - 'a'] = i + 1;
	}

	cout << ans << "\n-1 -1\n";

}