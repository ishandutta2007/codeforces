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
const int N = 4444;
const int INF = 1e9 + 19;

struct chil {
    long long id, v, d, p;
};

int n;
chil a[N];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld%lld", &a[i].v, &a[i].d, &a[i].p);
        a[i].id = i;
    }

}

void solve() {
    vector < int > answer;
    for (; n > 0; ) {
        int x = a[0].v;
        for (int i = 1; i < n && x > 0; i++, x--) {
            a[i].p -= x;
        }
        answer.pb(a[0].id);
        a[0].p = -1;
        for (int i = 1; i < n; i++) {
            if (a[i].p < 0) {
                for (int j = i + 1; j < n; j++)
                    a[j].p -= a[i].d;
            }
        }
        int cur = 0;
        for (int i = 0; i < n; i++)
            if (a[i].p >= 0)
                a[cur++] = a[i];
        n = cur;
    }
    printf("%d\n", (int)answer.size());
    for (auto x: answer)
        printf("%d ", x + 1);
    puts("");

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