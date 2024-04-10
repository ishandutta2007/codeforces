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
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 333;
const int INF = 1e9 + 19;

double c[N];
double dp[N][N];
int n;

void read() {
	scanf("%d", &n);
	for (int i = 0; i <= n; i++)
		scanf("%lf", &c[i]);
	for (int it = 0; it < 2 * n; it++) {
		for (int i = 0; i < 2 * n; i++)
			for (int j = 0; j <= n; j++) {
				int v = i - j + (n - j); 
				if (0 <= v && v < n * 2)
					dp[it + 1][v] = max(dp[it + 1][v], dp[it][i] + c[j]);
			}
	}
	double answer = 0;
	for (int i = 0; i < n * 2; i++) {
		double mn = INF;
		for (int k = 1; k <= n * 2; k++)
			mn = min(mn, (dp[n * 2][i] - dp[n * 2 - k][i]) / k);
		answer = max(answer, mn);
	}
	printf("%.17f\n", answer);
}

void solve() {

}

void printAns() {

}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
            printAns();
        }
    }
    else {
        stress();
    }

    return 0;
}