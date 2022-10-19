#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const long long INF = 1000000009000000009;

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    long long a, b;
    cin >> a >> b;
    vector<long long> v;
    for (long long i = 1; i * i <= a; ++i)
    {
        if (a % i == 0)
        {
            v.push_back(i);
            if (i * i != a)
                v.push_back(a / i);
        }
    }
    sort(v.begin(), v.end());
    long long ans = 0;
    while (1)
    {
        for (int i = v.size() - 1; i >= 0; --i)
        {
            if (b % v[i] == 0)
            {
                long long minu = INF;
                for (int j = i + 1; j < v.size(); ++j)
                {
                    if (v[j] % v[i] == 0)
                    {
                        if ((b / v[i]) > (v[j] / v[i]))
                        {
                            minu = min(minu, ((b / v[i]) % (v[j] / v[i])));
                        }
                    }
                }
                if (minu == INF)
                {
                    ans += (b / v[i]);
                    cout << ans << endl;
                    return 0;
                }
                ans += minu;
                b -= minu * v[i];
                break;
            }
        }
    }
    return 0;
}