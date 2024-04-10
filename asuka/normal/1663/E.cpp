#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;

string s[111];

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) cin >> s[i];

	string ans = "theseus";

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			rep(di, 0, 1) rep(dj, 0, 1) {
				if (di + dj == 0) continue;

				string cur;

				rep(k, 0, 6) {
					if (i + k * di >= n || j + k * dj >= n) break;

					cur += s[i + k * di][j + k * dj];
				}

				if (cur == ans) {
					puts("YES");
					return 0;
				}

			}
		}

	puts("NO");
	return 0;
}