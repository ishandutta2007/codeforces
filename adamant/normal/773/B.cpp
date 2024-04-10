#include <bits/stdc++.h>

using namespace std;

int get(int k, int n)
{
    if(2 * k > n)
        return 0;
    if(4 * k > n)
        return 1;
    if(8 * k > n)
        return 2;
    if(16 * k > n)
        return 3;
    if(32 * k > n)
        return 4;
    return 5;
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n][5];
    int cost[] = {500, 1000, 1500, 2000, 2500, 3000};
    int cnt[5] = {0};
    for(int i = 0; i < n; i++)
        for(int z = 0; z < 5; z++)
        {
            cin >> a[i][z];
            cnt[z] += a[i][z] >= 0;
        }
    int ans = 1e9 + 8;
    double diff[5];
    for(int z = 0; z < 5; z++)
    {
        diff[z] = (a[0][z] >= 0 ? (1 - a[0][z] / 250.) : 0) -
                  (a[1][z] >= 0 ? (1 - a[1][z] / 250.) : 0);
    }
    int max_mask = 6 * 6 * 6 * 6 * 6;
    for(int mask = 0; mask < max_mask; mask++)
    {
        int ptr[5];
        int t = mask;
        for(int i = 0; i < 5; i++)
        {
            ptr[i] = t % 6;
            t /= 6;
        }
        int total = 0;
        for(int i = 0; i < 5; i++)
            total += round(cost[ptr[i]] * diff[i]);
        if(total > 0)
        {
            int cur = 0;
            for(int i = 0; i < 5; i++)
            {
                int A = cnt[i], B = n, t = 0;
                while(get(A, B) != ptr[i])
                    if(get(A, B) < ptr[i])
                        B++, t++;
                    else
                    {
                        if(a[0][i] == -1)
                            cur = 1e9 + 8;
                        A++, B++, t++;
                    }
                cur = max(cur, t);
            }
            if(cur < 1e9 + 8)
            {

            for(int i = 0; i < 5; i++)
            {
                int A = cnt[i], B = n, t = cur;
                if(t >= 1e9 + 8)
                    break;
                while(t--)
                    if(get(A, B) < ptr[i] || get(A, B + 1) == ptr[i])
                        B++;
                    else
                    {
                        if(a[0][i] == -1)
                            cur = 1e9 + 8;
                        A++, B++;
                    }
                //cur = max(cur, t);
            }

            }
            ans = min(ans, cur);
        }
    }
    if(ans == 1e9 + 8)
        ans = -1;
    cout << ans << endl;
}
/*
k < a/b <= 2*k
(a+1)/(b+1)

a/b-a/(b+1) <= 1/b-1/(b+1)
(a+1)/(b+1)-a/b = [b-a]/(b(b+1)) <= 1/3
*/