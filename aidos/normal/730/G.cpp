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
const int N = (int) 1e5 + 10;

using namespace std;

int n, k, L[N], R[N];
int s[N], d[N];
pii a[N];

void solve(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &s[i], &d[i]);
	}
	a[k++] = mp(inf + inf, inf + inf);
	for (int i = 1; i <= n; i++) {
		int l, r, pos = 0;
		while (a[pos].s < s[i]) pos++;
		if (s[i] + d[i] - 1 < a[pos].f) {
			a[k++] = mp(s[i], s[i] + d[i] - 1);
			l = s[i];
			r = s[i] + d[i] - 1;
		} else {
			int prev = 0;
			for (int j = 0; j < k; j++) {
				if (prev + d[i] < a[j].f) {
					a[k++] = mp(prev + 1, prev + d[i]);
					l = prev + 1;
					r = prev + d[i];
					break;
				} else {
					prev = a[j].s;
				}
			}
		}
		printf("%d %d\n", l, r);
		sort(a, a + k);
	}
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