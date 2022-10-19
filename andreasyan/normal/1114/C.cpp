#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair

long long n, b;

vector<pair<long long, long long> > v;
int main()
{
    cin >> n >> b;
    for (long long i = 2; i * i <= b; ++i)
    {
        if (b % i == 0)
        {
            long long q = 0;
            while (b % i == 0)
            {
                ++q;
                b /= i;
            }
            v.push_back(m_p(i, q));
        }
    }
    if (b > 1)
        v.push_back(m_p(b, 1));

    long long ans = 1000000000000000000;
    for (int i = 0; i < v.size(); ++i)
    {
        long long x = v[i].first;
        long long xx = 1;
        long long q = 0;
        while (1)
        {
            if (xx > 1000000000000000000 / x)
                break;
            xx *= x;
            q += (n / xx);
            if (n / xx == 0)
                break;
        }
        ans = min(ans, q / v[i].second);
    }
    cout << ans << endl;
    return 0;
}