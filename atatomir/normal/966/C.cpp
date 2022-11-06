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

const int maxBts = 61;

ll n, i, j, x, act;
vector<ll> v[maxBts + 11];
vector<ll> ord;
bool ok;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld", &n);
    for (i = 1; i <= n; i++) {
        scanf("%lld", &x);
        for (j = 0; (1LL << (j + 1)) <= x; j++);
        v[j].pb(x);
    }

    while (ord.size() < n) {
        ok = false;

        for (i = 0; i < maxBts; i++) {
            if ((act >> i) & 1) continue;
            if (v[i].empty()) continue;

            x = v[i].back();
            v[i].pop_back();
            act ^= x;
            ord.pb(x);
            ok = true;

            //cerr << act << ' ';
            break;
        }

        if (!ok) break;
    }

    //cerr << '\n';

    if (ord.size() < n) {
        printf("No");
        return 0;
    } else {
        printf("Yes\n");
        for (auto e : ord) printf("%lld ", e);
    }


    return 0;
}