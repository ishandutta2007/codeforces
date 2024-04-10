#include <bits/stdc++.h>

using namespace std;

const int maxN = 100500;
vector<pair<int, int>> e[maxN];
int n;

pair<int, vector<int>> solve(int finalColor)
{
    vector<int> answer;
    vector<int> d(n, -1);
    
    for (int i = 0; i < n; i++)
    {
        deque<int> bfsQueue;
        if (d[i] == -1)
        {
            d[i] = 0;
            bfsQueue.push_back(i);
        }
        else continue;
        
        vector<int> zeros, ones;
        
        while (!bfsQueue.empty())
        {
            int v = bfsQueue.front();
            bfsQueue.pop_front();
            
            if (d[v] == 0)
                zeros.push_back(v);
            else
                ones.push_back(v);
            
            for (pair<int, int> edge: e[v])
            {
                int c = edge.second == finalColor ? 0 : 1;
                int u = edge.first;
                
                if (d[u] == -1)
                {
                    d[u] = (d[v] + c) % 2;
                    
                    if (c == 0)
                        bfsQueue.push_front(u);
                    else
                        bfsQueue.push_back(u);
                }
                else if (d[u] != (d[v] + c) % 2)
                {
                    //printf("final color %d impossible\n", finalColor);
                    return make_pair(-1, vector<int>());
                }
            }
        }
        
        vector<int>& from = zeros.size() < ones.size() ? zeros : ones;
        copy(from.begin(), from.end(), back_inserter(answer));
    }
    
    //printf("final color %d -> need %d\n", finalColor, (int)answer.size());
    return make_pair(answer.size(), answer);
}

int main()
{
    int m;
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < m; i++)
    {
        int u, v;
        char c;
        scanf("%d %d %c", &u, &v, &c);
        u--; v--;
        
        e[u].emplace_back(v, c == 'R');
        e[v].emplace_back(u, c == 'R');
    }
    
    pair<int, vector<int>> one = solve(0);
    pair<int, vector<int>> two = solve(1);
    
    if (one.first == -1 && two.first == -1)
    {
        printf("-1\n");
        return 0;
    }
    
    auto& ans = (one.first == -1 ? two : (two.first == -1 ? one : (one.first < two.first ? one : two)));
    printf("%d\n", ans.first);
    for (int x: ans.second)
        printf("%d ", x + 1);
    printf("\n");
    
    return 0;
}