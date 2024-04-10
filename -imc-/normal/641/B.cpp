#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int a[105][105];

int main()
{
    int n, m, nq;
    cin >> n >> m >> nq;
    
    vector<tuple<int, int, int, int>> q(nq);
    
    for (int i = 0; i < nq; i++)
    {
        cin >> get<0>(q[i]) >> get<1>(q[i]);
        
        if (get<0>(q[i]) == 3) cin >> get<2>(q[i]) >> get<3>(q[i]);
    }
    
    for (int i = nq - 1; i >= 0; i--)
    {
        auto query = q[i];
        
        if (get<0>(query) == 1)
        {
            int y = get<1>(query);
            y--;
            
            int last = a[m - 1][y];
            for (int x = m - 1; x > 0; x--)
                a[x][y] = a[x - 1][y];
            a[0][y] = last;
        }
        else if (get<0>(query) == 2)
        {
            int x = get<1>(query);
            x--;
            
            int last = a[x][n - 1];
            for (int y = n - 1; y > 0; y--)
                a[x][y] = a[x][y - 1];
            a[x][0] = last;
        }
        else
        {
            int y = get<1>(query), x = get<2>(query), val = get<3>(query);
            x--; y--;
            
            a[x][y] = val;
        }
    }
    
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
            printf("%d ", a[x][y]);
        printf("\n");
    }
    
    return 0;
}