#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

const int MAXN = 100005;

struct event {
    int x, y, z, t, w;
    event(int x, int y, int z, int t, int w) : x(x), y(y), z(z), t(t), w(w) {}
    event() : x(0), y(0), z(0), t(0), w(0) {}
    bool operator <(const event &rhs) const {
        if (x != rhs.x) return x < rhs.x;
        return t < rhs.t;
    }
};

int N, K;
int x[MAXN], y[MAXN];
vector <int> X, Y;
vector <event> V;
int f[MAXN];
int cnt[MAXN];
int sx[MAXN];

void load() {
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        x[i] = x1 + x2;
        y[i] = y1 + y2;
    }
}

int cx(int tx) {
    return lower_bound(X.begin(), X.end(), tx) - X.begin();
}

int cy(int ty) {
    return lower_bound(Y.begin(), Y.end(), ty) - Y.begin();
}

void update(int x) {
    for (++x; x < MAXN; x += x & -x)
        f[x]++;
}

int get(int x) {
    int ret = 0;
    for (++x; x; x -= x & -x)
        ret += f[x];
    return ret;
}

int query(int lo, int hi) {
    return get(hi) - get(lo - 1);
}

int calc(int lo, int hi) {
    return max((hi - lo + 1) / 2, 1);
}

ll solve() {
    for (int i = 0; i < N; i++) {
        X.push_back(x[i]);
        Y.push_back(y[i]);
    }
    
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
        
    int idx = 0;
    for (int i = 0; i <= K; i++)
        for (int j = 0; j <= K; j++)
            for (int k = 0; k <= K; k++)
                for (int l = 0; l <= K; l++) {
                    if (i > N - j - 1 || k > N - l - 1) continue;
                    V.push_back(event(X[i], Y[k], Y[N - l - 1], 0, idx));
                    V.push_back(event(X[N - j - 1], Y[k], Y[N - l - 1], 2, idx));
                    sx[idx++] = X[i];
                }
    
    for (int i = 0; i < N; i++)
        V.push_back(event(x[i], y[i], -1, 1, -1));
        
    sort(V.begin(), V.end());
    
    ll sol = (ll)5e18;
    for (int i = 0; i < V.size(); i++) 
        if (V[i].t == 0) 
            cnt[V[i].w] -= query(cy(V[i].y), cy(V[i].z));
        else if (V[i].t == 1) 
            update(cy(V[i].y));
        else {   
            cnt[V[i].w] += query(cy(V[i].y), cy(V[i].z));
            if (cnt[V[i].w] >= N - K) 
                sol = min(sol, (ll)calc(sx[V[i].w], V[i].x) * (ll)calc(V[i].y, V[i].z));
        }
            
    return sol;
}

int main() {
    load();
    printf("%I64d\n", solve());
    return 0;
}