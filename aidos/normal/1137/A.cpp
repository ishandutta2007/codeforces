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
const int mod = (int) 1e9 + 7;
using namespace std;
int n, m;
int a[1010][1010];
int b[1010][1010];
int c[1010][1010];
int d[1111];
int la[1111];
int lb[1111];
void solve(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) scanf("%d", &a[i][j]);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++) d[j] = a[i][j];
		sort(d, d + m);
		int u = unique(d, d + m) - d;
		la[i] = u;
		for(int j = 0; j < m; j++) b[i][j] = lower_bound(d, d + u, a[i][j]) - d;
	}
	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++) d[j] = a[j][i];
		sort(d, d + n);
		int u = unique(d, d + n) - d;
		lb[i] = u;
		for(int j = 0; j < n; j++) c[j][i] = lower_bound(d, d + u, a[j][i]) - d;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			printf("%d ", max(b[i][j], c[i][j]) + max(la[i] - b[i][j], lb[j] - c[i][j]));
		}
		printf("\n");
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