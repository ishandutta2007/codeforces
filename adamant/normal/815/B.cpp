#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int m = 1e9 + 7;

int bpow(int x, int n)
{
    if(n == 0)
        return 1;
    if(n % 2 == 0)
        return bpow(x * x % m, n / 2);
    else
        return x * bpow(x, n - 1) % m;
}

const int maxn = 1e6;
int fact[maxn], rfact[maxn];

int nCr(int n, int r)
{
    return fact[n] * rfact[r] % m * rfact[n - r] % m;
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    fact[0] = rfact[0] = 1;
    for(int i = 1; i < maxn; i++)
    {
        fact[i] = fact[i - 1] * i % m;
        rfact[i] = bpow(fact[i], m - 2);
    }
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &it: a)
        cin >> it;
    bool st = 1;
    while(a.size() % 4 != 1)
    {
        for(int i = 0; i + 1 < a.size(); i++)
        {
            a[i] += st ? a[i + 1] : m - a[i + 1];
            a[i] %= m;
            st ^= 1;
        }
        a.pop_back();
    }
    int ans = 0;
    for(int i = 0; i < a.size(); i += 2)
    {
        ans += nCr(a.size() / 2, i / 2) * a[i] % m;
        ans %= m;
    }
    cout << ans << endl;
    /*bool st = 0;
    vector<int> a[n];
    for(int i = 0; i < n; i++)
    {
        a[i] = vector<int>(n);
        a[i][i] = 1;
    }
    for(int k = n; k > 1; k--)
    {
        for(int i = 0; i + 1 < k; i++)
        {
            for(int j = 0; j < n; j++)
                a[i][j] += st ? a[i + 1][j] : -a[i + 1][j];
            st ^= 1;
        }
    }
    for(auto it: a[0])
        cout << it << ' ';
    cout << endl;*/
}