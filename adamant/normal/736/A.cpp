#include <bits/stdc++.h>

using namespace std;

#define int int64_t

signed main()
{
    //freopen("input.txt", "r", stdin);
    cout << fixed << setprecision(2);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int cnt[100];
    cnt[0] = 0;
    cnt[1] = 1;
    if(n == 2)
    {
        cout << 1 << endl;
        return 0;
    }
    if(n == 3)
    {
        cout << 2 << endl;
        return 0;
    }
    int ans = 1;
    for(int i = 2; i < 100; i++)
    {
        cnt[i] = cnt[i - 1] + cnt[i - 2] + 1;
        if(n > cnt[i])
            ans = i;
        else
            break;
    }
    cout << ans << endl;
    return 0;
}