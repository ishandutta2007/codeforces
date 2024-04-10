#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    if (n < 10) return cout << n, 0;
    ll x = n;
    ll ds = 0, s = 0, fd;
    while(x)
    {
        if (x < 10) fd = x;
        s += x%10;
        x /= 10;
        ds++;
    }
    if (s >= fd-1 + (ds-1)*9) return cout << n, 0;
    ll cand = fd;
    for(int i = 1; i < ds; ++i) cand = 10*cand + 9;
    cand--;
    for(ll cr = 1;; cand -= 9*cr, cr *= 10)
    {
        if (cand <= n) return cout << cand, 0;
    }

}