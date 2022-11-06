#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>

using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    bool u, v;
    char c;
    int n, x, a, b, p, q, r, i;
    scanf("%d", &n);

    a = 0;
    b = 1023;

    for(i = 0; i < n; i++)
    {
        scanf(" %c%d", &c, &x);
        if(c == '&')
        {
            a &= x;
            b &= x;
        }
        else if(c == '|')
        {
            a |= x;
            b |= x;
        }
        else if(c == '^')
        {
            a ^= x;
            b ^= x;
        }
    }

    p = 1023;
    q = 0;
    r = 0;

    for(i = 0; i < 10; i++)
    {
        u = !!(a & (1 << i));
        v = !!(b & (1 << i));
        if(!u && !v)
            p -= 1 << i;
        else if(u && !v)
            r += 1 << i;
        else if(u && v)
            q += 1 << i;
    }

    printf("3\n");
    printf("& %d\n", p);
    printf("| %d\n", q);
    printf("^ %d\n", r);

    return 0;
}