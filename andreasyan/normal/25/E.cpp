#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 300005;
const int P = 31;
const int M = 1000000009;
const int M1 = 1000001324;

int ast[N];
int ast1[N];
void pre()
{
    ast[0] = 1;
    for (int i = 1; i < N; ++i)
        ast[i] = (ast[i - 1] * 1LL * P) % M;
    ast1[0] = 1;
    for (int i = 1; i < N; ++i)
        ast1[i] = (ast1[i - 1] * 1LL * P) % M1;
}

string a[3];
int b[3];

int pa[N], pb[N];
int pa1[N], pb1[N];
string kpc(string a, string b)
{
    int n = a.size();
    int m = b.size();
    a = "#" + a;
    b = "#" + b;
    for (int i = 1; i <= n; ++i)
        pa[i] = (pa[i - 1] + (a[i] - 'a' + 1) * 1LL * ast[i]) % M;
    for (int i = 1; i <= m; ++i)
        pb[i] = (pb[i - 1] + (b[i] - 'a' + 1) * 1LL * ast[i]) % M;
    for (int i = 1; i <= n; ++i)
        pa1[i] = (pa1[i - 1] + (a[i] - 'a' + 1) * 1LL * ast1[i]) % M1;
    for (int i = 1; i <= m; ++i)
        pb1[i] = (pb1[i - 1] + (b[i] - 'a' + 1) * 1LL * ast1[i]) % M1;
    if (n <= m)
    {
        for (int l = 1; l <= m - n + 1; ++l)
        {
            int r = l + n - 1;
            int ha = pa[n];
            int hb = (pb[r] - pb[l - 1] + M) % M;
            ha = (ha * 1LL * ast[l - 1]) % M;
            int ha1 = pa1[n];
            int hb1 = (pb1[r] - pb1[l - 1] + M1) % M1;
            ha1 = (ha1 * 1LL * ast1[l - 1]) % M1;
            if (ha == hb && ha1 == hb1)
            {
                string ans = "";
                for (int i = 1; i <= m; ++i)
                    ans += b[i];
                return ans;
            }
        }
    }
    else
    {
        for (int l = 1; l <= n - m + 1; ++l)
        {
            int r = l + m - 1;
            int hb = pb[m];
            int ha = (pa[r] - pa[l - 1] + M) % M;
            hb = (hb * 1LL * ast[l - 1]) % M;
            int hb1 = pb1[m];
            int ha1 = (pa1[r] - pa1[l - 1] + M1) % M1;
            hb1 = (hb1 * 1LL * ast1[l - 1]) % M1;
            if (ha == hb && ha1 == hb1)
            {
                string ans = "";
                for (int i = 1; i <= n; ++i)
                    ans += a[i];
                return ans;
            }
        }
    }
    for (int d = min(n, m); d >= 1; --d)
    {
        int ha = (pa[n] - pa[n - d] + M) % M;
        int hb = pb[d];
        hb = (hb * 1LL * ast[n - d]) % M;
        int ha1 = (pa1[n] - pa1[n - d] + M1) % M1;
        int hb1 = pb1[d];
        hb1 = (hb1 * 1LL * ast1[n - d]) % M1;
        if (ha == hb && ha1 == hb1)
        {
            string ans = "";
            for (int i = 1; i <= n - d; ++i)
                ans += a[i];
            for (int i = 1; i <= m; ++i)
                ans += b[i];
            return ans;
        }
    }
    string ans = "";
    for (int i = 1; i <= n; ++i)
        ans += a[i];
    for (int i = 1; i <= m; ++i)
        ans += b[i];
    return ans;
}

int main()
{
    pre();
    for (int i = 0; i < 3; ++i)
    {
        cin >> a[i];
        b[i] = i;
    }
    int ans = N;
    do
    {
        ans = min(ans, (int)kpc(kpc(a[b[0]], a[b[1]]), a[b[2]]).size());
    } while (next_permutation(b, b + 3));
    printf("%d\n", ans);
    return 0;
}
/*
abacaba
baca
c
*/