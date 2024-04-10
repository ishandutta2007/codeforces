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
const int N = 1e5 + 10;
const int INF = 1e9 + 19;

int n;
int a[N];
int p[N];
int g[N];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void solve() {
    for (int i = 0; i < n; i++) {
        p[i + 1] = p[i] + (a[i] == 2);
        g[i + 1] = g[i] + (a[i] == 1);
    } 
    vector < pair < int, int > > data;
    for (int t = 1; t <= n; t++) {
        int r = 0; 
        int cntG = 0;
        int cntP = 0;
        bool flag = 1;
        for (;;) {
            int r1 = lower_bound(g, g + n + 1, g[r] + t) - g;
            int r2 = lower_bound(p, p + n + 1, p[r] + t) - p;
            r = min(r1, r2);
            if (r1 == n + 1 && r2 == n + 1) {
                flag = 0; 
                break;
            }
            assert(r1 != r2);
            cntG += r1 == r;
            cntP += r2 == r;
            if (r == n) {
                if (r1 == r) {
                    flag &= cntG > cntP;
                }    
                if (r2 == r) {
                    flag &= cntP > cntG;
                }
                break;
            }
        }
        if (flag) 
            data.pb(mp(max(cntG, cntP), t));

    }
    sort(all(data));
    cout << data.size() << "\n";
    for (auto x: data)
        printf("%d %d\n", x.fr, x.sc);


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