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
int p[N];
bool use[N];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
        p[i]--;
    }
}

void solve() {
    vector < vector < int > > cir;
    for (int i = 0; i < n; i++) {
        if (!use[i]) {
            vector < int > tmp;
            int v = i;
            for (; !use[v]; v = p[v]) {
                use[v] = 1;
                tmp.pb(v);
            }
            cir.pb(tmp);
        }
    }
    int sum = 0;
    for (auto &g: cir)
        sum += g.size();
    assert(sum == n);
    for (auto & g: cir) {
        assert(!g.empty());
        if ((int)g.size() == 1) {
            int o = g[0];
            puts("YES");
            for (int i = 0; i < n; i++)
                if (i != o) {
                    printf("%d %d\n", i + 1, o + 1);
                }
            return;
        }
    }
    for (auto & g: cir) {
        if ((int)g.size() == 2) {
            bool flag = 1;
            for (auto & e: cir)
                flag &= (int)e.size() % 2 == 0;
            if (flag) {
                puts("YES");
                printf("%d %d\n", g[0] + 1, g[1] + 1);  
                for (auto & e: cir) {
                    if (e[0] == g[0]) continue;
                    for (int i = 0; i < (int)e.size(); i++)
                        printf("%d %d\n", e[i] + 1, g[i % 2] + 1);
                }
                return;
            }
            else {
                puts("NO");
                return;
            }
        }
    }

    puts("NO");




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