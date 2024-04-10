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

#define equal equalll
#define less lesss
const int N = 1e6 + 10;
const int INF = 1e9 + 19;

int n;
int a[N];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

}

void solve() {
    for (int i = 0; i < n; i++) {
        vector < int > tmp;
        if (i > 0) {
            tmp.pb(abs(a[0] - a[i]));
            tmp.pb(abs(a[i - 1] - a[i]));
        }
        if (i + 1 < n) {
            tmp.pb(abs(a[i + 1] - a[i]));
            tmp.pb(abs(a[n - 1] - a[i]));
        }
        sort(tmp.begin(), tmp.end());
        printf("%d %d\n", tmp[0], tmp.back());
    }

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