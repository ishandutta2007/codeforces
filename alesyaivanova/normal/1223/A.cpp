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



signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int n;
        cin >> n;
        if (n <= 4)
            cout << 4 - n << "\n";
        else
            cout << n % 2 << "\n";
    }
}