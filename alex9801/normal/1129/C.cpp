#include <bits/stdc++.h>
using namespace std;

namespace SA
{
    const int MAXN = 3010;
    int ord[MAXN], nord[MAXN], cnt[MAXN], aux[MAXN];
    void solve(int n, char *str, int *sfx, int *rev, int *lcp) {
        int p = 1;
        memset(ord, 0, sizeof(ord));
        for(int i = 0; i < n; i++) {
            sfx[i] = i;
            ord[i] = str[i];
        }
        int pnt = 1;
        while(1) {
            memset(cnt, 0, sizeof(cnt));
            for(int i = 0; i < n; i++) cnt[ord[min(i + p, n)]]++;
            for(int i = 1; i <= n || i <= 255; i++) cnt[i] += cnt[i - 1];
            for(int i = n - 1; i >= 0; i--)
                aux[--cnt[ord[min(i + p, n)]]] = i;
            memset(cnt, 0, sizeof(cnt));
            for(int i = 0; i < n; i++) cnt[ord[i]]++;
            for(int i = 1; i <= n || i <= 255; i++) cnt[i] += cnt[i - 1];
            for(int i = n - 1; i >= 0; i--)
                sfx[--cnt[ord[aux[i]]]] = aux[i];
            if(pnt == n) break;
            pnt = 1;
            nord[sfx[0]] = 1;
            for(int i = 1; i < n; i++) {
                if(ord[sfx[i - 1]] != ord[sfx[i]] || ord[sfx[i - 1] + p] != ord[sfx[i] + p]) {
                    pnt++;
                }
                nord[sfx[i]] = pnt;
            }
            memcpy(ord, nord, sizeof(int) * n);
            p *= 2;
        }
        for(int i = 0; i < n; i++) rev[sfx[i]] = i;
        int h = 0;
        for(int i = 0; i < n; i++) {
            if(rev[i]) {
                int prv = sfx[rev[i] - 1];
                while(str[prv + h] == str[i + h]) h++;
                lcp[rev[i]] = h;
            }
            h = max(h - 1, 0);
        }
    }
};

const int mod = 1000000007;

int pre[3010];
bool ill[3010];
int mem[3010][3010];
int arr[3010];

bool vit[3010][3010];
char str[3010];
int sfx[3010];
int rev[3010];
int lcp[3010];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, i, j;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for(i = 0; i < n; i++)
        str[i] = arr[i];

    SA::solve(n, str, sfx, rev, lcp);

    for(i = 0; i < n; i++)
    {
        int l = 1e9;
        int mx = 0;
        for(j = rev[i] - 1; j >= 0; j--)
        {
            l = min(l, lcp[j + 1]);
            if(sfx[j] > i)
                continue;

            mx = max(mx, l);
            break;
        }

        l = 1e9;
        for(j = rev[i] + 1; j < n; j++)
        {
            l = min(l, lcp[j]);
            if(sfx[j] > i)
                continue;

            mx = max(mx, l);
            break;
        }

        mx = min(mx, n - i);
        for(j = 0; j < mx; j++)
            vit[i + j][i] = 1;
    }

    pre[0] = 1;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= 4 && i - j >= 0; j++)
            pre[i] = (pre[i] + pre[i - j]) % mod;

    for(i = 3; i < n; i++)
    {
        if(arr[i - 3] == 0 && arr[i - 2] == 0 && arr[i - 1] == 1 && arr[i] == 1)
            ill[i] = 1;
        if(arr[i - 3] == 0 && arr[i - 2] == 1 && arr[i - 1] == 0 && arr[i] == 1)
            ill[i] = 1;
        if(arr[i - 3] == 1 && arr[i - 2] == 1 && arr[i - 1] == 1 && arr[i] == 0)
            ill[i] = 1;
        if(arr[i - 3] == 1 && arr[i - 2] == 1 && arr[i - 1] == 1 && arr[i] == 1)
            ill[i] = 1;
    }

    int r = 0;
    for(i = 0; i < n; i++)
    {
        for(j = i; j >= 0; j--)
        {
            int len = i - j + 1;

            if(len == 4 && ill[i])
                mem[i][j] = 1;
            else if(len >= 5)
            {
                mem[i][j] = ((mem[i - 1][j] + mem[i - 2][j]) % mod + mem[i - 3][j]) % mod;
                if(ill[i])
                    mem[i][j] = (mem[i][j] + pre[len - 4]) % mod;
                else
                    mem[i][j] = (mem[i][j] + mem[i - 4][j]) % mod;
            }

            if(!vit[i][j])
                r = (r + (pre[len] - mem[i][j] + mod) % mod) % mod;
        }

        printf("%d\n", r);
    }
    return 0;
}