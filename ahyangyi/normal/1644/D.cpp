#include <iostream>
#include <vector>

using namespace std;
const int N = 200000;
const int M = 998244353;

int pow(int a, int b)
{
    if (b == 0) return 1;
    if (b == 1) return a;
    int ret = pow(a, b / 2);
    ret = ret * (long long)ret % M;
    if (b % 2 == 1)
    {
        ret = ret * (long long)a % M;
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);

    int ct;
    cin >> ct;
    vector<int> r(N), c(N);
    for (int t = 1; t <= ct; ++t)
    {
        int n, m, k, q;
        cin >> n >> m >> k >> q;
        
        vector<int> x(q), y(q);
        for (int i = 0; i < q; ++i)
        {
            cin >> x[i] >> y[i];
            --x[i];
            --y[i];
        }

        int rc = 0, cc = 0, cnt = 0;
        for (int i = q - 1; i >= 0; --i)
        {
            if (r[x[i]] < t || c[y[i]] < t)
            {
                ++cnt;
            }
            if (r[x[i]] < t)
            {
                ++rc;
                r[x[i]] = t;
            }
            if (c[y[i]] < t)
            {
                ++cc;
                c[y[i]] = t;
            }
            if (rc == n || cc == m)
            {
                break;
            }
        }

        cout << pow(k, cnt) << "\n";
    }

    return 0;
}