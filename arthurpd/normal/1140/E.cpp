#include <bits/stdc++.h>
using namespace std;

#define MAXN 312345
#define MOD 998244353LL

int k;

long long tab[MAXN][2];
bool been[MAXN][2];

long long pd(int n, bool diff)
{
    if (n == 0)
        return diff ? 1 : 0;
    
    if (been[n][diff])
        return tab[n][diff];

    long long retv = 0;
    if (diff)
    {
        retv = (((k - 2) * pd(n - 1, true)) % MOD + pd(n-1, false)) % MOD;
    }
    else
    {
        retv = ((k - 1) * pd(n - 1, true)) % MOD;
    }

    been[n][diff] = true;
    return tab[n][diff] = retv;
}

long long solve(vector<int> a, int n)
{
    long long ans = 1;
    a.insert(a.begin(), 0);
    a.push_back(0);

    vector<int> prev(n + 2, 0);
    vector<int> prox(n + 2, 0);

    for (int i = 1; i <= n; i++)
    {
        prev[i] = a[i-1] > 0 ? i - 1 : prev[i-1];
    }

    prox[n + 1] = n + 1;
    for (int i = n; i > 0; i--)
    {
        prox[i] = a[i + 1] > 0 ? i + 1 : prox[i + 1];
    }

    int l = 1, r = n;
    if (a[1] == -1)
    {
        if (n == 1)
        {
            return k;
        }
        else if (prox[1] == n + 1)
        {
            return (((k * 1ll * (k - 1)) % MOD * pd(n - 2, true)) % MOD + (k * pd(n - 2, false)) % MOD) % MOD;
        }
        else
        {
            ans = (ans * (((k - 1) * pd(prox[1] - 1 - 1, true)) % MOD + pd(prox[1] - 1 - 1, false)) % MOD) % MOD;
            l = prox[1];
        }
    }

    if (a[n] == -1)
    {
        ans = (ans * (((k - 1) * pd(n - prev[n] - 1, true)) % MOD + pd(n - prev[n] - 1, false)) % MOD) % MOD;
        r = prev[n];
    }

    while (l != r)
    {
        ans = (ans * pd(prox[l] - l - 1, a[prox[l]] != a[l])) % MOD;
        l = prox[l];
    }

    return ans;
}

int main(void)
{
    int n, a;
    cin >> n >> k;

    vector<int> odd, even;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a);
        if (i % 2 == 0)
            even.push_back(a);
        else
            odd.push_back(a);
    }

    cout << (solve(even, even.size()) * solve(odd, odd.size())) % MOD << endl;
}