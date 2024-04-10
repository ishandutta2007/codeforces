#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <iomanip>
#include <bitset>

using namespace std;

typedef long long ll;

mt19937 rnd(228);

const int N = (1 << 17);
const int M = 1e9 + 7;

inline int add(int a, int b)
{
    a += b;
    if (a >= M) a -= M;
    return a;
}

inline int mul(int a, int b)
{
    return (a * (ll) b) % M;
}

int f[N];
int cnt[N];
int a[N];
int b[N];
int c[N];

void hwft(vector <int> &a)
{
    for (int len = 2; len <= N; len *= 2)
    {
        for (int i = 0; i < N; i += len)
        {
            for (int j = 0; j < len / 2; j++)
            {
                int x = a[i + j];
                int y = a[i + j + len / 2];
                a[i + j] = add(x, y);
                a[i + j + len / 2] = add(x, M - y);
            }
        }
    }
}

inline int bin(int a, int n)
{
    int res = 1;
    while (n)
    {
        if (n % 2 == 0)
        {
            a = mul(a, a);
            n /= 2;
        }
        else
        {
            res = mul(res, a);
            n--;
        }
    }
    return res;
}

void calc_c()
{
    vector <int> a;
    a.resize(N);
    for (int i = 0; i < N; i++) a[i] = cnt[i];
    hwft(a);
    for (int i = 0; i < N; i++)
    {
        a[i] = mul(a[i], a[i]);
    }
    hwft(a);
    int rv = bin(N, M - 2);
    for (int i = 0; i < N; i++)
    {
        c[i] = mul(a[i], rv);
    }
}

void sv(int *a)
{
    for (int len = 2; len <= N; len *= 2)
    {
        for (int i = 0; i < N; i += len)
        {
            for (int j = 0; j < len / 2; j++)
            {
                int x = a[i + j];
                int y = a[i + j + len / 2];
                a[i + j] = add(x, y);
                a[i + j + len / 2] = y;
            }
        }
    }
}

void rev_sv(int *a)
{
    for (int len = 2; len <= N; len *= 2)
    {
        for (int i = 0; i < N; i += len)
        {
            for (int j = 0; j < len / 2; j++)
            {
                int x = a[i + j];
                int y = a[i + j + len / 2];
                a[i + j] = add(x, M - y);
                a[i + j + len / 2] = y;
            }
        }
    }
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i < N; i++)
    {
        f[i] = add(f[i - 1], f[i - 2]);
    }
    int n;
    scanf("%d", &n);
    vector <int> s(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &s[i]);
        cnt[s[i]]++;
    }
    calc_c();
    for (int i = 0; i < N; i++)
    {
        for (int j = i; ; j = (j - 1) & i)
        {
            a[i] = add(a[i], mul(cnt[j], cnt[i ^ j]));
            if (j == 0)
            {
                break;
            }
        }
        a[i] = mul(f[i], a[i]);
        b[i] = mul(f[i], cnt[i]);
        c[i] = mul(f[i], c[i]);
    }
    sv(a);
    sv(b);
    sv(c);
    for (int i = 0; i < N; i++) a[i] = mul(a[i], mul(b[i], c[i]));
    rev_sv(a);
    int ans = 0;
    for (int i = 1; i < N; i++) if ((i & (i - 1)) == 0) ans = add(ans, a[i]);
    printf("%d\n", ans);
}