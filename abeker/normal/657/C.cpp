#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <ll, int> pii;

const int MAXN = 200005;
const int offset = 1 << 18;
const int INF = (int)1e9;

struct tournament {
    int cnt[2 * offset];
    ll sum[2 * offset];
    tournament() {
        memset(cnt, 0, sizeof cnt);
        memset(sum, 0, sizeof sum);
    }
    void update(int x, ll val) {
        x += offset;
        cnt[x] = 1;
        sum[x] = val;
        for (x /= 2; x; x /= 2) {
            cnt[x] = cnt[2 * x] + cnt[2 * x + 1];
            sum[x] = sum[2 * x] + sum[2 * x + 1];
        }
    }
    ll query(int x, int lo, int hi, int k) {
        if (hi - lo == 1) return sum[x];
        int mid = (lo + hi) / 2;
        int rest = k - cnt[2 * x];
        if (rest > 0) return sum[2 * x] + query(2 * x + 1, mid, hi, rest);
        return query(2 * x, lo, mid, k);
    }
};

int N, K, B, C;
int t[MAXN];
ll pref[MAXN];
int idx[MAXN][5];
ll value[MAXN][5];
pii p[MAXN];
tournament T[5];

void load() {
    scanf("%d%d%d%d", &N, &K, &B, &C);
    for (int i = 0; i < N; i++)
        scanf("%d", t + i); 
}

ll get(int lo, int hi) {
    return pref[hi] - (lo ? pref[lo - 1] : 0);
}

ll f(int x) {
    return (ll)(x / 5) * B + (ll)(x % 5) * C;
}

ll solve() {
    sort(t, t + N);
    ll sol = (ll)1e18;
    
    if (B >= 5 * C) {
        pref[0] = t[0];
        for (int i = 1; i < N; i++)
            pref[i] = pref[i - 1] + t[i];
        for (int i = K - 1; i < N; i++)
            sol = min(sol, (ll)K * t[i] - get(i - K + 1, i));
        return sol * C;
    }
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < N; j++)
            p[j] = pii(f(INF + i - t[j]), j);
        sort(p, p + N);
        for (int j = 0; j < N; j++) {
            idx[p[j].second][i] = j;
            value[p[j].second][i] = p[j].first;
        }
    }
    
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < 5; j++) {
            int tmp = t[i] + j;
            int mod = (tmp % 5 + 5) % 5;
            T[mod].update(idx[i][mod], value[i][mod]);
            if (i >= K - 1) 
                sol = min(sol, T[mod].query(1, 0, offset, K) - (ll)(INF + mod - tmp) / 5 * B * K);
        }
    
    return sol;
}

int main() {
    load();
    printf("%I64d\n", solve());
    return 0;
}