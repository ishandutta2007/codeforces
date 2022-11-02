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
    int b, g, n;
    cin >> b >> g >> n;
    b = min(b, n);
    g = min(g, n);
    cout << abs(g - (n - b)) + 1;
}