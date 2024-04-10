#include <bits/stdc++.h>

using namespace std;

#define int int64_t

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int s, x;
    cin >> s >> x;
    if(s - x < 0)
        cout << 0 << "\n";
    else if(((s - x) % 2) == 1)
        cout << 0 << "\n";
    else if((s == x) && (__builtin_popcountll(x) == 1))
        cout << 0 << "\n";
    else if((((s - x) / 2) & x) != 0)
        cout << 0 << "\n";
    else
        cout << (1LL << __builtin_popcountll(x)) - 2 * (s == x) << "\n";
}