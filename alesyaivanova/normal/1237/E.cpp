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
#define all(x) (x).begin(), (x).end()

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    if (n == 1 || n == 2 || n == 4)
    {
        cout << 1;
        return 0;
    }
    int lg = 0;
    while ((1 << (lg + 1)) - 1 <= n)
        lg++;
    int u = (1 << lg);
    int kek = u - 1;
    for (int t = 4; t <= u; t *= 4)
        kek += u / t;
    if ((n == kek) || (n == kek + 1))
        cout << 1;
    else
        cout << 0;

}