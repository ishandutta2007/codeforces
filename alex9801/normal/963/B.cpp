#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
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

int par[200010];
vector<int> chi[200010];

bool chk[200010];
int dep[200010];
vector<int> res;

void f(int x, int d)
{
    int cnt = 0;
    dep[x] = d;
    for(int &y : chi[x])
    {
        f(y, d + 1);

        if(!chk[y])
            cnt++;
    }

    if(par[x] == x)
    {
        if(cnt % 2 == 1)
        {
            printf("NO\n");
            exit(0);
        }
    }
    else
    {
        cnt++;
        if(cnt % 2 == 0)
        {
            chk[x] = 1;
            res.push_back(x);
        }
    }
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, r, i;
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        int p;
        scanf("%d", &p);
        if(p != 0)
        {
            par[i] = p;
            chi[p].push_back(i);
        }
        else
        {
            r = i;
            par[i] = i;
        }
    }
    
    f(r, 0);

    printf("YES\n");
    for(int &x : res)
        printf("%d\n", x);

    vector<pair<int, int>> sor;
    for(i = 1; i <= n; i++)
        if(!chk[i])
            sor.push_back({ dep[i], i });
    sort(sor.begin(), sor.end());

    for(auto &p : sor)
        printf("%d\n", p.second);

    return 0;
}