#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);

long long l, r, k;

void solv()
{
    cin >> l >> r >> k;
    if (r - l + 1 <= 4)
    {
        long long ans = l;
        vector<long long> vans;
        vans.push_back(l);
        for (long long x = 0; x < (1 << (r - l + 1)); ++x)
        {
            long long u = 0;
            vector<long long> v;
            for (long long i = 0; i < 4; ++i)
            {
                if ((x & (1 << i)))
                {
                    v.push_back(l + i);
                    u ^= (l + i);
                }
            }
            if (1 <= v.size() && v.size() <= k)
            {
                if (u < ans)
                {
                    ans = u;
                    vans = v;
                }
            }
        }
        cout << ans << endl;
        cout << vans.size() << endl;
        for (int i = 0; i < vans.size(); ++i)
            cout << vans[i] << ' ';
        cout << endl;
        return;
    }
    if (k == 1)
    {
        cout << l << endl;
        cout << 1 << endl;
        cout << l << endl;
        return;
    }
    if (k == 2)
    {
        cout << 1 << endl;
        if (l % 2 == 0)
        {
            cout << 2 << endl;
            cout << l << ' ' << l + 1 << endl;
        }
        else
        {
            cout << 2 << endl;
            cout << l + 1 << ' ' << l + 2 << endl;
        }
        return;
    }
    if (k >= 4)
    {
        cout << 0 << endl;
        if (l % 2 == 0)
        {
            cout << 4 << endl;
            cout << l << ' ' << l + 1 << ' ' << l + 2 << ' ' << l + 3 << endl;
        }
        else
        {
            cout << 4 << endl;
            cout << l + 1 << ' ' << l + 2 << ' ' << l + 3 << ' ' << l + 4 << endl;
        }
        return;
    }
    for (long long i = 0; i < 58; ++i)
    {
        long long x = (1LL << i) | (1LL << (i + 1));
        long long y = (1LL << (i + 1)) | ((1LL << i) - 1);
        long long z = (1LL << i) | ((1LL << i) - 1);
        if (l <= z && x <= r)
        {
            cout << 0 << endl;
            cout << 3 << endl;
            cout << x << ' ' << y << ' ' << z << endl;
            return;
        }
    }
    cout << 1 << endl;
    if (l % 2 == 0)
    {
        cout << 2 << endl;
        cout << l << ' ' << l + 1 << endl;
    }
    else
    {
        cout << 2 << endl;
        cout << l + 1 << ' ' << l + 2 << endl;
    }
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