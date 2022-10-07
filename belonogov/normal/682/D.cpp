#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 1111;
const long long INF = 1e9 + 19;

int dp[N][N][22];
int n, m, k;
char s[N];
char t[N];

void read() {
	scanf("%d%d%d", &n, &m, &k);
	scanf("%s", s);
	scanf("%s", t);
}

void upd(int & a, int b) {
	a = max(a, b);
}

void solve() {
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++) {
			for (int d = 0; d <= k * 2; d++) {
				if (d % 2 == 0) {
					if (i < n)
						upd(dp[i + 1][j][d], dp[i][j][d]);					
					if (j < m)
						upd(dp[i][j + 1][d], dp[i][j][d]);
					upd(dp[i][j][d + 1], dp[i][j][d]);
				}
				else {
					if (i < n && j < m && s[i] == t[j])
						upd(dp[i + 1][j + 1][d], dp[i][j][d] + 1);
					upd(dp[i][j][d + 1], dp[i][j][d]);
				}
			}
		}
	int answer = 0;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			for (int d = 0; d <= k * 2; d++)
				answer = max(answer, dp[i][j][d]);
	assert(answer >= k);
	printf("%d\n", answer);

}

void stress() {

}

int main(){
#ifdef MY_DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
        }
    }
    else {
        stress();
    }

    return 0;
}