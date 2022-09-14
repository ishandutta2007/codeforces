#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <ctime>

using namespace std;

const int P1 = 998244353;
const long long G1 = 565042129;

const int P2 = 7340033;
const long long G2 = 5;

long long binPow(long long a, long long b, int m) {
    if (a == 0)
        return 0;
    if (b == 0)
        return 1;
    long long c = binPow(a, b / 2, m);
    c = (c * c) % m;
    if (b % 2 == 1)
        return (c * a) % m;
    return c;
}

vector<long long> fft(const vector<long long> &as, int P, int g) {
    int n = (int)as.size();
    int k = 0;
    while ((1 << k) < n) k++;
    vector<int> rev(n);
    rev[0] = 0;
    int high1 = -1;
    for (int i = 1; i < n; i++) {
        if ((i & (i - 1)) == 0)
            high1++;
        rev[i] = rev[i ^ (1 << high1)];
        rev[i] |= (1 << (k - high1 - 1));
    }

    vector<long long> roots(n);

    roots[0] = 1;
    for (int i = 1; i < n; i++)
        roots[i] = g * roots[i - 1] % P;

    vector<long long> cur(n);
    for (int i = 0; i < n; i++)
        cur[i] = as[rev[i]];

    for (int len = 1; len < n; len <<= 1) {
        vector<long long> nCur(n);
        int rStep = (int)roots.size() / (len * 2);
        for (int pDest = 0; pDest < n;) {
            int p1 = pDest;
            for (int i = 0; i < len; i++) {
                long long val = roots[i * rStep] * cur[p1 + len] % P;
                nCur[pDest] = cur[p1] + val;
                if (nCur[pDest] >= P)
                    nCur[pDest] -= P;
                nCur[pDest + len] = cur[p1] - val;
                if (nCur[pDest + len] < 0)
                    nCur[pDest + len] += P;
                pDest++, p1++;
            }
            pDest += len;
        }
        cur.swap(nCur);
    }
    return cur;
}

vector<long long> fft_rev(const vector<long long> &as, int P, int G) {
    vector<long long> res = fft(as, P, G);
    long long k = binPow(as.size(), P - 2, P);
    for (int i = 0; i < res.size(); i++)
        res[i] = (res[i] * k) % P;
    reverse(res.begin() + 1, res.end());
    return res;
}

const int MAXM = 1 << 20;

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> v(MAXM);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        v[a] = 1;
    }
    vector<long long> u(MAXM);
    u = v;

    v = fft(v, P1, G1);

    for (int i = 0; i < MAXM; ++i)
        v[i] = binPow(v[i], k, P1);

    v = fft_rev(v, P1, G1);

    u = fft(u, P2, G2);

    for (int i = 0; i < MAXM; ++i)
        u[i] = binPow(u[i], k, P2);

    u = fft_rev(u, P2, G2);

    for (int i = 0; i < MAXM; ++i)
        if (v[i] != 0 || u[i] != 0)
            printf("%d ", i);
    printf("\n");

    cout << endl;
    return 0;
}