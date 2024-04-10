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

bool chk[100];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    bool u;
    int h, m, s, t1, t2, x, i;
    scanf("%d%d%d%d%d", &h, &m, &s, &t1, &t2);

    h %= 12;
    t1 %= 12;
    t2 %= 12;

    chk[h] = 1;
    chk[m / 5] = 1;
    chk[s / 5] = 1;

    u = 1;
    for(i = t1; i != t2; i = (i + 1) % 12)
    {
        if(chk[i])
        {
            u = 0;
            break;
        }
    }
    if(u)
    {
        printf("YES");
        return 0;
    }

    u = 1;
    for(i = t2; i != t1; i = (i + 1) % 12)
    {
        if(chk[i])
        {
            u = 0;
            break;
        }
    }
    if(u)
    {
        printf("YES");
        return 0;
    }

    printf("NO");
    return 0;
}