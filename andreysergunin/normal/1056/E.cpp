#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <bitset>
#include <functional>
#include <tuple>
#include <complex>
#include <chrono>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned int uint;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 1000100;

int p[2], base[2];

bool isPrime(int p) {
    for (int i = 2; i * i <= p; ++i) {
        if (p % i == 0) {
            return false;
        }
    } 
    return true;
}

int random_p() {   
    int p = 5e8 + (rnd() % (int)(5e8));
    while (!isPrime(p)) {
        ++p;
    }
    return p;
}

void add(int &a, int b, int p) {
    a += b;
    if (a >= p) {
        a -= p;
    }
}

void sub(int &a, int b, int p) {
    a -= b;
    if (a < 0) {
        a += p;
    }
}

void mul(int &a, int b, int p) {
    ll c = (ll)a * b;
    c %= p;
    a = c;
}

struct Hash {
    Hash() {
        a[0] = 0;
        a[1] = 0;
    }

    int a[2];

    int& operator[](int k) {
        return a[k];
    }

    int operator[](int k) const {
        return a[k];
    }
};

Hash operator+(const Hash &h1, const Hash &h2) {
    Hash h;
    for (int i = 0; i < 2; ++i) {
        h[i] = h1[i];
        add(h[i], h2[i], p[i]);
    }
    return h;
}

Hash operator-(const Hash &h1, const Hash &h2) {
    Hash h;
    for (int i = 0; i < 2; ++i) {
        h[i] = h1[i];
        sub(h[i], h2[i], p[i]);
    }
    return h;
}

Hash operator*(const Hash &h1, const Hash &h2) {
    Hash h;
    for (int i = 0; i < 2; ++i) {
        h[i] = h1[i];
        mul(h[i], h2[i], p[i]);
    }
    return h;
}

bool operator==(const Hash &h1, const Hash &h2) {
    bool eq = true;
    for (int i = 0; i < 2; ++i) {
        eq &= (h1[i] == h2[i]);
    } 
    return eq;
}

int cnt[2][MAXN];

Hash h[MAXN];
Hash b[MAXN];

string s, t;

bool check(int u[2]) {
    // cout << "-> " << u[0] << " " << u[1] << endl;
    int n = sz(s);
    int m = sz(t);
    Hash hs[2];
    bool st[2] = {true, true};
    for (int i = 0; i < n; ++i) {
        int x = s[i] - '0';
        int pos = cnt[0][i] * u[0] + cnt[1][i] * u[1];
        Hash cur = h[pos + u[x]] - (h[pos] * b[u[x]]);
        // cout << cur[0] << " " << cur[1] << endl;

        if (st[x]) {
            st[x] = false;
            hs[x] = cur;
        } else {
            if (!(cur == hs[x])) {
                return false;
            }
        }
    }
    if (hs[0] == hs[1]) {
        return false;
    }
    return true;
}   

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    for (int i = 0; i < 2; ++i) {
        p[i] = random_p();
        while (base[i] < 1000) {
            base[i] = rnd() % p[i];
        }
        // cout << p[i] << " " << base[i] << endl;
    }

    cin >> s >> t;
    int n = sz(s);
    int m = sz(t);

    b[0][0] = 1;
    b[0][1] = 1;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < 2; ++j) {
            h[i + 1][j] = h[i][j];
            mul(h[i + 1][j], base[j], p[j]);
            add(h[i + 1][j], t[i], p[j]);
            b[i + 1][j] = b[i][j];
            mul(b[i + 1][j], base[j], p[j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        cnt[0][i + 1] = cnt[0][i];
        cnt[1][i + 1] = cnt[1][i];
        ++cnt[s[i] - '0'][i + 1];
    }


    int ans = 0;
    for (int i = 1; i * cnt[0][n] < m; ++i) {
        int u[2];
        u[0] = i;
        u[1] = (m - u[0] * cnt[0][n]) / cnt[1][n];

        if (u[0] * cnt[0][n] + u[1] * cnt[1][n] == m) {
            ans += check(u);
        }
    }

    cout << ans << endl;
}