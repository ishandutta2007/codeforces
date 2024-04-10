#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAX_N = 509;
unordered_map<int, int> m;
unordered_map<int, int> c;
int cnt = 0;
int mod = 998244353;

int gcd(int a, int b)
{
    if (a < b)
    {
        int c = a;
        a = b;
        b = c;
    }
    while (b > 0)
    {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        int b = (int)ceil(powl(a, 0.25));
        if (b * b * b * b > a)
            b--;
        if (b * b * b * b < a)
            b++;
        if (b * b * b * b == a)
        {
            m[b] += 4;
            continue;
        }
        b = (int)ceil(powl(a, 1.0 / 3.0));
        if (b * b * b > a)
            b--;
        if (b * b * b < a)
            b++;
        if (b * b * b == a)
        {
            m[b] += 3;
            continue;
        }
        b = (int)ceil(sqrt(a));
        if (b * b > a)
            b--;
        if (b * b < a)
            b++;
        if (b * b == a)
        {
            m[b] += 2;
            continue;
        }
        c[a]++;
        cnt++;
    }
    for (auto a : c)
    {
        for (auto b : c)
        {
            if (a.first == b.first)
                continue;
            int g = gcd(a.first, b.first);
            if (g >= 2)
            {
                if (m.find(g) == m.end())
                    m.emplace(g, 0);
                if (m.find(a.first / g) == m.end())
                    m.emplace(a.first / g, 0);
                if (m.find(b.first / g) == m.end())
                    m.emplace(b.first / g, 0);
            }
        }
    }
    while (true)
    {
        vector<int> used;
        for (auto a : c)
        {
            for (auto p : m)
            {
                if (a.first % p.first == 0)
                {
                    m[p.first] += a.second;
                    m[a.first / p.first] += a.second;
                    used.push_back(a.first);
                    break;
                }
            }
        }
        if (used.empty())
            break;
        for (auto a : used)
            c.erase(a);
    }
    int ans = 1;
    for (auto a : m)
        ans = (ans * (a.second + 1)) % mod;
    for (auto a : c)
    {
        int b = (int)ceil(sqrt(a.first));
        if (b * b == a.first)
            ans = (ans * (2 * a.second + 1)) % mod;
        else
            ans = (((ans * (a.second + 1)) % mod) * (a.second + 1)) % mod;
    }
    cout << ans << endl;
}