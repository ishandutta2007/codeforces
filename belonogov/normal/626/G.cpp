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
const int N = 2e5 + 10;
const long long INF = 1e9 + 19;
const double eps = 1e-9;

struct Fraq {
    long long p, q;
    Fraq(long long p, long long q): p(p), q(q) { }
    bool operator < (const Fraq & A) const {
         __float128(p) * A.q;
        //long right = (A.p) * q;
        //return left < right;
        return p * A.q < A.p * q;
    }
};

int n, t, q;
int p[N];
int x[N];
int k[N];
pair < int, int > query[N];

void read() {
    scanf("%d%d%d", &n, &t, &q);
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &x[i]);
    for (int i = 0; i < q; i++)
        scanf("%d%d", &query[i].fr, &query[i].sc);
}

Fraq costAdd(int id) {
    if (x[id] < k[id] + 1) assert(false);
    return Fraq(p[id] * 1ll * x[id], (x[id] + k[id]) * 1ll * (x[id] + k[id] + 1));
}

Fraq costRem(int id) {
    assert(k[id] > 0);
    return Fraq(p[id] * 1ll * x[id], (x[id] + k[id]) * 1ll * (x[id] + k[id] - 1));
}

double totalCost(int id) {
    return p[id] * 1.0 * k[id] / (k[id] + x[id]);
}
set < pair < Fraq, int > > canAdd;
set < pair < Fraq, int > > canRem;

void del(int id) {
    if (k[id] + 1 <= x[id])  {
        int sz = canAdd.size();
        canAdd.erase(mp(costAdd(id), id));
        assert(sz - 1 == (int)canAdd.size());
    }
    if (k[id] > 0) {
        int sz = canRem.size();
        canRem.erase(mp(costRem(id), id));
        assert(sz - 1 == (int)canRem.size());
    }
}

void add(int id) {
    if (k[id] + 1 <= x[id])  {
        int sz = canAdd.size();
        canAdd.insert(mp(costAdd(id), id));
        assert(sz + 1 == (int)canAdd.size());
    }
    if (k[id] > 0) {
        int sz = canRem.size();
        canRem.insert(mp(costRem(id), id));
        assert(sz + 1 == (int)canRem.size());
    }
}


void solve() {
    int free = t;
    for (int i = 0; i < n; i++) {
        canAdd.insert(mp(costAdd(i), i));
    }
    
    double answer = 0;
    for (int tt = 0; tt < q; tt++) {
        int id = query[tt].sc - 1;

        del(id);

        answer -= totalCost(id);             
        x[id] += (query[tt].fr == 1)? 1: -1;

        if (k[id] > x[id]) {
            k[id]--;
            free++;
        }
        assert(k[id] <= x[id]);
        answer += totalCost(id);

        add(id);

        for (; free > 0 && !canAdd.empty(); ) {
            int id = canAdd.rbegin()->sc;

            del(id);

            answer -= totalCost(id);
            k[id]++;
            free--;
            assert(k[id] <= x[id]);
            answer += totalCost(id);

            add(id);
        }

        int cc = 0;
        for (;!canAdd.empty() && !canRem.empty();) {
            if (canRem.begin()->fr < canAdd.rbegin()->fr) {
                cc++;
                int v = canRem.begin()->sc;
                int u = canAdd.rbegin()->sc;
                answer -= totalCost(v);
                answer -= totalCost(u);

                del(v);
                del(u);

                k[v]--;
                assert(k[v] >= 0);
                k[u]++;
                assert(k[u] <= x[u]);

                answer += totalCost(v);
                answer += totalCost(u);

                add(v);
                add(u);
            }
            else
                break;
        }
        //assert(cc < 20);

        printf("%.17f\n", answer);
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