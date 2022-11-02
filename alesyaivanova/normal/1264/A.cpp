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

const int maxn = 1e6 + 9;
int a[maxn];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        int n;
        cin >> n;
        vector<int> kek;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (i == 0 || a[i] != a[i - 1])
                kek.pb(1);
            else
                kek.back()++;
        }
        int g = kek[0];
        int s = 0, b = 0;
        int i = 1;
        while (i < (int)kek.size() && s <= g)
        {
            s += kek[i];
            i++;
        }
        while (i < (int)kek.size() && g + s + b + kek[i] <= n / 2)
        {
            b += kek[i];
            i++;
        }
        if (g < s && g < b && s + g + b <= n / 2 && g && s && b)
            cout << g << " " << s << " " << b << "\n";
        else
            cout << "0 0 0\n";
    }
}