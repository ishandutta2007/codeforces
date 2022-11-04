#include <cstdio>
#include <cstring>
#include <algorithm>
#define M 100010
#define Inf 1000000007
#define mid (L + R >> 1)
#define lc (Now * 2)
#define rc (Now * 2 + 1)

using namespace std;

int n, q;

int Tag[26][M * 8], Sum[26][M * 8], Tot[26], Cnt = 0;

char ch[M];

inline void Read(int& x)
{
    x = 0;
    char ch = getchar();
    while(ch < '0') ch = getchar();
    while(ch >= '0') x = x * 10 + ch - '0', ch = getchar();
}

void I(int Now, int L, int R)
{
    for(int i = 0; i < 26; i++) Tag[i][Now] = -1;
    if(L == R)
        Sum[ch[L] - 'a'][Now] = 1;
    else
    {
        I(lc, L, mid), I(rc, mid + 1, R);
        for(int i = 0; i < 26; i++) Sum[i][Now] = Sum[i][lc] + Sum[i][rc];
    }
}

void Push_Down(int s, int Now, int L, int R)
{
    if(Tag[s][Now] == 0)
        Sum[s][lc] = Sum[s][rc] = Tag[s][lc] = Tag[s][rc] = 0, Tag[s][Now] = -1;
    else if(Tag[s][Now] == 1)
        Sum[s][lc] = mid - L + 1, Sum[s][rc] = R - mid, Tag[s][lc] = Tag[s][rc] = 1, Tag[s][Now] = -1;
}

void O(int Now, int L, int R)
{
    for(int i = 0; i < 26; i++) Push_Down(i, Now, L, R);
    if(L == R)
        for(int i = 0; i < 26; i++)
            if(Sum[i][Now])
            {
                putchar(i + 'a');
                return;
            }
    O(lc, L, mid), O(rc, mid + 1, R);
}

void Delete(int Now, int L, int R, int l, int r)
{
    for(int i = 0; i < 26; i++) Push_Down(i, Now, L, R);
    if(L == l && R == r)
        for(int i = 0; i < 26; i++)
            Sum[i][Now] = Tag[i][Now] = 0;
    else
    {
        if(l <= mid) Delete(lc, L, mid, l, min(r, mid));
        if(r > mid) Delete(rc, mid + 1, R, max(l, mid + 1), r);
        for(int i = 0; i < 26; i++) Sum[i][Now] = Sum[i][lc] + Sum[i][rc];
    }
}

void Insert(int Now, int L, int R, int l, int r, int s)
{
    Push_Down(s, Now, L, R);
    if(L == l && R == r)
        Sum[s][Now] = R - L + 1, Tag[s][Now] = 1;
    else
    {
        if(l <= mid) Insert(lc, L, mid, l, min(r, mid), s);
        if(r > mid) Insert(rc, mid + 1, R, max(l, mid + 1), r, s);
        Sum[s][Now] = Sum[s][lc] + Sum[s][rc];
    }
}

void Query(int Now, int L, int R, int l, int r)
{
    for(int i = 0; i < 26; i++) Push_Down(i, Now, L, R);
    if(L == l && R == r)
        for(int i = 0; i < 26; i++)
            Tot[i] += Sum[i][Now];
    else
    {
        if(l <= mid) Query(lc, L, mid, l, min(r, mid));
        if(r > mid) Query(rc, mid + 1, R, max(l, mid + 1), r);
        for(int i = 0; i < 26; i++) Sum[i][Now] = Sum[i][lc] + Sum[i][rc];
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Read(n), Read(q);
    gets(ch + 1);
    I(1, 1, n);
    for(int i = 1; i <= q; i++)
    {
        int l, r;
        Read(l), Read(r);
        memset(Tot, 0, sizeof Tot);
        Query(1, 1, n, l, r);
        int odd = 0, Who;
        for(int j = 0; j < 26; j++)
            if(Tot[j] & 1) odd++, Who = j;
        if(odd == 0)
        {
            Delete(1, 1, n, l, r);
            for(int j = 0; j < 26; j++)
                if(Tot[j])
                {
                    Insert(1, 1, n, l, l + Tot[j] / 2 - 1, j);
                    Insert(1, 1, n, r - Tot[j] / 2 + 1, r, j);
                    l += Tot[j] / 2;
                    r -= Tot[j] / 2;
                }
        }
        else if(odd == 1)
        {
            Delete(1, 1, n, l, r);
            for(int j = 0; j < 26; j++)
                if(Tot[j])
                {
                    Insert(1, 1, n, l, l + Tot[j] / 2 - 1, j);
                    Insert(1, 1, n, r - Tot[j] / 2 + 1, r, j);
                    l += Tot[j] / 2;
                    r -= Tot[j] / 2;
                }
            Insert(1, 1, n, l, r, Who);
        }
    }
    O(1, 1, n);
    return 0;
}