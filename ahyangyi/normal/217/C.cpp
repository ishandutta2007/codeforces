#include <stdio.h>

char str[2000000];

struct Ans
{
    int stat;
    int len;
};

int bxor (int a, int b)
{
    int re = 0;

    for (int i = 0; i < 16; i ++)
        if (a & (1 << i))
            for (int j = 0; j < 16; j ++)
                if (b & (1 << j))
                {
                    re |= (1 << (i ^ j));
                }
    return re;
}

int bor (int a, int b)
{
    int re = 0;

    for (int i = 0; i < 16; i ++)
        if (a & (1 << i))
            for (int j = 0; j < 16; j ++)
                if (b & (1 << j))
                {
                    re |= (1 << (i | j));
                }
    return re;
}

int band (int a, int b)
{
    int re = 0;

    for (int i = 0; i < 16; i ++)
        if (a & (1 << i))
            for (int j = 0; j < 16; j ++)
                if (b & (1 << j))
                {
                    re |= (1 << (i & j));
                }
    return re;
}

bool isok (Ans ans)
{
    if (ans.stat & (1 << (8 + 4 + 2)))
        return true;
    if (ans.stat & (1 << (8 + 4 + 1)))
        return true;
    if (ans.stat & (1 << (8 + 2 + 1)))
        return true;
    if (ans.stat & (1 << (4 + 2 + 1)))
        return true;
    if (ans.stat & (1 << (8 + 4)))
        return true;
    if (ans.stat & (1 << (8 + 2)))
        return true;
    if (ans.stat & (1 << (4 + 1)))
        return true;
    if (ans.stat & (1 << (2 + 1)))
        return true;
    if (ans.stat & (1 << (8)))
        return true;
    if (ans.stat & (1 << (4)))
        return true;
    if (ans.stat & (1 << (2)))
        return true;
    if (ans.stat & (1 << (1)))
        return true;
    return false;
}

Ans getans (int start)
{
    Ans ans;

    if (str[start] == '0')
    {
        ans.stat = (1 << 0);
        ans.len = 1;
        return ans;
    }
    if (str[start] == '1')
    {
        ans.stat = (1 << 15);
        ans.len = 1;
        return ans;
    }
    if (str[start] == '?')
    {
        ans.stat = (1 << (8+2)) + (1 << (8+4));
        ans.len = 1;
        return ans;
    }
    Ans ans1, ans2;
    char op;

    start ++;
    ans1 = getans (start);
    start = start + ans1.len;
    op = str[start ++];
    ans2 = getans (start);
    
    ans.len = ans1.len + ans2.len + 3;
    if (op == '^')
        ans.stat = bxor(ans1.stat, ans2.stat);
    if (op == '&')
        ans.stat = band(ans1.stat, ans2.stat);
    if (op == '|')
        ans.stat = bor(ans1.stat, ans2.stat);

    return ans;
}

int main ()
{
    int n;
    scanf ("%d%s", &n, str);
    printf ("%s\n", isok(getans (0))? "YES": "NO");
    
    return 0;
}