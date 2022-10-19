#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);

void solv()
{
    long long n;
    cin >> n;
    if (n % 3 != 0)
    {
        cout << 0 << endl;
        return;
    }
    n /= 3;
    vector<long long> v;
    for (long long i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            v.push_back(i);
            if (i * i != n)
                v.push_back(n / i);
        }
    }
    sort(v.begin(), v.end());
    int ans = 0;
    long double nn = n;
    for (int i = 0; i < v.size(); ++i)
    {
        long long x = v[i];
        if (0.9 > nn / x / x / x)
        {
            break;
        }
        for (int j = i; j < v.size(); ++j)
        {
            long long y = v[j];
            if (0.9 > nn / x / y / y)
            {
                break;
            }
            long long z = n / x;
            if (z % y != 0)
                continue;
            z /= y;
            if (y > z)
                continue;
            long long c = x + y - z;
            if (c % 2 != 0)
                continue;
            c /= 2;
            long long a = x - c;
            long long b = y - c;
            if (a > 0 && b > 0 && c > 0)
            {
                if (a == b && b == c)
                    ++ans;
                else if (a == b || b == c || a == c)
                    ans += 3;
                else
                    ans += 6;
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}