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

const ll limit = 1LL << 60;

ll n, k, M, D, i;
ll ans = 0;

void try_with(ll x) {
    if (x <= 0) return;

    ll tms = n / x;
    if (tms == 0) return;
    tms--;

    if (x > M) return;
    if (((tms / k) + 1) > D) return;

    ans = max(ans, ((tms / k) + 1) * x);
}

void check(ll tms) {
    ll per, hr;

    if (limit / k < tms - 1) return;

    hr = tms;
    tms = (tms - 1) * k + 1;
    if (tms <= 0) return;
    per = n / tms;

    if (per <= 0) return;
    if (per > M) return;
    try_with(per);
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n >> k >> M >> D;
    for (i = 1; i <= D; i++) check(i);
    try_with(M);

    if (limit / D >= k) {
        try_with( (n + k * D - 1) / (k * D));
    }


    cout << ans;

    return 0;
}