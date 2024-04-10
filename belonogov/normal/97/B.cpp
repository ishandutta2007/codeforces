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
const int N = 2e5 + 10;
const int INF = 1e9 + 19;

int n;
pair < int, int > a[N];
int cur;


void read() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &a[i].fr, &a[i].sc);
}

void calc(int l, int r) {
	if (r - l <= 1) return;
	int len = r - l;
	vector < int > yy;
	for (int i = l; i < r; i++)
		yy.pb(a[i].sc);

	///db(yy.size());

	for (int i = l; i < r; ) {
		int j = i;
		for (; i < r && a[j].fr == a[i].fr; i++);
			
		int cl = j - l;
		int cr = r - i;
		//db2(cl, cr);
		if (cl * 2 <= len && cr * 2 <= len) {
			for (auto y: yy) {
				a[cur++] = mp(a[j].fr, y);				
			}
			calc(l, j);
			calc(i, r);
			return;
		}
	}

}

void solve() {
	cur = n;
	sort(a, a + n);

	calc(0, n);



	sort(a, a + cur);
	cur = unique(a, a + cur) - a;

	printf("%d\n", cur);
	for (int i = 0; i < cur; i++)
		printf("%d %d\n", a[i].fr, a[i].sc);

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