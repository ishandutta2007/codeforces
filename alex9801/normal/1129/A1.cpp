#include <bits/stdc++.h>
using namespace std;

vector<int> arr[5010];
int pos[5010][2];
int chk[5010];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, m, i, j;
    scanf("%d%d", &n, &m);
    for(i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        arr[x].push_back(y);
    }

    int mx = 0;
    for(i = 1; i <= n; i++)
        mx = max(mx, (int)arr[i].size());

    if(mx == 1)
    {
        int cnt = 0;
        for(i = 1; i <= n; i++)
            if(arr[i].size())
                cnt++;

        for(i = 1; i <= n; i++)
        {
            int p = i;
            int c = 0;
            int r = -1;
            for(j = 0; j < n && c < cnt; j++)
            {
                if(chk[p])
                {
                    c += chk[p];
                    chk[p] = 0;
                }

                if(arr[p].size() == 1)
                    chk[arr[p][0]]++;

                r++;
                p++;
                if(p == n + 1)
                    p = 1;
            }

            while(c < cnt)
            {
                if(chk[p])
                {
                    c += chk[p];
                    chk[p] = 0;
                }

                r++;
                p++;
                if(p == n + 1)
                    p = 1;
            }

            printf("%d ", r);
        }
        return 0;
    }

    memset(pos, -1, sizeof pos);
    int cnt = 0;
    for(i = 1; i <= n; i++)
    {
        if((int)arr[i].size() < mx - 1)
            continue;

        sort(arr[i].begin(), arr[i].end());

        auto it = lower_bound(arr[i].begin(), arr[i].end(), i);
        if(it == arr[i].end())
            it = arr[i].begin();

        cnt++;
        pos[i][1] = *it;
        
        it++;
        if(it == arr[i].end())
            it = arr[i].begin();

        if((int)arr[i].size() == mx && *it != pos[i][0])
        {
            cnt++;
            pos[i][0] = *it;
        }
        else
        {
            pos[i][0] = pos[i][1];
            pos[i][1] = -1;
        }
    }
    

    for(i = 1; i <= n; i++)
    {
        int p = i;
        int c = 0;
        int r = (mx - 2) * n - 1;
        for(j = 0; j < n && c < cnt; j++)
        {
            if(chk[p])
            {
                c += chk[p];
                chk[p] = 0;
            }

            if(pos[p][0] != -1)
                chk[pos[p][0]]++;

            r++;
            p++;
            if(p == n + 1)
                p = 1;
        }

        for(j = 0; j < n && c < cnt; j++)
        {
            if(chk[p])
            {
                c += chk[p];
                chk[p] = 0;
            }

            if(pos[p][1] != -1)
                chk[pos[p][1]]++;

            r++;
            p++;
            if(p == n + 1)
                p = 1;
        }

        while(c < cnt)
        {
            if(chk[p])
            {
                c += chk[p];
                chk[p] = 0;
            }

            r++;
            p++;
            if(p == n + 1)
                p = 1;
        }

        printf("%d ", r);
    }

    return 0;
}