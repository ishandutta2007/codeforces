#include <bits/stdc++.h>

using namespace std;

int cnt(int n)
{
    n--;
    int ans = 1;
    n /= 7;
    while(n > 0)
    {
        ans++;
        n /= 7;
    }
    return ans;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int A = cnt(n);
    int B = cnt(m);
    if(A + B > 7)
    {
        cout << 0 << "\n";
        return 0;
    }
    int ans = 0;
    for(int a = 0; a < n; a++)
        for(int b = 0; b < m; b++)
        {
            int cnt[7];
            memset(cnt, 0, sizeof(cnt));
            int ta = a, tb = b;
            for(int i = 0; i < A; i++)
            {
                cnt[ta % 7]++;
                ta /= 7;
            }
            for(int i = 0; i < B; i++)
            {
                cnt[tb % 7]++;
                tb /= 7;
            }
            if(*max_element(cnt, cnt + 7) == 1)
            {
                ans++;
            }
        }
    cout << ans << "\n";
	return 0;
}