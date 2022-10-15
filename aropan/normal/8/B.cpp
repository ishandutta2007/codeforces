#include<cstdio>
#include<cstring>
/*
#include<climits>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
//*/

#define sqr(x) ((x)*(x))

using namespace std;

const int MAXN = 1111;

int x[MAXN], y[MAXN];
int n;
char s[MAXN];

int main()
{
/*
    freopen(".in", "r", stdin);
    freopen(".out", "w", stdout);
//*/
    gets(s);
    n = strlen(s);
    x[0] = 0;
    y[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        x[i] = x[i - 1];
        y[i] = y[i - 1];
        switch (s[i - 1])
        {
            case 'L': x[i]--; break; 
            case 'R': x[i]++; break; 
            case 'U': y[i]--; break; 
            case 'D': y[i]++; break; 
        }
    }

    for (int i = 0; i <= n; i++)
        for (int j = i + 2; j <= n; j++)
            if (sqr(x[i] - x[j]) + sqr(y[i] - y[j]) <= 1)
            {
                puts("BUG");
                return 0;
            }
    puts("OK");
    return 0;
}