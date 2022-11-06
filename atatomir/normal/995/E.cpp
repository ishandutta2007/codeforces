#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <map>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

const ll limit = 100;
const ll ini = 30000;;

ll u, v, mod, i, j;
vector< vector<int> > ways;
map<ll, pair<int, int> > M;

ll poww(ll a, ll b) {
    ll ans = 1;
    while (b > 0) {
        if (b & 1) ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return ans;
}

ll nxt(ll x) {
    return (x + 1) % mod;
}

ll pred(ll x) {
    return (x + mod - 1) % mod;
}

ll inv(ll x) {
    return poww(x, mod - 2);
}

void generate_path() {
    vector<int> aux = {};
    ll act = u;
    ll r, i;

    for (i = 1; i <= limit; i++) {
        r = rand() % 3;
        if (r == 0) {
            aux.pb(1);
            act = nxt(act);
        }
        if (r == 1) {
            aux.pb(2);
            act = pred(act);
        }
        if (r == 2) {
            aux.pb(3);
            act = inv(act);
        }

        if (M.count(act) == 0) {
            M[act] = mp(ways.size(), aux.size());
        }
    }

    ways.pb(aux);
}

void generate_path2() {
    vector<int> aux = {};
    ll act = v;
    ll r, i;

    for (i = 0; i <= limit; i++) {
        if (i > 0) {
            r = rand() % 3;
            if (r == 0) {
                aux.pb(2);
                act = nxt(act);
            }
            if (r == 1) {
                aux.pb(1);
                act = pred(act);
            }
            if (r == 2) {
                aux.pb(3);
                act = inv(act);
            }
        }

        if (M.count(act) == 0) continue;
        int id = M[act].first;
        int until = M[act].second;

        reverse(aux.begin(), aux.end());
        printf("%d\n", until + aux.size());
        for (ll i = 0; i < until; i++) printf("%d ", ways[id][i]);
        for (auto e : aux) printf("%d ", e);
        exit(0);
    }

    ways.pb(aux);

}

int main()
{
    //freopen("test.in","r",stdin);
    srand(time(NULL));
    
    scanf("%lld%lld%lld", &u, &v, &mod);

    if (u == v) {
        printf("0");
        return 0;
    }

    for (i = 1; i <= ini; i++) 
        generate_path();
   
    while (true) generate_path2();


    return 0;
}