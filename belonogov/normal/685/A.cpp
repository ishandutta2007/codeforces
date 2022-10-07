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
const int N = -1;
const long long INF = 1e9 + 19;

int n, m;

int getC(int n) {
	int res = 0;
	if (n == 0) return 1;
	for (; n > 0; n /= 7, res++);
	return res;
}

bool use[10];
bool flag;

void add(int x, int l) {
	for (int i = 0; i < l; i++, x /= 7) {
		if (use[x % 7])
			flag = 0;
		else {
			use[x % 7] = 1;
		}
	}
}

void read() {
	scanf("%d%d", &n, &m);
	int l1 = getC(n - 1);
   	int l2 = getC(m - 1);
	int answer = 0;
	if (l1 + l2 <= 7) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				flag = 1;		
				memset(use, 0, sizeof(use));
				add(i, l1);
				add(j, l2);
				answer += flag;
			}
	}
	printf("%d\n", answer);

}

void solve() {

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