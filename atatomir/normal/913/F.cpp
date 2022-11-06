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

#define mod 998244353
#define maxN 2018

ll poww(ll a, ll b) {
    ll ans = 1;
    while (b > 0) {
        if (b & 1) ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return ans;
}

struct zz {
    ll x;

    zz() {x = 0;}
    zz(ll _x) {x = _x;}

    zz operator+(const zz& who)const {
        static ll aux;
        aux = x + who.x;
        if (aux >= mod) aux -= mod;
        return aux;
    }

    zz operator-(const zz& who)const {
        static ll aux;
        aux = x + mod - who.x;
        if (aux >= mod) aux -= mod;
        return aux;
    }

    zz operator*(const zz& who)const {
        static ll aux;
        aux = x * who.x;
        aux %= mod;
        return aux;
    }

    zz operator/(const zz& who)const {
        static ll aux;
        aux = poww(who.x, mod - 2);
        return (x * aux) % mod;
    }
};

int n, i, a, b;
zz p, np;
zz p_pow[maxN], np_pow[maxN];

zz split[maxN][maxN];
zz is_split[maxN], is_not_split[maxN];

zz dp[maxN];
zz comb2[maxN];

void compute_chances() {
    int i, j;

    p_pow[0] = np_pow[0] = 1;
    for (i = 1; i <= n; i++) {
        p_pow[i] = p_pow[i - 1] * p;
        np_pow[i] = np_pow[i - 1] * np;
    }

    split[1][0] = 1;
    split[1][1] = 1;

    for (i = 1; i < n; i++) {
        for (j = 0; j <= i; j++) {
            split[i + 1][j] = split[i + 1][j] + split[i][j] * np_pow[j];
            split[i + 1][j + 1] = split[i + 1][j + 1] + split[i][j] * p_pow[i - j];
        }
    }

    /*for (i = 1; i <= n; i++) {
        for (j = 1; j < i; j++)
            is_split[i] = is_split[i] + split[i][j];
        is_not_split[i] = (zz)1 - is_split[i];
    }*/
}

void compute_dp() {
    int i, j;
    zz all;

    for (i = 1; i <= n; i++) comb2[i] = (i * (i - 1)) / 2;

    dp[1] = 0;
    is_split[1] = 0;
    is_not_split[1] = 1;

    for (i = 2; i <= n; i++) {
        all = comb2[i];
        for (j = 1; j < i; j++) {
            dp[i] = dp[i] + split[i][j] * is_not_split[i - j] * (all - comb2[j] + dp[i - j] + dp[j]);
            is_split[i] = is_split[i] + split[i][j] * is_not_split[i - j];
        }

        is_not_split[i] = (zz)1 - is_split[i];

        dp[i] = dp[i] + is_not_split[i] * all;
        dp[i] = dp[i] / is_split[i];
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n >> a >> b;
    p = (zz)(a) / (zz)(b);
    np = (zz)(1) - p;

    compute_chances();
    compute_dp();

    cout << dp[n].x;

    return 0;
}