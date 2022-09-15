#include<bits/stdc++.h>
using namespace std;

int arr[200010];
int res[200010];
vector<int> vec[200010];
int cur[200010];

int main()
{
    int n, m, i, j, k;
    int sum = 0;
    scanf("%d%d", &n, &m);
    for(i=1;i<=n;i++)
    {
        scanf("%d", &arr[i]);
        vec[arr[i]].push_back(i);
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d", &res[i]);
        sum += res[i];
    }
    
    set<int> ss;
    
    int ans = n;
    
    for(i=1;i<=m;i++)
    {
        if(res[i] == 0)
            continue;
        
        if(vec[i].size() < res[i])
        {
            printf("-1\n");
            return 0;
        }
        
        cur[i] = res[i] - 1;
        ss.insert(vec[i][cur[i]]);
    }
    
    ans = min(ans, *prev(ss.end()) - sum);
    
    for(i=2;i<=n;i++)
    {
        int t = arr[i - 1];
        
        if(res[t] != 0)
        {
            if(cur[t] + 1 == vec[t].size())
                break;
            
            ss.erase(vec[t][cur[t]]);
            cur[t]++;
            ss.insert(vec[t][cur[t]]);
        }
        
        ans = min(ans, *prev(ss.end()) - sum - i + 1);
    }
    printf("%d\n", ans);
    return 0;
}