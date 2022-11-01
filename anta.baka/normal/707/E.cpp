#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 2e3;
int n, m, k;
ll f[N][N], sum[N][N];

void add(int ii, int jj, int d) {
    for(int i = ii; i < n; i |= i+1)
        for(int j = jj; j < m; j |= j+1)
            f[i][j] += d;
}

ll get(int ii, int jj) {
    ll res = 0;
    for(int i = ii; i >= 0; i &= i+1, i--)
        for(int j = jj; j >= 0; j &= j+1, j--)
            res += f[i][j];
    return res;
}

ll rect(int i1, int j1, int i2, int j2) {
    return get(i2, j2)
    - (i1 > 0 ? get(i1-1, j2) : 0)
    - (j1 > 0 ? get(i2, j1-1) : 0)
    + (i1 > 0 && j1 > 0 ? get(i1-1, j1-1) : 0);
}

struct data {
    vector<int> i, j, c;
    int n;
};

data gy[N];

struct qdata {
    int type, i1, j1, i2, j2;
};

qdata qu2[N];
pii qu[1000000];

// ASK 0
// SWITCH 1

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < k; i++) {
        scanf("%d", &gy[i].n);
        gy[i].i.resize(gy[i].n);
        gy[i].j.resize(gy[i].n);
        gy[i].c.resize(gy[i].n);
        for(int j = 0; j < gy[i].n; j++) {
            scanf("%d%d%d", &gy[i].i[j], &gy[i].j[j], &gy[i].c[j]);
            --gy[i].i[j]; --gy[i].j[j];
        }
    }
    int q, q2 = 0;
    scanf("%d", &q);
    for(int i = 0; i < q; i++) {
        char s[8];
        scanf("%s", s);
        if(s[0] == 'A') {
            qu[i].first = 2; qu[i].second = q2;
            scanf("%d%d%d%d", &qu2[q2].i1, &qu2[q2].j1, &qu2[q2].i2, &qu2[q2].j2);
            --qu2[q2].i1; --qu2[q2].j1; --qu2[q2].i2; --qu2[q2].j2;
            q2++;
        } else {
            qu[i].first = 1;
            scanf("%d", &qu[i].second);
            --qu[i].second;
        }
    }
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < gy[i].n; j++)
            add(gy[i].i[j], gy[i].j[j], gy[i].c[j]);
        for(int j = 0; j < q2; j++)
            sum[i][j] = rect(qu2[j].i1, qu2[j].j1, qu2[j].i2, qu2[j].j2);
        for(int j = 0; j < gy[i].n; j++)
            add(gy[i].i[j], gy[i].j[j], -gy[i].c[j]);
    }
    vector<bool> on(k, true);
    for(int i = 0; i < q; i++)
        if(qu[i].first == 1)
            on[qu[i].second] = !on[qu[i].second];
        else {
            long long res = 0;
            for(int j = 0; j < k; j++)
                if(on[j])
                    res += sum[j][qu[i].second];
            printf("%I64d\n", res);
        }
    return 0;
}