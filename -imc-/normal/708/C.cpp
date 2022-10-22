#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxN = 500000;
vector<int> e[maxN];

int n;
int fDown[maxN], sizeDown[maxN];
int fUp[maxN], sizeUp[maxN];
vector<int> vchildren[maxN];

int answer[maxN];

void downDfs(int v, int p = -1)
{
    sizeDown[v] = 1;
    
    for (int u: e[v])
        if (u != p)
        {
            downDfs(u, v);
            sizeDown[v] += sizeDown[u];
            fDown[v] = max(fDown[v], fDown[u]);
            vchildren[v].push_back(u);
        }
        
    if (sizeDown[v] * 2 <= n)
        fDown[v] = max(fDown[v], sizeDown[v]);
}

void upDfs(int v)
{
    vector<int>& children = vchildren[v];
    int nc = children.size();
    
    vector<int> fd(nc);
    for (int u: children)
        fd.push_back(fDown[u]);
    
    vector<int> prefMax(nc), sufMax(nc);
    
    if (nc > 0)
    {
        prefMax[0] = fDown[children[0]];
        sufMax[nc - 1] = fDown[children[nc - 1]];
    }
    for (int i = 1; i < nc; i++)
        prefMax[i] = max(prefMax[i - 1], fDown[children[i]]);
    for (int i = nc - 2; i >= 0; i--)
        sufMax[i] = max(sufMax[i + 1], fDown[children[i]]);
    
    bool fail = false, broken = false;
    
    for (int i = 0; i < nc; i++)
    {
        int u = children[i];
        fUp[u] = max(fUp[u], fUp[v]);
        if (i)
            fUp[u] = max(fUp[u], prefMax[i - 1]);
        if (i + 1 < nc)
            fUp[u] = max(fUp[u], sufMax[i + 1]);
        
        if ((n - sizeDown[u]) * 2 <= n)
            fUp[u] = max(fUp[u], n - sizeDown[u]);
        
        sizeUp[u] = n - sizeDown[u];
        upDfs(u);
        
        if (sizeDown[u] * 2 > n)
        {
            if (broken)
            {
                fail = true;
            }
            else
            {
                broken = true;
                if (!((sizeDown[u] - fDown[u]) * 2 <= n))
                    fail = true;
            }
        }
    }
    
    if (sizeUp[v] * 2 > n)
    {
        if (broken)
        {
            fail = true;
        }
        else
        {
            broken = true;
            if (!((sizeUp[v] - fUp[v]) * 2 <= n))
                fail = true;
        }
    }
    
    answer[v] = fail ? 0 : 1;
}

int main()
{
    scanf("%d", &n);
    
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        
        e[u].push_back(v);
        e[v].push_back(u);
    }
    
    downDfs(0);
    upDfs(0);
    
    //for (int i = 0; i < n; i++)
    //    printf("vertex %d: size down %d, size up %d, f down %d, f up %d\n", i + 1, sizeDown[i], sizeUp[i], fDown[i], fUp[i]);
    
    for (int i = 0; i < n; i++)
        printf("%d ", answer[i]);
    printf("\n");
    
    return 0;
}