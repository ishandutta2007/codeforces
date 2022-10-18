#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

int div5(int x)
{
    if (x >= 0)
        return x / 5;
    else
        return -(-x / 5);
}

signed main()
{
    int n, k, b, c;
    scanf("%lld %lld %lld %lld", &n, &k, &b, &c);
    
    vector<int> t(n);
    for (int i = 0; i < n; i++)
        scanf("%lld", &t[i]);
    
    b = min(b, 5 * c);
    
    ll answer = 1e18;
    for (int rest = 0; rest < 5; rest++)
    {
        vector<pair<int, int>> aCost(n);
        for (int i = 0; i < n; i++)
        {
            aCost[i].first = t[i];
            int delta = ((rest - t[i]) % 5 + 5) % 5;
            aCost[i].first += delta;
            aCost[i].second += delta * c;
        }
        //for (int i = 0; i < n; i++) printf("(%d %d) ", aCost[i].first, aCost[i].second); printf("\n");
        
        for (int i = 0; i < n; i++)
        {
            int delta = -(aCost[i].first - rest) / 5;
            aCost[i].second += delta * b;
        }
        
        //for (int i = 0; i < n; i++) printf("(%d %d) ", aCost[i].first, aCost[i].second); printf("\n");
        
        sort(aCost.begin(), aCost.end());
        
        multiset<int> minCosts;
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            if ((int)minCosts.size() == k - 1)
            {
                //printf("base level %d\n", div5(aCost[i].first) * k * b);
                //printf("max sum %lld\n", sum);
                
                ll can = (aCost[i].first - rest) / 5 * k * b + sum + aCost[i].second;
                answer = min(answer, can);
            }
            
            minCosts.insert(aCost[i].second);
            sum += aCost[i].second;
            if ((int)minCosts.size() > k - 1)
            {   
                ll minInSet = *prev(minCosts.end());
                sum -= minInSet;
                minCosts.erase(minCosts.find(minInSet));
            }
            
        }
    }
    
    printf("%lld\n", answer);
    
    return 0;
}