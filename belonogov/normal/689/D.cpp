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
const int N = 2e5 + 10;
const long long INF = 1e9 + 19;
const int T = 20;

int n;
int a[N];
int b[N];
int mx[T][N];
int mn[T][N];
int deg[N];

void read() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);

}

int f(int l, int r) {
	int d = deg[r - l];
	int r1 = min(mn[d][l], mn[d][r - (1 << d)]);
	int r2 = max(mx[d][l], mx[d][r - (1 << d)]);
	return r1 - r2;
}

void solve() {
	long long answer = 0;
	deg[1] = 0;		
	for (int i = 2; i <= n; i++)
		deg[i] = deg[i / 2] + 1;
	for (int i = 0; i < n; i++) {
		mx[0][i] = a[i];
		mn[0][i] = b[i];
	}

	for (int j = 1; j < T; j++)
		for (int i = 0; i + (1 << j) <= n; i++) {
			mn[j][i] = min(mn[j - 1][i], mn[j - 1][i + (1 << (j - 1))]);
			mx[j][i] = max(mx[j - 1][i], mx[j - 1][i + (1 << (j - 1))]);
		}

	int curL = -1;
	int curR = 0;
	//for (int i = 0; i < n; i++)
		//cerr << a[i] << " ";
	//cerr << endl;
	//for (int i = 0; i < n; i++)
		//cerr << b[i] << " ";
	//cerr << endl;
	//for (int i = 0; i <= n; i++)
		//for (int j = i + 1; j <= n; j++)
			//db3(i, j, f(i, j));

		


	for (int i = 0; i < n; i++) {
		for (;curR <= i && f(curR, i + 1) <= 0; curR++);
		for (;curL < i && f(curL + 1, i + 1) < 0; curL++);
		//db3(curL, curR, i);
		if (curL < curR)
			answer += curR - curL - 1;
	}

	printf("%lld\n", answer);
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