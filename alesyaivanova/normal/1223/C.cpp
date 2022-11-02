#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double

const int MAXN = 2e5 + 9;
int n, x, a, y, b, k;
int p[MAXN];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    for (int j = 0; j < q; j++)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> p[i];
        sort(p, p + n);
        cin >> x >> a >> y >> b >> k;
        if (x < y)
        {
            swap(a, b);
            swap(x, y);
        }
        int c = a * b / __gcd(a, b);
        int left = 0;
        int right = n + 1;
        while (right - left > 1)
        {
            int mid = (left + right) / 2;
            int c1 = mid / c;
            int a1 = mid / a - c1;
            int b1 = mid / b - c1;
            int cur = 0;
            for (int e = 0; e < c1; e++)
                cur += p[n - 1 - e] * (x + y) / 100;
            for (int e = c1; e < c1 + a1; e++)
                cur += p[n - 1 - e] * x / 100;
            for (int e = c1 + a1; e < c1 + a1 + b1; e++)
                cur += p[n - 1 - e] * y / 100;
            if (cur >= k)
                right = mid;
            else
                left = mid;
        }
        if (left == n)
            cout << "-1\n";
        else
            cout << left + 1 << "\n";
    }
}