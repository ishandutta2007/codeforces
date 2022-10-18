#include <bits/stdc++.h>

using namespace std;

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int p[n];
    int b[n];
    for(int i = 0; i < n; i++)
        cin >> p[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    int ans = 0;
    int used[n];
    fill(used, used + n, 0);
    for(int i = 0; i < n; i++)
    {
        if(!used[i])
        {
            int j = i;
            bool ok = 0;
            while(!used[j])
            {
                used[j] = 1;
                ok |= b[j];
                j = p[j] - 1;
            }
            ans++;
        }
    }
    cout << (ans - (ans == 1)) + (accumulate(b, b + n, 0) % 2 == 0) << endl;
    return 0;
}