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
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 1e6; 
const long long INF = 1e9 + 19;

int n, d;
int a[N];
int can[N];

void read() {
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void solve() {
    can[0] = 1; 
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    for (int j = 0; j < n; j++) {
        for (int i = sum; i >= a[j]; i--) {
            can[i] |= can[i - a[j]];
        }
    }
    int answer = 0;
    int pos = 0;
    for (;;) {
        //db2(pos, best);
        int best = -1;
        //db2(pos, best);
        for (int i = 1; i <= d; i++)
            if (can[i + pos])
                best = i + pos;
        if (best == -1) {
            printf("%d %d\n", pos, answer);
            return;
        }
        pos = best;
        answer++;
    }
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
        }
    }
    else {
        stress();
    }

    return 0;
}