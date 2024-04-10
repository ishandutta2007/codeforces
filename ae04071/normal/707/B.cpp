#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#include <functional>

int n, m, k;
std::vector<std::pair<int, int>> adj[100001];
bool visited[100001];

int main()
{
    scanf("%d %d %d",&n, &m, &k);
    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        adj[a].push_back(std::make_pair(b,c));
        adj[b].push_back(std::make_pair(a,c));
    }
    
    for(int i = 0; i < k; i++)
    {
        int a;
        scanf("%d",&a);
        visited[a] = true;
    }
    
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> que;
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i]) continue;
        for(auto& it : adj[i])
        {
            if(visited[it.first]) continue;
            que.push(std::make_pair(it.second, it.first));
        }
    }
    
    if(que.empty())
    {
        printf("-1\n");
    }
    else
        printf("%d\n",que.top().first);
    
    return 0;
}