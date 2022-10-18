#include <bits/stdc++.h>

using namespace std;

#define int int64_t

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int ans = 0;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if((a * x1 + b * y1 + c < 0) != (a * x2 + b * y2 + c < 0)) ans++;
    }
    cout << ans << "\n";
}