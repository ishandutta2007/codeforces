#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxN = 1e6 + 100;

int h, w;
vector<int> edgesTo[maxN];

int mode;

int extract(int i)
{
    if (mode == 0)
        return i / w;
    else
        return i % w;
}

char used[maxN];
vector<int> visited;

void dfs(int v)
{
    visited.push_back(v);
    used[v] = true;
    
    for (int u: edgesTo[v])
        if (!used[u])
            dfs(u);
}

int rowMax[maxN], colMax[maxN];
int answer[maxN];

int main()
{
    scanf("%d %d", &h, &w);
    
    vector<pair<int, int>> valueIndex(w * h);
    
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
        {
            scanf("%d", &valueIndex[x + y * w].first);
            valueIndex[x + y * w].second = x + y * w;
        }
    
    for (int t = 0; t < 2; t++)
    {
        mode = t;
        
        // one row go together
        sort(valueIndex.begin(), valueIndex.end(), [](const pair<int, int>& a, const pair<int, int>& b)
        {
            if (a.first != b.first)
                return a.first < b.first;
            
            return extract(a.second) < extract(b.second);
        });
        
        for (int i = 0; i < w * h - 1; i++)
            if (valueIndex[i].first == valueIndex[i + 1].first && extract(valueIndex[i].second) == extract(valueIndex[i + 1].second))
            {
                edgesTo[valueIndex[i].second].push_back(valueIndex[i + 1].second);
                edgesTo[valueIndex[i + 1].second].push_back(valueIndex[i].second);
            }
    }
    
    for (int i = 0; i < w * h; i++)
    {
        int index = valueIndex[i].second;
        
        if (!used[index])
        {
            visited.clear();
            dfs(index);
            
            int minNumber = 0;
            for (int x: visited)
            {
                minNumber = max(minNumber, rowMax[x / w]);
                minNumber = max(minNumber, colMax[x % w]);
            }
            minNumber++;
            
            for (int x: visited)
            {
                answer[x] = minNumber;
                rowMax[x / w] = max(rowMax[x / w], minNumber);
                colMax[x % w] = max(colMax[x % w], minNumber);
            }
        }
    }
    
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            printf("%d ", answer[x + y * w]);
        }
        printf("\n");
    }
    
    return 0;
}