#include <bits/stdc++.h>

using namespace std;

vector<int> c;
vector<vector<int>> e;

const int maxN = 100500;
bool oneColor[maxN];

void dfs(int v, int p = -1)
{
    oneColor[v] = true;
    int theColor = c[v];
    
    for (int u: e[v])
    {
        if (u == p) continue;
        
        dfs(u, v);
        
        if (theColor != c[u])
            oneColor[v] = false;
        
        if (!oneColor[u])
            oneColor[v] = false;
    }
    
    //printf("one color[%d]: %d\n", v + 1, oneColor[v] ? 1 : 0);
}

// -1: root
void ansdfs(int v, int p = -1, int upColor = -1)
{
    vector<pair<int, int>> cColors;
    int nMinusOne = 0;
    for (int u: e[v])
    {
        if (u == p) continue;
        
        if (!oneColor[u])
        {
            cColors.emplace_back(u, -1);
            nMinusOne++;
        }
        else
            cColors.emplace_back(u, c[u]);
    }
    
    if (nMinusOne == 0)
    {
        cout << "YES\n" << v + 1 << endl;
        exit(0);
    }
    
    vector<char> prefOk(cColors.size()), sufOk(cColors.size());
    for (int i = 0; i < (int)cColors.size(); i++)
        prefOk[i] = (i ? prefOk[i - 1] : true) && cColors[i].second != -1 && (!i || cColors[i].second == cColors[i - 1].second);
    
    for (int i = cColors.size() - 1; i >= 0; i--)
        sufOk[i] = (i != (int)cColors.size() - 1 ? sufOk[i + 1] : true) && cColors[i].second != -1 && (i == (int)cColors.size() - 1 || cColors[i].second == cColors[i + 1].second);
    
    for (int i = 0; i < (int)cColors.size(); i++)
        if ((!i || prefOk[i - 1]) && (i + 1 == (int)cColors.size() || sufOk[i + 1]))
        {
            int theColor = -1;
            if (i)
                theColor = cColors[i - 1].second;
            else if (i + 1 != (int)cColors.size())
                theColor = cColors[i + 1].second;
            
            if (theColor != -1 && theColor != c[v]) continue;
            if (upColor != -1 && upColor != c[v]) continue;
            
            ansdfs(cColors[i].first, v, c[v]);
        }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    e.resize(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--; v--;
        
        e[u].push_back(v);
        e[v].push_back(u);
    }
    
    c.resize(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];
    
    dfs(0);
    ansdfs(0);
    
    cout << "NO" << endl;
    
    return 0;
}