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

#define maxN 300011

int n, i, pos;
ll p[maxN], s[maxN];

pair<ll, ll> dp[maxN];
pair<ll, ll> from_here[maxN], until_here[maxN];
vector<int> moves;

void upd(pair<ll, ll>& a, pair<ll, ll> b) {
    a = min(a, b);
}

ll execute(ll& a, ll& b) {
    ll aux = min(a, b);
    a -= aux;
    b -= aux;
    return 2LL * aux;
}

ll magic3(ll a, ll b, ll c) {
    ll ans = 0;
    ans += execute(b, c);
    ans += 2 * b + c;
    return ans;
}

pair<ll, ll> get_from_here(int pos) {
    return mp(dp[pos].first + magic3(p[pos], p[pos + 1], p[pos + 2]) - s[pos + 2], pos);
}

ll case_one(ll a, ll b, ll c) {
    ll ans = 0;
    ans += 2LL * b;
    //ans += execute(a, b);
    //ans += execute(b, c);
    return ans;
}

ll case_two(ll a, ll b, ll c, ll d) {
    ll ans = 0;
    ans += execute(b, c);
    //ans += execute(a, b);
    //ans += execute(c, d);
    ans += 2LL * (b + c);
    return ans;
}

ll case_three_one(ll a, ll b, ll c, ll d, ll e) {
    ll ans = 0;
    ans += execute(b, c);
    ans += execute(c, d);
    //ans += execute(a, b);
    //ans += execute(d, e);
    ans += 2LL * (b + d);
    return ans;
}

ll case_three_two(ll a, ll b, ll c, ll d, ll e) {
    ll ans = 0;
    ans += execute(c, d);
    ans += execute(b, c);
    //ans += execute(a, b);
    //ans += execute(d, e);
    ans += 2LL * (b + d);
    return ans;
}

ll case_three(ll a, ll b, ll c, ll d, ll e) {
    return min(case_three_one(a, b, c, d, e),
               case_three_two(a, b, c, d, e));
}

void get_moves(int l, int r) {
    int i, j;

    if (l + 1 >= r) return;

    if (r - l - 1 == 3) {
        if (case_three_two(p[l], p[l + 1], p[l + 2], p[l + 3], p[l + 4]) <
            case_three_one(p[l], p[l + 1], p[l + 2], p[l + 3], p[l + 4]) ) {

            if (p[l + 2] > 0 && p[l + 3] > 0) {
                execute(p[l + 2], p[l + 3]);
                moves.pb(l + 2);
            }

        }
    }

    i = l + 1; j = r - 1;
    while (i < j) {
        if (p[i] > 0 && p[i + 1] > 0) {
            execute(p[i], p[i + 1]);
            moves.pb(i);
        }

        if (p[j] > 0 && p[j - 1] > 0) {
            execute(p[j], p[j - 1]);
            moves.pb(j - 1);
        }

        i++; j--;
    }

    if (p[l] > 0 && p[l + 1] > 0) {
        execute(p[l], p[l + 1]);
        moves.pb(l);
    }

    if (p[r] > 0 && p[r - 1] > 0) {
        execute(p[r - 1], p[r]);
        moves.pb(r - 1);
    }
}

int main()
{
    // freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%lld", &p[i]);
        s[i] = s[i - 1] + p[i];
    }

    //! add position 0
    dp[0] = mp(0, 0);
    from_here[0] = until_here[0] = get_from_here(0);

    //! add position 1
    dp[1] = mp(0, 0);
    from_here[1] = get_from_here(1);
    until_here[1] = min(until_here[0], from_here[1]);

    for (i = 2; i <= n + 1; i++) {
        //! size 1
        dp[i] = mp(dp[i - 2].first + case_one(p[i - 2], p[i - 1], p[i]), i - 2);

        //! size 2
        if (i - 3 >= 0) {
            upd(dp[i], mp(dp[i - 3].first + case_two(p[i - 3], p[i - 2], p[i - 1], p[i]), i - 3));
        }

        //! size 3
        if (i - 4 >= 0) {
            upd(dp[i], mp(dp[i - 4].first + case_three(p[i - 4], p[i - 3], p[i - 2], p[i - 1], p[i]), i - 4));
        }

        //! size >= 4
        if (i - 5 >= 0) {
            //upd(dp[i], mp( until_here[i - 5].first + s[i - 3] + magic3(p[i - 2], p[i - 1], p[i - 2]), until_here[i - 5].second));
        }

        from_here[i] = get_from_here(i);
        until_here[i] = min(until_here[i - 1], from_here[i]);
    }

    pair<ll, ll> best;
    best = min(mp(dp[n].first, n), mp(dp[n + 1].first, n + 1));
    pos = best.second;

    vector<int> sol = {};
    while (pos != 0) {
        sol.pb(pos);
        pos = dp[pos].second;
    }
    sol.pb(0);

    reverse(sol.begin(), sol.end());
    for (i = 0; i + 1 < sol.size(); i++)
        get_moves(sol[i], sol[i + 1]);

    printf("%d\n", moves.size());
    for (auto e : moves) printf("%d\n", e);

    cerr << "\n\n Total cost " << best.first << ' ' << best.first / 2 << '\n';


    return 0;
}