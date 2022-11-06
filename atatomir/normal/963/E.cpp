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

const int defX[4] = {-1, 0, +1, 0};
const int defY[4] = {0, -1, 0, +1};
ll p[4];

const int maxN = 103;
const ll mod = 1000000007;
const int limit = maxN * 1.1;

ll poww(ll a, ll b) {
    ll ans = 1; a %= mod;
    while (b > 0) {
        if (b & 1) ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return ans;
}

struct ec {
    vector< pair<int, ll> > coef;
    ll sum;

    ec(vector< pair<int, ll> > _c, ll _s) {
        coef = _c;
        sum = _s;
    }

    ec() {
        coef = {};
        sum = 0;
    }

    void operator*=(ll x) {
        sum = (sum * x) % mod;
        for (auto& e : coef)
            e.second = (e.second * x) % mod;
    }

    void operator+=(ec who) {
        static vector< pair<int, ll> > aux;
        int p1, p2;

        sum = (sum + who.sum) % mod;
        aux = coef;
        coef.clear();

        for (p1 = p2 = 0; p1 < aux.size() && p2 < who.coef.size(); ) {
            if (aux[p1].first == who.coef[p2].first) {
                coef.pb(mp(aux[p1].first, (aux[p1].second + who.coef[p2].second) % mod));
                if (coef.back().second == 0) coef.pop_back();
                p1++; p2++;
            } else {
                if (aux[p1].first < who.coef[p2].first) {
                    coef.pb(aux[p1]);
                    p1++;
                } else {
                    coef.pb(who.coef[p2]);
                    p2++;
                }
            }
        }

        while (p1 < aux.size()) {
            coef.pb(aux[p1]);
            p1++;
        }

        while (p2 < who.coef.size()) {
            coef.pb(who.coef[p2]);
            p2++;
        }
    }
};

struct gauss {
    vector<ec> data;
    vector<ll> sol;

    void solve() {
        int i, j, act;
        ll aux;

        /*for (auto v : data) {
            for (auto e : v.coef) cerr << "(" << e.first << ", " << e.second << ") ";
            cerr << v.sum << '\n';
        }
        cerr << "\n\n";*/

        sol.clear();
        for (i = 0; i < data.size(); i++) {
            aux = poww(data[i].coef[0].second, mod - 2);
            data[i] *= aux;

            for (j = i + 1; j < data.size() && j - i <= limit; j++) {
                if (data[j].coef[0].first != data[i].coef[0].first) continue;
                aux = poww(data[j].coef[0].second, mod - 2);
                aux = (mod - aux) % mod;
                data[j] *= aux;
                data[j] += data[i];
            }

            /*for (auto v : data) {
                for (auto e : v.coef) cerr << "(" << e.first << ", " << e.second << ") ";
                cerr << v.sum << '\n';
            }
            cerr << "\n\n";*/
        }

        sol.resize(data.size());
        for (i = data.size() - 1; i >= 0; i--) {
            act = data[i].coef[0].first;
            sol[act] = data[i].sum;
            for (j = 1; j < data[i].coef.size(); j++)
                sol[act] = (sol[act] + mod - ((data[i].coef[j].second * sol[data[i].coef[j].first]) % mod)) % mod;
        }
    }
};

ll R, i, j, d, a1, a2, a3, a4, aux, act, sz, id;
vector< pair<int, ll> > act_ec;
gauss work;

int main()
{
    //freopen("test.in","r",stdin);

    cin >> R >> a1 >> a2 >> a3 >> a4;

    aux = poww(a1 + a2 + a3 + a4, mod - 2);
    p[0] = (a1 * aux) % mod;
    p[1] = (a2 * aux) % mod;
    p[2] = (a3 * aux) % mod;
    p[3] = (a4 * aux) % mod;

    act = -1; sz = 2 * R + 3;
    for (i = -R - 1; i <= R + 1; i++) {
        for (j = -R - 1; j <= R + 1; j++) {
            act++;
            act_ec.clear();

            if (i == 0 && j == 0) id = act;

            if (i * i + j * j > R * R) {
                act_ec.pb(mp(act, 1LL));
                work.data.pb((ec){act_ec, 0});
                continue;
            }

            act_ec.pb(mp(act, 1LL));
            act_ec.pb(mp(act - sz, mod - p[0]));
            act_ec.pb(mp(act - 1, mod - p[1]));
            act_ec.pb(mp(act + sz, mod - p[2]));
            act_ec.pb(mp(act + 1, mod - p[3]));

            sort(act_ec.begin(), act_ec.end());
            work.data.pb({act_ec, 1LL});
        }
    }

    work.solve();
    printf("%lld", work.sol[id]);


    return 0;
}