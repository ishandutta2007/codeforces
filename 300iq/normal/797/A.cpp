#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    vector <int> t;
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            t.push_back(i);
            n /= i;
        }
    }
    if (n != 1)
    {
        t.push_back(n);
    }
    while (t.size() > k)
    {
        int a = t.back();
        t.pop_back();
        t.back() *= a;
    }
    if (t.size() < k)
    {
        cout << -1 << '\n';
    }
    else
    {
        for (auto c : t)
        {
            cout << c << ' ';
        }
        cout << '\n';
    }
}