#include <cstdio>
#include <algorithm>
#include <set>
#include <map>

int n, m;
int cost[100001];
std::multimap<int, int>arr;

int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
        scanf("%d",&cost[i]);
    
    std::sort(cost, cost + n);
    for(int i = 0; i < n; i++)
    {
        arr.insert(std::make_pair(cost[i], i));
    }
    
    scanf("%d",&m);
    for(int i = 0; i < m; i++)
    {
        int num;
        scanf("%d",&num);
        std::map<int,int>::iterator it = arr.upper_bound(num);
        if(it == arr.end()) printf("%d\n", n);
        else printf("%d\n",it->second);
    }
    
    
    return 0;
}