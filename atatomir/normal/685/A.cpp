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

//! 0 to n - 1

#define pow poww

int i, d1, d2, aux;
ll n, m;

int limit;
bool used[7];
ll pow;

int ans;


bool is_lower(ll val, ll lim) {
    ll real = 0;
    ll act_pow = 1;

    while (val) {
        real += act_pow * (val % 10);
        val /= 10;
        act_pow *= 7;
    }

    return real < lim;
}

void gen_to(int pas, ll act) {
    if (pas == limit + 1) {
        if (!is_lower(act / pow, n)) return;
        if (!is_lower(act % pow, m)) return;

        ans++;

        return;
    }

    for (int i = 0; i < 7; i++) {
        if (used[i]) continue;

        used[i] = true;
        gen_to(pas + 1, act * 10 + i);
        used[i] = false;
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld%lld", &n, &m);

    aux = n - 1; d1 = 0;
    while (aux) {
        d1++;
        aux /= 7;
    }

    d1 = max(d1, 1);

    aux = m - 1; d2 = 0; poww = 1;
    while (aux) {
        d2++;
        aux /= 7;
        poww *= 10;
    }

    d2 = max(d2, 1);


    limit = d1 + d2;
    gen_to(1, 0);

    printf("%d", ans);


    return 0;
}