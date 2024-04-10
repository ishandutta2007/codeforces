#include <bits/stdc++.h>

using namespace std;

void imp()
{
    cout << "-1\n";
    exit(0);
}

void dec(int& x)
{
    x--;
    if (x < 0) imp();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string answer = "";
    int nTurns = 0;
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> g(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];
    
    int minNum = 1e9;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            minNum = min(g[i][j], minNum);
        
    nTurns += minNum * min(n, m);
    for (int t = 0; t < minNum; t++)
        for (int i = 0; i < min(n, m); i++)
            answer += string(n < m ? "row" : "col") + " " + to_string(i + 1) + "\n";
        
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            g[i][j] -= minNum;
        
    bool ok = false;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (g[i][j] == 0)
            {
                //printf("zero %d %d\n", i, j);
                for (int k = 0; k < n; k++)
                {
                    while (g[k][j] != 0)
                    {
                        for (int t = 0; t < m; t++)
                            dec(g[k][t]);
                        
                        answer += "row " + to_string(k + 1) + "\n";
                        nTurns++;
                    }
                }
                
                for (int k = 0; k < m; k++)
                {
                    while (g[i][k] != 0)
                    {
                        for (int t = 0; t < n; t++)
                            dec(g[t][k]);
                        
                        answer += "col " + to_string(k + 1) + "\n";
                        nTurns++;
                    }
                }
                
                ok = true;
                goto breakAll;
            }
    
    breakAll:;
    assert(ok);
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (g[i][j] != 0)
                imp();
            
    answer = to_string(nTurns) + "\n" + answer;
    cout << answer;
    
    return 0;
}