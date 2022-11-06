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

const int bts = 6;
const int limit = 1000000;
const ll mod = 1000000007;
const ll pows[6] = {1, 10, 100, 1000, 10000, 100000};

ll n, i, j, k, x;
ll cnt[limit], sum[limit], sum_sq[limit], data[limit];
ll pows2[limit + 11];

ll add(ll& a, ll b) {
    a += b;
    if (a >= mod) a -= mod;
}

void supraset() {
    int i, j, k;

    for (j = 0; j < bts; j++) {
        for (i = limit - 1; i > 0; i--) {
            if ( (i / pows[j]) % 10 == 9 )
                continue;

            add(cnt[i], cnt[i + pows[j]]);
            add(sum[i], sum[i + pows[j]]);
            add(sum_sq[i], sum_sq[i + pows[j]]);
        }
    }
}

void inv_supraset() {
    int i, j, k;

    for (j = 0; j < bts; j++) {
        for (i = 0; i < limit; i++) {
            if ( (i / pows[j]) % 10 == 9 )
                continue;

            add(data[i], mod - data[i + pows[j]]);
        }
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> x;
        cnt[x]++;
        add(sum[x], x);
        add(sum_sq[x], (x * x) % mod);
    }

    pows2[0] = 1;
    for (i = 1; i <= limit; i++)
        pows2[i] = (pows2[i - 1] * 2) % mod;

    supraset();

    for (i = 0; i < limit; i++) {
        if (cnt[i] == 0)
            continue;

        if (cnt[i] == 1) {
            data[i] = sum_sq[i];
            continue;
        }

        data[i] = (sum[i] * sum[i] + mod - sum_sq[i]) % mod;
        data[i] = (data[i] * pows2[cnt[i] - 2]) % mod;

        add(data[i], (sum_sq[i] * pows2[cnt[i] - 1]) % mod);
    }

    inv_supraset();

    ll ans = 0;
    for (i = 0; i < limit; i++) ans ^= 1LL * i * data[i];
    cout << ans;


    return 0;
}