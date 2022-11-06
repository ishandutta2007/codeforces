#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
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
#include <iterator>

using namespace std;

char buf[10];
const int mod = 1000000007;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, i;
    scanf("%d", &n);

    int r = 1;
    set<int> sell, buy, tot;

    for(i = 0; i < n; i++)
    {
        int p;
        scanf("%s%d", buf, &p);

        if(buf[1] == 'D')
        {
            tot.insert(p);
            if(!sell.empty() && p > *sell.begin())
                sell.insert(p);
            if(!buy.empty() && p < *prev(buy.end()))
                buy.insert(p);
        }
        else
        {
            tot.erase(p);
            bool found = 0;

            if(!sell.empty())
            {
                auto it = sell.find(p);
                if(it != sell.end())
                {
                    found = 1;

                    if(it != sell.begin())
                    {
                        printf("0\n");
                        return 0;
                    }

                    sell.erase(it);
                }
                else
                {
                    if(p > *sell.begin())
                    {
                        printf("0\n");
                        return 0;
                    }
                }
            }

            if(!buy.empty())
            {
                auto it = buy.find(p);
                if(it != buy.end())
                {
                    if(found)
                    {
                        printf("0\n");
                        return 0;
                    }

                    found = 1;

                    if(it != prev(buy.end()))
                    {
                        printf("0\n");
                        return 0;
                    }

                    buy.erase(it);
                }
                else
                {
                    if(p < *prev(buy.end()))
                    {
                        printf("0\n");
                        return 0;
                    }
                }
            }

            if(!tot.empty())
            {
                auto it = tot.upper_bound(p);
                if(it != tot.end())
                    sell.insert(*it);
                if(it != tot.begin())
                    buy.insert(*prev(it));
            }

            if(!found)
            {
                r = (r * 2LL) % mod;
            }
        }

        if(!sell.empty() && !buy.empty() && *sell.begin() <= *(prev(buy.end())))
        {
            printf("0\n");
            return 0;
        }
    }

    for(int t : sell)
    {
        if(buy.find(t) != buy.end())
        {
            printf("0\n");
            return 0;
        }
    }

    int c = 1;
    for(int t : tot)
        if((buy.empty() || *(prev(buy.end())) < t) && (sell.empty() || t < *sell.begin()))
            c++;

    r = 1LL * r * c % mod;
    printf("%d\n", r);

    return 0;
}