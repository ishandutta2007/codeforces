#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int p[2] = { 11, 13 };
int ppow[2][1000010];

using hsh = array<int, 2>;

hsh append(const hsh& h, int x)
{
    hsh r;
    for(int b = 0; b < 2; b++)
        r[b] = (1LL * h[b] * p[b] + x) % mod;
    return r;
}
hsh substr(const hsh& h1, const hsh& h2, int l)
{
    hsh r;
    for(int b = 0; b < 2; b++)
        r[b] = (h2[b] + 1LL * (mod - ppow[b][l]) * h1[b]) % mod;
    return r;
}
bool leq(char x[], hsh hx[], char y[], hsh hy[], int l)
{
    int s = 0;
    int g = l;
    while(s < g)
    {
        int m = (s + g + 1) / 2;
        if(substr(hx[0], hx[m], m) == substr(hy[0], hy[m], m))
            s = m;
        else
            g = m - 1;
    }
    return s == l || x[s + 1] <= y[s + 1];
}

char a[1000010];
char l[1000010];
char r[1000010];
hsh ha[1000010];
hsh hl[1000010];
hsh hr[1000010];

int mem[1000010];
int sum[1000010];

int main()
{
    int n, nl, nr;
    scanf("%s%s%s", a + 1, l + 1, r + 1);
    n = strlen(a + 1);
    nl = strlen(l + 1);
    nr = strlen(r + 1);

    for(int b = 0; b < 2; b++)
    {
        ppow[b][0] = 1;
        for(int i = 1; i < 1000010; i++)
            ppow[b][i] = 1LL * ppow[b][i - 1] * p[b] % mod;
    }

    for(int i = 1; i <= n; i++)
        ha[i] = append(ha[i - 1], a[i] - '0');
    for(int i = 1; i <= nl; i++)
        hl[i] = append(hl[i - 1], l[i] - '0');
    for(int i = 1; i <= nr; i++)
        hr[i] = append(hr[i - 1], r[i] - '0');

    mem[0] = 1;
    sum[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        if(i >= nl)
        {
            int x = leq(l, hl, a + (i - nl), ha + (i - nl), nl) ? nl : nl + 1;
            int y = i < nr || leq(a + (i - nr), ha + (i - nr), r, hr, nr) ? min(nr, i) : nr - 1;
            if(x <= y)
            {

                mem[i] = ((x > i ? 0 : sum[i - x]) + (mod - (y >= i ? 0 : sum[i - y - 1]))) % mod;
                if(a[i] == '0' && l[1] == '0')
                    mem[i] = (mem[i] + mem[i - 1]) % mod;
            }
        }

        if(a[i + 1] != '0')
            sum[i] = (sum[i - 1] + mem[i]) % mod;
        else
            sum[i] = sum[i - 1];
    }
    
    printf("%d\n", mem[n]);
    return 0;
}