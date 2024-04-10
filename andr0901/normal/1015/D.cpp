#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll n, k, s;
    cin >> n >> k >> s;
    if (k > s || k * (n - 1) < s) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    ll t;
    int cur = 1;
    bool b = 0;
    while (k --> 0) {
        t = min(n - 1, s - k);
        if (!b)
            cur += t;
        else
            cur -= t;
        cout << cur << " ";
        s -= t;
        b = !b;
    }
    return 0;
}