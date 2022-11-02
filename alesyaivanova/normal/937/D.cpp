#include <iostream>
#include <vector>

using namespace std;
bool j = false;
vector<int> ans;
int n;

bool dfs(int v, vector<vector<int> >& g, vector<int>& used)
{
    used[v] = 1;
    for (int e = 0; e < (int) g[v].size(); e++)
    {
        if (used[g[v][e]] == 1)
        {
            used[v] = 2;
            return true;
        }
        if (!used[g[v][e]])
        {
            bool t = dfs(g[v][e], g, used);
            if (t)
            {
                used[v] = 2;
                return true;
            }
        }
    }
    used[v] = 2;
    return false;
}

void dfs1(int v, vector<vector<int> >& g, vector<bool>& used, int k)
{
    used[v + (k - 1) * n] = true;
    if (j)
    {
        ans.push_back(v + 1);
        return;
    }
    if (g[v].size() == 0 && k == 2)
    {
        j = true;
        ans.push_back(v + 1);
        return;
    }
    for (int e = 0; e < (int) g[v].size(); e++)
    {
        if (!used[g[v][e] + (2 - k) * n])
        {
            dfs1(g[v][e], g, used, 3 - k);
            if (j)
            {
                ans.push_back(v + 1);
                return;
            }
        }
    }
}

int main()
{
    int m;
    cin >> n >> m;
    vector<vector<int> > g(n);
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        g[i].resize(c);
        for (int e = 0 ; e < c; e++)
        {
            cin >> g[i][e];
            g[i][e]--;
        }
    }
    int s;
    cin >> s;
    s--;
    vector<int> used(n, 0);
    bool k = dfs(s, g, used);
    vector<bool> used1(2 * n, 0);
    dfs1(s, g, used1, 1);
    if (j)
    {
        cout << "Win\n";
        for (int i = (int)ans.size() - 1; i >= 0; i--)
            cout << ans[i] << " ";
        return 0;
    }
    if (k)
        cout << "Draw";
    else
        cout << "Lose";
}