#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair

int n;

int main()
{
    cin >> n;
    int ans = 0;
    int cn = n;
    vector<pair<int, int > > v;
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            int t = 0;
            while (n % i == 0)
            {
                n /= i;
                ++t;
            }
            v.push_back(m_p(i, t));
        }
    }
    if (n > 1)
        v.push_back(m_p(n, 1));
    int maxu = 0;
    for (int i = 0; i < v.size(); ++i)
        maxu = max(maxu, v[i].second);
    int e = 0;
    while ((1 << e) < maxu)
        ++e;
    ans++;
    bool z = true;
    for (int i = 0; i < v.size(); ++i)
        if (v[i].second != (1 << e))
            z = false;
    if (z)
        --ans;
    ans += e;
    int t = 1;
    for (int i = 0; i < v.size(); ++i)
        t *= v[i].first;
    cout << t << ' ' << ans << endl;
    return 0;
}