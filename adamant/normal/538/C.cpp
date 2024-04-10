#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int pd = 0, ph = 0;
    int d, h;
    cin >> d >> h;
    int ans = h + d - 1;
    ph = h, pd = d;
    while(--m)
    {
        cin >> d >> h;
        if(d - pd < abs(h - ph))
        {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        ans = max(ans, max(h, ph) + (d - pd - abs(h - ph)) / 2);
        ph = h, pd = d;
    }
    cout << max(ans, ph + (n - pd)) << "\n";
}