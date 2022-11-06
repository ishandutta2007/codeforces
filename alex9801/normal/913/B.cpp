#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>

using namespace std;

vector<int> chi[1010];
bool leaf[1010];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, p, i;
    scanf("%d", &n);
    for(i = 2; i <= n; i++)
    {
        scanf("%d", &p);
        chi[p].push_back(i);
    }

    for(i = 1; i <= n; i++)
        if(chi[i].empty())
            leaf[i] = 1;

    for(i = 1; i <= n; i++)
    {
        if(leaf[i])
            continue;

        int r = 0;
        for(auto &c : chi[i])
            if(leaf[c])
                r++;

        if(r < 3)
        {
            printf("No");
            return 0;
        }
    }
    printf("Yes");
    return 0;
}