#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>

#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define ull unsigned long long
#define pll pair < ll, ll >
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it ++)
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()

const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;

using namespace std;
int n, m, a[500], was[500];
string p, s[500];

void solve(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
		was[a[i]] = 1;
		if (p == "") {
			p = s[a[i]];
		} else {
			if (s[a[i]].length() != p.length()) {
				puts("No");
				return;
			}
			int len = p.length();
			for (int j = 0; j < len; j++)
				if (s[a[i]][j] != p[j])
					p[j] = '?';
		}
	}
	for (int i = 1; i <= m; i++)
		for (int j = 0; j < s[a[i]].length(); j++) {
			if (p[j] == '?') continue;
			if (s[a[i]][j] == p[j]) continue;
			puts("No");
			return;
		}
	for (int i = 1; i <= n; i++) if (!was[i]) {
		bool match = true;
		if (s[i].length() == p.length()) {
			for (int j = 0; j < s[i].length(); j++) {
				if (p[j] == '?') continue;
				if (s[i][j] == p[j]) continue;
				match = false;
				break;
			}
		} else
			match = false;
		if (match) {
			puts("No");
			return;
		}
	}
	cout << "Yes\n" << p << "\n";
}

int main () {
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }

    return 0;
}