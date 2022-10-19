#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 300005;
const int MAXM = 1000005;
const int MAXL = 19;
    
int N;
int a[MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) 
        scanf("%d", a + i);
}

int g[MAXL][MAXN];
int exp[MAXN];

void init() {
    for (int i = 0; (1 << i) <= N; i++) 
        for (int j = 0; j < N; j++) 
            if (i) g[i][j] = __gcd(g[i - 1][j], g[i - 1][j + (1 << i - 1)]);
            else g[i][j] = a[j];
    for (int i = 2; i <= N; i++)  
        exp[i] = exp[i >> 1] + 1;
}

int occ[MAXM];

inline int query(int lo, int hi) {
    int e = exp[hi - lo];
    return __gcd(g[e][lo], g[e][hi - (1 << e)]);
}

vector <int> check(int k) {
    vector <int> res;
    for (int i = 0; i < N; i++) 
        occ[a[i]] = 0;
    for (int i = 0; i < N; i++) {
        occ[a[i]]++;
        if (i >= k - 1) {
            if (i >= k) occ[a[i - k]]--;
            if (occ[query(i - k + 1, i + 1)]) 
                res.push_back(i - k + 1);
        }
    }
    return res;
}

void solve() {
    int lo = 1, hi = N + 1, mid;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (check(mid).empty()) hi = mid;
        else lo = mid + 1;
    }
    vector <int> sol = check(lo - 1);
    printf("%d %d\n", sol.size(), lo - 2);
    for (int i = 0; i < sol.size(); i++) 
        printf("%d ", sol[i] + 1);
    puts("");
}

int main() {
    load();
    init();
    solve();
    return 0;
}