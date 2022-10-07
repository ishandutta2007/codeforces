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

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define equal equalll
#define less lesss
const int N = 1e6 + 10;
const int INF = 2e9 + 10;

int n;
pair < int, int > b[N];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x, r;
        scanf("%d%d", &x, &r);
        b[i] = mp(x - r, x + r);
    }
}

bool cmp(pair < int, int > a, pair < int, int > b) {
    return a.sc < b.sc;
}

void solve() {
    sort(b, b + n, cmp);
    int last = -INF;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (b[i].fr >= last) {
            last = b[i].sc;
            cnt++;
        }
    }
    cout << cnt << endl;
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
        while (true) {
            read();
            solve();
            printAns();
            return 0;
        }
    }
    else {
        stress();
    }

    return 0;
}