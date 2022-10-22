#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int maxN = 100500;

vector<int> loves[maxN];

vector<pair<int, int>> hatePairs;

int color[maxN];

void colorDfs(int v)
{
    for (int u: loves[v])
        if (!color[u])
        {
            color[u] = color[v];
            colorDfs(u);
        }
}

vector<int> hates[maxN];
int colorTwo[maxN];

void colorDfsTwo(int v)
{
    //printf("%d: color %d\n", v, colorTwo[v]);
    
    for (int u: hates[v])
        if (!colorTwo[u])
        {
            colorTwo[u] = 3 - colorTwo[v];
            colorDfsTwo(u);
        }
        else if (colorTwo[u] != 3 - colorTwo[v])
        {
            printf("0\n");
            exit(0);
        }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < m; i++)
    {
        int x, y, type;
        scanf("%d %d %d", &x, &y, &type);
        x--; y--;
        
        if (type == 1)
        {
            loves[x].push_back(y);
            loves[y].push_back(x);
        }
        else
        {
            hatePairs.push_back(make_pair(x, y));
        }
    }
    
    int nColors = 0;
    
    for (int i = 0; i < n; i++)
        if (!color[i])
        {
            nColors++;
            color[i] = nColors;
            colorDfs(i);
        }
        
    for (int i = 0; i < (int)hatePairs.size(); i++)
    {
        int a = hatePairs[i].first, b = hatePairs[i].second;
        
        if (color[a] == color[b])
        {
            printf("0\n");
            return 0;
        }
        
        hates[color[a] - 1].push_back(color[b] - 1);
        hates[color[b] - 1].push_back(color[a] - 1);
        
        //printf("hate pair %d - %d\n", color[a] - 1, color[b] - 1);
    }
    
    int nComponents = 0;
    
    for (int i = 0; i < nColors; i++)
        if (colorTwo[i] == 0)
        {
            colorTwo[i] = 1;
            colorDfsTwo(i);
            nComponents++;
        }
        
    //printf("! %d\n", nComponents);
        
    int answer = 1;
    for (int i = 0; i < nComponents - 1; i++)
    {
        answer *= 2;
        answer %= 1000000007;
    }
    
    printf("%d\n", answer);

    return 0;
}