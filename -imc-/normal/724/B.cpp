#include <bits/stdc++.h>

using namespace std;

void swapCols(vector<vector<int>>& v, int j1, int j2)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
        swap(v[i][j1], v[i][j2]);
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
        
    vector<int> sorted(m);
    for (int i = 0; i < m; i++) sorted[i] = i + 1;
        
    for (int j1 = 0; j1 < m; j1++)
        for (int j2 = j1; j2 < m; j2++)
        {
            swapCols(a, j1, j2);
            
            bool fail = false;
            for (int i = 0; i < n; i++)
            {
                for (int j1 = 0; j1 < m; j1++)
                    for (int j2 = j1; j2 < m; j2++)
                    {
                        bool ok = false;
                        swap(a[i][j1], a[i][j2]);
                        
                        if (a[i] == sorted)
                            ok = true;
                        
                        swap(a[i][j1], a[i][j2]);
                        
                        if (ok)
                            goto breakAll;
                    }
                    
                fail = true;
                break;
                    
                breakAll:;
            }
            
            if (!fail)
            {
                printf("YES\n");
                return 0;
            }
            
            swapCols(a, j1, j2);
        }
    printf("NO\n");
    
    return 0;
}