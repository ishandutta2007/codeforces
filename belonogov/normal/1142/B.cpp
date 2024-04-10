#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <math.h>
#include <string>
#include <set>
#include <iomanip>
#include <bitset>
#include <random>
#include <complex>
#include <random>
#include <cassert>
#include <unordered_map>
#include <unordered_set>

#define F first
#define S second
#define pb push_back
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define pw(x) (1LL<<(x))

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << " = "; for (auto xxxx: a) cerr << xxxx << " "; cerr << endl

using namespace std;

typedef long long ll;
typedef double dbl;
const int INF = 1.01e9;




int main() {
#define TASK "A"
#ifdef HOME
    assert(freopen(TASK".in", "r", stdin));
#endif
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    vector<int> perm(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &perm[i]) ;
        perm[i]--;
    }
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
        a[i]--;
    }
    vector<pair<int,int>> query(q);
    for (int i = 0; i < q; i++) {
        scanf("%d%d", &query[i].F, &query[i].S);
        query[i].F--;
    }

    vector<int> rev(n);
    for (int i = 0; i < n; i++) {
        rev[perm[i]] = i;
    }

    for (auto& x: a) {
        x = rev[x];
    }

    vector<int> answer(q, -1);

    const int LOG = 20;
    vector<vector<int>> jump(m, vector<int> (LOG, -1));
    vector<int> last(n, - 1);
    for (int i = 0; i < m; i++) {
        last[a[i]] = i;
        jump[i][0] = last[(a[i] - 1 + n) % n];
//        db2(i, jump[i][0]);
    }

    for (int i = 1; i < LOG; i++) {
        for (int j = 0; j < m; j++) {
            if (jump[j][i - 1] != -1) {
                jump[j][i] = jump[jump[j][i - 1]][i - 1];
            }
        }
    }


    vector<vector<pair<int,int>>> event(m + 1);

    //for (auto x: query) {
    for (int i = 0; i < (int)query.size(); i++) {
        auto x = query[i];
        event[x.second].push_back({x.first, i});
    }

    int best_l = -1;
    for (int i = 0; i < m; i++) {
        int need = n - 1;
        int v = i;
        for (int j = 0; j < LOG; j++) {
            if (need & pw(j) && v != -1) {
                v = jump[v][j];
            }
        }
        best_l = max(best_l, v);
        for (auto t: event[i + 1]) {
            answer[t.S] = t.F <= best_l;
        }
    }

    for (int i = 0; i < q; i++) {
        assert(answer[i] != -1);
        printf("%d", answer[i]);
    }
    puts("");

































    return 0;
}