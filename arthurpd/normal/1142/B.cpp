#include <bits/stdc++.h>
using namespace std;

#define MAXN 212345
#define inf 0x3f3f3f3f

int p[MAXN];
int rev[MAXN];
int a[MAXN];
int prox[MAXN];
int next_idx[21][MAXN];
int cnt[MAXN];
int val[21][MAXN];

int main(void)
{
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < n; rev[p[i]] = i, i++)
        scanf("%d", &p[i]);
    
    for (int i = 0; i < m; i++)
        scanf("%d", &a[i]);

    for (int i = m - 1; i >= 0; i--)
    {
        int j = prox[p[(rev[a[i]] + 1) % n]];
        if (j != 0)
        {
            cnt[i] = cnt[j] + 1;
            next_idx[0][i] = j;
        }
        else
        {
            cnt[i] = 0;
            next_idx[0][i] = i;
        }

        prox[a[i]] = i;
    }


    for (int i = 1; i <= 20; i++)
        for (int j = 0; j < m; j++)
            next_idx[i][j] = next_idx[i - 1][next_idx[i - 1][j]];

    for (int i = 0; i < m; i++)
    {
        int perm_end = i;
        for (int j = 20; j >= 0; j--)
            if (cnt[next_idx[j][perm_end]] >= cnt[i] - n + 1)
                perm_end = next_idx[j][perm_end];
        
        if (cnt[perm_end] == cnt[i] - n + 1)
            val[0][i] = perm_end;
        else
        {
            val[0][i] = inf;
        }
    }


/*    for (int i = 0; i < m; i++)
    {
        cout << next_idx[0][i] << " " << cnt[i] << " " << val[0][i] << endl;
    }

    cout << endl;
*/
    for (int i = 1; i <= 20; i++)
        for (int j = 0; j < m; j++)
            val[i][j] = min(val[i-1][j], val[i-1][min(m - 1, j + (1 << (i - 1)))]);

    for (int i = 0; i < q; i++)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        l--;
        r--;

        int j = 0;
        while ((1 << (j + 1)) <= r - l + 1)
            j++;
        
        int res = 0;
        res = min(val[j][l], val[j][r - (1 << j) + 1]);
        if (res > r)
            printf("0");
        else
        {
            printf("1");
        }
        
    }
    printf("\n");
}