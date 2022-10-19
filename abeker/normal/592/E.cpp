#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

const int MAXN = 400005;

struct frac {
    int x, y;
    frac(int _x, int _y) {
        x = _x;
        y = _y;
        if (y < 0) {
            x = -x;
            y = -y;
        }
    }
    frac(){}
    bool operator <(const frac &rhs) const {
        return (ll)x * rhs.y < (ll)rhs.x * y;
    }
};

typedef vector <frac> :: iterator it;

int N;
int C, D;
int r[MAXN], w[MAXN];
vector <frac> V[3];
ll cnt[2];

void load() {
    scanf("%d%d%d", &N, &C, &D);
    for (int i = 0; i < N; i++)
        scanf("%d%d", r + i, w + i);
}

int sgn(int x) {
    return x ? x > 0 : 2;
}

ll get(int idx, frac val) {
    pair <it, it> tmp = equal_range(V[idx].begin(), V[idx].end(), val);
    cnt[idx ^ 1] += (ll)(V[idx].end() - tmp.second);
    return (ll)(tmp.first - V[idx].begin()) * (V[idx].end() - tmp.second); 
}

ll solve() {
    for (int i = 0; i < N; i++) {
        r[i] -= C;
        w[i] -= D;
        V[sgn(w[i])].push_back(frac(r[i], w[i]));
    }
    
    for (int i = 0; i < 2; i++)
        sort(V[i].begin(), V[i].end());
    
    ll sol = 0;
    for (int k = 0; k < 2; k++)
        for (int i = 0; i < V[k].size(); i++)
            sol += get(k ^ 1, V[k][i]); 
    
    for (int i = 0; i < V[2].size(); i++)
        sol += cnt[sgn(V[2][i].x)];
    
    return sol;
}

int main() {
    load();
    printf("%I64d\n", solve());
    return 0;
}