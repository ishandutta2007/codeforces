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
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int k;
    cin >> k;
    vector<int> a(10, 1);
    int w = 1;
    while (w < k)
    {
        bool fl = 0;
        for (int i = 1; i < 10; i++)
        {
            if (a[i] != a[i - 1])
            {
                w /= a[i];
                a[i]++;
                w *= a[i];
                fl = 1;
                break;
            }
        }
        if (!fl)
        {
            w /= a[0];
            a[0]++;
            w *= a[0];
        }
    }
    string s = "codeforces";
    for (int i = 0; i < 10; i++)
        for (int e = 0; e < a[i]; e++)
            cout << s[i];
}