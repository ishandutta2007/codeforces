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
const int N = 500 + 2;
const long long INF = 1e9 + 19;

bool dp[N][N][N];
int c[N];
int n, k;
bool answer[N];

void read() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &c[i]);
}

void solve() {
	dp[0][0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++)
			for (int x = 0; x + j <= k; x++) {
				if (dp[i][j][x]) {
					dp[i + 1][j][x] = 1;
					if (j + x + c[i] <= k) {
						dp[i + 1][j + c[i]][x] = 1;
						dp[i + 1][j][x + c[i]] = 1;
					}
				}	
			}
	}
	for (int j = 0; j <= k; j++)
		if (dp[n][j][k - j])
			answer[j] = 1;

	vector < int > ans;
	for (int i = 0; i <= k; i++)
		if (answer[i])
			ans.pb(i);

	printf("%d\n", (int)ans.size());
	for (auto x: ans)
		printf("%d ", x);
	puts("");

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