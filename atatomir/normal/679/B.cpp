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

ll m;

ll cube(ll x) {
    return x * x * x;
}

pair<ll, ll> solve(ll rem) {
    ll a;
    pair<ll, ll> ans, aux;

    if (rem == 0) return mp(0, 0);
    for (a = 1; cube(a + 1) <= rem; a++);

    aux = solve(rem - cube(a));
    aux.first++; aux.second += cube(a);
    ans = aux;

    rem = cube(a) - 1; a--;
    if (a > 0) {
        aux = solve(rem - cube(a));
        aux.first++; aux.second += cube(a);

        ans = max(ans, aux);
    }

    return ans;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld", &m);
    auto ans = solve(m);

    printf("%lld %lld", ans.first, ans.second);

    return 0;
}