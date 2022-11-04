#include <cstdio>
#include <cstring>
#include <algorithm>
#define M 262144
#define Mid (L + R >> 1)
#define lc (Now * 2)
#define rc (Now * 2 + 1)

using namespace std;

int n, m, k;

char ch[M + 7];

int Seg[M * 2 + 7], Sum[M * 2 + 7][12][12], Lest[M * 2 + 7], Rest[M * 2 + 7];

void Down(int Now, int L, int R)
{
    if(Seg[Now] != -1)
    {
        Seg[lc] = Seg[rc] = Seg[Now];
        memset(Sum[lc], 0, sizeof Sum[lc]);
        memset(Sum[rc], 0, sizeof Sum[rc]);
        Sum[lc][Seg[Now]][Seg[Now]] = Sum[rc][Seg[Now]][Seg[Now]] = R - Mid;
        Lest[lc] = Rest[lc] = Lest[rc] = Rest[rc] = Seg[Now];
        Seg[Now] = -1;
    }
}

void Upd(int Now)
{
    for(int i = 1; i <= k; i++)
        for(int j = 1; j <= k; j++)
            Sum[Now][i][j] = Sum[lc][i][j] + Sum[rc][i][j];
    Lest[Now] = Lest[lc], Rest[Now] = Rest[rc];
    Sum[Now][Rest[lc]][Lest[rc]]++;
}

void Cover(int Now, int L, int R, int l, int r, int Val)
{
    if(L == l && R == r)
    {
        Seg[Now] = Val;
        memset(Sum[Now], 0, sizeof Sum[Now]);
        Sum[Now][Val][Val] = R - L + 1;
        Lest[Now] = Rest[Now] = Val;
        return;
    }
    Down(Now, L, R);
    if(l <= Mid) Cover(lc, L, Mid, l, min(Mid, r), Val);
    if(r > Mid) Cover(rc, Mid + 1, R, max(Mid + 1, l), r, Val);
    Upd(Now);
}
    
int main()
{
    scanf("%d%d%d\n", &n, &m, &k);
    gets(ch + 1);
    ch[n + 1] = 'a' + k;
    memset(Seg, -1, sizeof Seg);
    for(int i = 1; i <= n; i++) Seg[i + M] = Lest[i + M] = Rest[i + M] = ch[i] - 'a' + 1;
    for(int i = M; i >= 1; i--) Upd(i);
    for(int i = 1; i <= m; i++)
    {
        int OP;
        scanf("%d", &OP);
        if(OP == 1)
        {
            int l, r, Val;
            char ch[2];
            scanf("%d%d%s", &l, &r, ch);
            Cover(1, 0, M - 1, l, r, ch[0] - 'a' + 1);
        }
        else
        {
            char ch[12];
            scanf("%s", ch + 1);
            int Ans = n;
            for(int i = 1; i <= k; i++)
                for(int j = i + 1; j <= k; j++)
                    Ans -= Sum[1][ch[i] - 'a' + 1][ch[j] - 'a' + 1];
            printf("%d\n", Ans);
        }
    }
    return 0;
}