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
const int maxn = (int) 3e5 + 10;
const int mod = (int) 1e9 + 7;
using namespace std;
int m, n;
int p[maxn];
int l[maxn];
ll s[maxn];
int mx[maxn];
void solve() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++) {
		scanf("%d", &l[i]);
	}
	for(int i = m; i >= 1; i--) {
		mx[i] = max(l[i], mx[i+1]+1);
	}
	
	int j = 1;
	int h = 0;
	for(int i = 1; i <= m; i++) {
		while(j <= h && j + mx[i] <= n) {
			j++;
		}
		if(j + l[i] - 1 > n) {
			cout << -1 << "\n";
			return;
		}
		p[i] = j;
		h = max(h, j + l[i] - 1);
		j++;
	}

	if(h != n) {
		cout << -1 << "\n";
		return;
	}
	for(int i = 1; i <= m; i++) {
		printf("%d ", p[i]);
	}
}

int main () {
    int t=1;
    //scanf("%d", &t);
    for(int i=1; i <= t; i++){
      //printf("Case #%d\n", i);
      solve();
    }
    
    return 0;
}