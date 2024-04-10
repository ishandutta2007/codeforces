#include <bits/stdc++.h>

using namespace std;

#pragma gcc target("sse4")

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) (x).begin(), (x).end()

const int MAXN = 1e5 + 9;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, p;
    cin >> n >> p;
    for (int a = 1; a <= 50; a++)
    {
        int x = n - a * p;
        if (x <= 0)
            continue;
        int t = 0;
        for (int e = 1; e <= x; e *= 2)
        {
            if (e & x)
                t++;
        }
        if (t <= a && a <= x)
        {
            cout << a;
            return 0;
        }
    }
    cout << -1;
}