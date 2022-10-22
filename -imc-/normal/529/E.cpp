#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>

typedef long long ll;

using namespace std;

int main()
{
#ifdef LOCAL
    freopen("e.in", "r", stdin);
#endif
    
    int n, k;
    scanf("%d %d", &n, &k);
    
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    map<int, vector<int>> sumWith;
    
    for (int i = 0; i < n; i++)
        for (int kk = 1; kk <= k; kk++)
            sumWith[a[i] * kk].push_back(a[i]);
        
    for (auto it: sumWith)
        sort(it.second.begin(), it.second.end());
    
    int nQueries;
    scanf("%d", &nQueries);
    
    for (int qi = 0; qi < nQueries; qi++)
    {
        int q;
        scanf("%d", &q);
        
        int minCan = -1;
        
        for (int i = 0; i < n; i++)
            for (int kk = 1; kk <= k; kk++)
            {
                int rest = q - kk * a[i];
                if (rest < 0) break;
                
                if (rest == 0 && (minCan == -1 || kk < minCan))
                    minCan = kk;
                
                auto it = sumWith.find(rest);
                if (it == sumWith.end()) continue;
                
                vector<int>& ways = it->second;
                for (int x: ways)
                {
                    if (x == a[i]) continue;
                    int can = kk + rest / x;
                    if (can > k) continue;
                    
                    if (minCan == -1 || can < minCan)
                        minCan = can;
                }
                
            }
            
        printf("%d\n", minCan);
    }
    
    return 0;
}