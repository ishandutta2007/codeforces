#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 10011


int n, b, q, i, j;
pair<int, int> Q[maxN];

int cnt[maxN][5];
vector<int> bits;
int low, high, sel;


void unfair() {
    printf("unfair");
    exit(0);
}

int how_many(int lim, int rem) {
    int how = (lim - rem) / 5;

    if (lim < rem) return 0;
    return how + 1;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d", &n, &b, &q);
    for (i = 1; i <= q; i++) scanf("%d%d", &Q[i].first, &Q[i].second);

    Q[++q] = mp(b, n);
    sort(Q + 1, Q + q + 1);
    q = unique(Q + 1, Q + q + 1) - Q - 1;

    for (i = 2; i <= q; i++) {
        if (Q[i].first == Q[i - 1].first) {
            unfair();
        }
    }

    for (i = 0; i < 5; i++) cnt[0][i] = n / 5;
    for (i = q; i > 0; i--) {
        Q[i].second -= Q[i - 1].second;

        for (j = 0; j < 5; j++) {
            cnt[i][j] = how_many(Q[i].first, j) - how_many(Q[i - 1].first, j);
        }
    }

    for (int mask = (1 << 5) - 1; mask > 0; mask--) {
        bits.clear();
        low = high = 0;

        for (i = 0; i < 5; i++)
            if ( (mask >> i) & 1 )
                bits.pb(i);

        for (i = 1; i <= q; i++) {
            sel = 0;

            for (auto e : bits)
                sel += cnt[i][e];

            int not_sel = (Q[i].first - Q[i - 1].first - sel);

            low += max(0, Q[i].second - not_sel);
            high += min(Q[i].second, sel);
        }

	bool ana_are_mere = false;
        int need = (n / 5) * __builtin_popcount(mask);
        if (need < low || need > high || ana_are_mere)
            unfair();
    }

    printf("fair");

    return 0;
}