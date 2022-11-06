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
#include <list>

using namespace std;

long long arr[100010];
list<long long> lis;

vector<long long> sor[60];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, i, j;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%lld", &arr[i]);

    for(i = 0; i < n; i++)
    {
        long long t = arr[i];
        int c = -1;
        while(t)
        {
            c++;
            t >>= 1;
        }

        sor[c].push_back(arr[i]);
    }

    for(i = 59; i >= 0; i--)
    {
        int sz = (int)sor[i].size();
        if(sz == 0)
            continue;

        vector<list<long long>::iterator> tmp;

        for(auto it = lis.begin(); it != lis.end(); it++)
            if((*it) & (1LL << i))
                tmp.push_back(it);

        if(tmp.size() + 1 < sz)
        {
            printf("No\n");
            return 0;
        }
        else if(tmp.size() + 1 == sz)
        {
            for(j = 0; j < sz - 1; j++)
                lis.insert(tmp[j], sor[i][j]);
            lis.push_back(sor[i][sz - 1]);
        }
        else
        {
            for(j = 0; j < sz; j++)
                lis.insert(tmp[j], sor[i][j]);
        }
    }

    printf("Yes\n");
    for(long long t : lis)
        printf("%lld ", t);
    printf("\n");

    return 0;
}