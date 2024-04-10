#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 200011

int n, m, i, pos;
pair<ll, int> ord[maxN];
ll x[maxN], len;
int wh[maxN];

int next_right(int pos, ll len) {
    return upper_bound(x + 1, x + n + 1, x[pos] + len) - x - 1;
}

int next_left(int pos, ll len) {
    return lower_bound(x + 1, x + n + 1, x[pos] - len) - x;
}

int get_next(int pos, ll len, bool right) {
    if (right) {
        int p = next_right(pos, len);
        if (p == pos) p = next_left(pos, len);
        return p;
    } else {
        int p = next_left(pos, len);
        if (p == pos) p = next_right(pos, len);
        return p;
    }
}

ll abss(ll x) {
    if (x < 0) return -x;
    return x;
}

int solve(int pos, ll len, bool right) {
    int to = get_next(pos, len, right);
    ll dif = abss(x[pos] - x[to]);

    if (to == pos) return pos;
    int toto = get_next(to, len - dif, (to < pos));

    if (toto == pos) return solve(pos, len % (2 * dif), right);
    return solve(toto, len - dif - abss(x[to] - x[toto]), (toto < to));
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++) scanf("%lld", &x[i]), ord[i] = mp(x[i], i);
    sort(x + 1, x + n + 1);
    sort(ord + 1, ord + n + 1);
    for (i = 1; i <= n; i++) wh[ord[i].second] = i;

    for (i = 1; i <= m; i++) {
        scanf("%d%lld", &pos, &len);
        pos = wh[pos];
        cout << ord[solve(pos, len, true)].second << '\n';
    }



    return 0;
}