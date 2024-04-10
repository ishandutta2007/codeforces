#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb emplace_back
#define pf emplace_front
#define ff first
#define ss second
#define pii pair<int, int>
#define mp make_pair

int inf = 1e18;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    for (int j = 0; j < q; j++)
    {
        int a, b, m;
        cin >> a >> b >> m;
        if (a > b)
        {
            cout << "-1\n";
            continue;
        }
        if (a == b)
        {
            cout << "1 " << a << "\n";
            continue;
        }
        bool u = false;
        for (int k = 2; k <= 50; k++)
        {
            int x = b - a * (1ll << (k - 2));
            int y = (1ll << (k - 2));
            if (x < y)
                break;
            if (x > y * m)
                continue;
            int t = x / y;
            int mod = x - t * y;
            cout << k << " " << a << " ";
            int cur = 0;
            int pr = 0;
            for (int i = 1; i < k; i++)
            {
                cur *= 2;
                cur += pr;
                pr = t;
                if ((mod != 0 && i == k - 1) || (i != k - 1 && mod != 0 && ((mod - 1) & (1ll << (k - i - 2)))))
                    pr++;
                cout << a * (1ll << (i - 1)) + cur + pr << " ";
            }
            cout << "\n";
            u = true;
            break;
        }
        if (!u)
            cout << "-1\n";
    }
}