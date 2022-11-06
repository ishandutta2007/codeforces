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

#define maxN 66

int r, c, n, i;
char s[maxN];
ll comb[maxN][maxN];

int cnt_a[maxN], cnt_b[maxN];
vector<ll> partial[maxN], partial_zero[maxN];

void compute_comb() {
    int i, j;

    for (i = 0; i <= n; i++) {
        comb[i][0] = 1;
        for (j = 1; j <= i; j++)
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
    }
}

ll get_difs(int conf, int a_bef, int b_bef) {
    int i;
    ll ans = 0;
    ll aux1, aux2;

    for (i = 0; i < c + 1; i++) {
        if (conf & (1 << i)) {
            //! here comes a B
            b_bef++;

            aux1 = comb[b_bef - 1][r - 1];
            aux2 = comb[n - b_bef][r] - comb[a_bef][r];

            ans -= aux1 * aux2;
        } else {
            //! here comes an A
            a_bef++;

            aux1 = comb[a_bef - 1][r - 1];
            aux2 = comb[n - a_bef][r] - comb[b_bef][r];

            ans += aux1 * aux2;
        }
    }

    return ans;
}

bool check(int conf) {
    int i;

    for (i = 0; i < c + 1; i++) {
        if (s[2 * r + c + i] == 'A' && ( (conf >> i) & 1 ) == 1) return false;
        if (s[2 * r + c + i] == 'B' && ( (conf >> i) & 1 ) == 0) return false;
    }

    return true;
}

void compute_second_part() {
    int i, conf;
    int limit = 1 << (c + 1);
    int a_here, b_here;

    for (conf = 0; conf < limit; conf++) {
        b_here = __builtin_popcount(conf);
        a_here = c + 1 - b_here;

        if (check(conf))
            partial[a_here].pb(get_difs(conf, r + c - a_here, r + c - b_here));
        else
            partial_zero[a_here].pb(get_difs(conf, r + c - a_here, r + c - b_here));
    }

    for (i = 0; i <= c + 1; i++) {
        sort(partial[i].begin(), partial[i].end());
        sort(partial_zero[i].begin(), partial_zero[i].end());
    }
}

ll get_coef(int conf) {
    int i, j;

    for (i = 0; i < c + 1; i++)
        if ( ((conf >> i) & 1) != (conf & 1) )
            break;

    for (j = i; j < c + 1; j++) {
        if (s[2 * r - 1 + j] == 'A' && (( (conf >> j) & 1 ) == 1)) return 0;
        if (s[2 * r - 1 + j] == 'B' && (( (conf >> j) & 1 ) == 0)) return 0;
    }

    int set_a = r - 1 + ( (conf & 1) == 0 ? i : 0 );
    int set_b = r - 1 + ( (conf & 1) == 1 ? i : 0 );

    if (set_a < cnt_a[2 * r - 2 + i]) return 0;
    if (set_b < cnt_b[2 * r - 2 + i]) return 0;
    return comb[set_a + set_b - cnt_a[2 * r - 2 + i] - cnt_b[2 * r - 2 + i]][set_a - cnt_a[2 * r - 2 + i]];
}

void upd(pair<ll, ll>& ans, pair<ll, ll> act) {
    if (act.first < 0) act.first = -act.first;

    if (ans.first < act.first) return;
    if (ans.first > act.first) {
        ans = act;
        return;
    }

    ans.second += act.second;
}

ll how_many(vector<ll>& data, ll val) {
    auto it1 = lower_bound(data.begin(), data.end(), val);
    auto it2 = upper_bound(data.begin(), data.end(), val);
    return it2 - it1;
}

ll compute_first_part() {
    int i, conf;
    int limit = 1 << (c + 1);
    int a_here, b_here;
    ll act, coef, coef2;
    pair<ll, ll> ans = mp(1LL << 60, 0);


    for (conf = 0; conf < limit; conf++) {
        b_here = __builtin_popcount(conf);
        a_here = c + 1 - b_here;
        act = get_difs(conf, r - 1, r - 1);

        //! coef may be != 0
        coef = get_coef(conf);
        auto it = lower_bound(partial[c + 1 - a_here].begin(),
                              partial[c + 1 - a_here].end(),
                              -act);


        if (it != partial[c + 1 - a_here].end()) {
            if (ans.first >= abs(*it + act)) {
                coef2 = how_many(partial[c + 1 - a_here], *it);
                upd(ans, mp(*it + act, coef * coef2));
            }
        }

        if (it != partial[c + 1 - a_here].begin()) {
            it--;
            if (ans.first >= abs(*it + act)) {
                coef2 = how_many(partial[c + 1 - a_here], *it);
                upd(ans, mp(*it + act, coef * coef2));
            }
        }

        //! coef is clearly 0
        coef = 0;
        it = lower_bound(partial_zero[c + 1 - a_here].begin(),
                         partial_zero[c + 1 - a_here].end(),
                         -act);


        if (it != partial_zero[c + 1 - a_here].end()) {
            coef2 = how_many(partial[c + 1 - a_here], *it);
            if (ans.first >= abs(*it + act)) {
                coef2 = how_many(partial_zero[c + 1 - a_here], *it);
                upd(ans, mp(*it + act, coef * coef2));
            }
        }

        if (it != partial_zero[c + 1 - a_here].begin()) {
            it--;
            if (ans.first >= abs(*it + act)) {
                coef2 = how_many(partial_zero[c + 1 - a_here], *it);
                upd(ans, mp(*it + act, coef * coef2));
            }
        }
    }

    return ans.second;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d\n%s", &r, &c, s + 1);
    n = 2 * (r + c);

    compute_comb();

    for (i = 1; i <= n; i++) {
        cnt_a[i] = cnt_a[i - 1] + (s[i] == 'A' ? 1 : 0);
        cnt_b[i] = cnt_b[i - 1] + (s[i] == 'B' ? 1 : 0);
    }

    compute_second_part();
    ll sol = compute_first_part();

    printf("%lld", sol);

    return 0;
}