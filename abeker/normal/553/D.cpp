#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 100005;

int N, M, K;
int a[MAXN];
bool fort[MAXN];
vector <int> E[MAXN];
pii frac[MAXN];
vector < pii > V;

bool comp(const pii &lhs, const pii &rhs) {
    return (ll)lhs.first * rhs.second < (ll)rhs.first * lhs.second;
}

struct cmp {
    bool operator()(const int &lhs, const int &rhs) const {
        if (comp(frac[lhs], frac[rhs])) return 1;
        if (comp(frac[rhs], frac[lhs])) return 0;
        return lhs < rhs;
    }
};

set <int, cmp> S;

void load() {
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 0; i < K; i++)
        scanf("%d", a + i);
    while (M--) {
        int a, b;
        scanf("%d%d", &a, &b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
}

bool check(int val) {
    memset(fort, false, sizeof fort);
    for (int i = 0; i < K; i++) 
        fort[a[i]] = true;
    for (int i = 1; i <= N; i++) {
        frac[i].first = frac[i].second = E[i].size();
        for (int j = 0; j < E[i].size(); j++)
            frac[i].first -= fort[E[i][j]];
    }
    
    S.clear();
    for (int i = 1; i <= N; i++)
        if (!fort[i]) S.insert(i);
    
    while (!S.empty()) {
        int x = *S.begin();
        if (!comp(frac[x], V[val]))
            break;
        S.erase(x);
        fort[x] = true;
        for (int i = 0; i < E[x].size(); i++) {
            int nxt = E[x][i];
            if (fort[nxt]) continue;
            S.erase(nxt);
            frac[nxt].first--;
            S.insert(nxt);
        }
    }
    
    return !S.empty();
}

void solve() {
    for (int i = 1; i <= N; i++) 
        for (int j = 0; j <= E[i].size(); j++)
            V.push_back(pii(j, E[i].size()));
    sort(V.begin(), V.end(), comp);
    V.resize(unique(V.begin(), V.end()) - V.begin());

    int lo = 0, hi = (int)V.size() - 1;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (check(mid)) lo = mid;
        else hi = mid - 1; 
    }
    check(lo);
    printf("%d\n", S.size());
    for (set <int> :: iterator it = S.begin(); it != S.end(); it++)
        printf("%d ", *it);
    puts("");
}

int main() {
    load();
    solve();
    return 0;
}