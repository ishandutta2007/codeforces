#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 100005;

struct frac {
    int w;
    ll x, y;
    frac(int w, ll x, ll y) : w(w), x(x), y(y) {}
    frac() : w(0), x(0), y(0) {}
    bool operator <(const frac &rhs) const {
        return (double)x / y > (double)rhs.x / rhs.y;
    }
};

int K, N, M;
int a[MAXN];
int t[MAXN], idx[MAXN], b[MAXN];
int assign[MAXN];
vector < pii > V[MAXN];
vector <frac> all;

void load() {
    scanf("%d%d%d", &K, &N, &M);
    for (int i = 0; i < K; i++)
        scanf("%d", a + i);
    for (int i = 0; i < N; i++)
        scanf("%d%d%d", t + i, idx + i, b + i);
}

bool cmp(const frac &lhs, const frac &rhs) {
    return t[lhs.w] < t[rhs.w];
}

void solve() {
    memset(assign, -1, sizeof assign);
    for (int i = 0; i < N; i++) {
        idx[i]--;
        if (t[i] == 1) {
            if (assign[idx[i]] == -1 || b[i] > b[assign[idx[i]]])     
                assign[idx[i]] = i;
            continue;
        }
        if (t[i] == 2) {
            V[idx[i]].push_back(pii(b[i], i));
            continue;
        }
        if (b[i] > 1) 
            all.push_back(frac(i, (ll)b[i], 1));
    }
    
    for (int i = 0; i < K; i++) {
        if (assign[i] != -1 && b[assign[i]] > a[i]) 
            V[i].push_back(pii(b[assign[i]] - a[i], assign[i]));
        sort(V[i].begin(), V[i].end(), greater < pii > ());
        ll sum = (ll)a[i];
        for (int j = 0; j < V[i].size(); j++) {
            all.push_back(frac(V[i][j].second, sum + (ll)V[i][j].first, sum));
            sum += (ll)V[i][j].first;
        }
    }
    
    int L = min((int)all.size(), M);
    sort(all.begin(), all.end());
    sort(all.begin(), all.begin() + L, cmp);
    printf("%d\n", L);
    for (int i = 0; i < L; i++)
        printf("%d ", ++all[i].w);
    puts("");
}

int main() {
    load();
    solve();
    return 0;
}