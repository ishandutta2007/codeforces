#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 100011

ll n, i, limit, cf, cm, m, m_rez;
ll v[maxN];
ll sum[maxN];

ll rez[maxN];
int id[maxN];

ll answer = -1;
ll how_full;
ll how_min;

int pos;

int dim;
pair<int, int> S[maxN];

void new_ans(ll full) {
    ll m_aux = m;

    ll ans = 0;
    for (ll step = 1LL << 20; step; step >>= 1)
        if (ans + step <= n - full)
            if ( v[ans + step] * (ans + step - 1) - sum[ans + step - 1] <= m_aux)
                ans += step;

    m_aux -= v[ans] * (ans - 1) - sum[ans - 1];

    ll incr = (ans > 0 ? m_aux / ans : 0);
    ll mini = min(limit, v[ans] + incr);

    if (full == n)
        mini = limit;

    ll aux = full * cf + mini * cm;
    if (answer < aux) {
        answer = aux;
        how_full = full;
        how_min = mini;
    }
}

bool cmp(int a, int b) {
    return rez[a] < rez[b];
}

void recons() {
    int i;

    m = m_rez;

    for (int i = n; i > n - how_full; i--) {
        int ind = id[i];

        m -= limit - rez[ind];
        rez[ind] = limit;
    }

    for (i = 1; i <= n && m > 0; i++) {
        int ind = id[i];

        if (rez[ind] >= how_min)
            break;

        m -= how_min - rez[ind];
        rez[ind] = how_min;
    }

    for (i = 1; i <= n; i++)
        printf("%I64d ", rez[i]);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%I64d %I64d %I64d %I64d %I64d", &n, &limit, &cf, &cm, &m);
    for (i = 1; i <= n; i++) {
        scanf("%I64d", &v[i]);
        rez[i] = v[i];
        id[i] = i;
    }
    m_rez = m;

    sort(v + 1, v + n + 1);
    sort(id + 1, id + n + 1, cmp);

    for (i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + v[i];

    pos = n + 1;

    while (m >= 0 && pos > 1) {
        ll need = limit - v[pos - 1];
        if (need > m) break;

        m -= need;
        pos--;
    }

    if (pos == 1) {
        new_ans(n);
        m += limit - v[1];
        pos++;
    }

    new_ans(n - pos + 1);

    for (; pos <= n; pos++) {
        m += limit - v[pos];
        new_ans(n - pos);
    }

    printf("%I64d\n", answer);
    recons();

    return 0;
}