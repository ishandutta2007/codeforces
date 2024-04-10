#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<char> used;
vector<int> answer;
vector<vector<int>> e;

int maxAnswer;

void dfs(int v)
{
    used[v] = true;
    answer[v] = 0;
    for (int u: e[v])
    {
        if (!used[u])
            dfs(u);
        answer[v] = max(answer[v], answer[u] + 1);
    }
    maxAnswer = max(maxAnswer, answer[v]);
}

int n;

bool uniqueAnswer()
{
    maxAnswer = 0;
    used.assign(n, false);
    answer.assign(n, 0);
    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs(i);
        
    //printf("got %d max\n", maxAnswer);
    return maxAnswer == n - 1;
}

vector<pair<int, int>> edges;

bool place(int m)
{
    e.clear();
    e.resize(n);
    
    for (int i = 0; i < m; i++)
        e[edges[i].first].push_back(edges[i].second);
    
    //printf("place %d edges\n", m);
    
    return uniqueAnswer();
}

int main()
{
    int m;
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        
        edges.emplace_back(u, v);
    }
    
    //for (int i = 0; i <= m; i++) printf("%d", place(i)); printf("\n");
    
    if (!place(m))
    {
        printf("-1\n");
        return 0;
    }
    
    int low = 0, high = m;
    while (low + 1 != high)
    {
        int mid = (low + high) / 2;
        if (place(mid))
            high = mid;
        else
            low = mid;
    }
    
    printf("%d\n", low + 1);
    
    return 0;
}