#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, nq, c;
    cin >> n >> nq >> c;
    c++;
    
    const int maxc = 101;
    vector<array<array<int, maxc>, maxc>> m(c);
    
    for (int i = 0; i < n; i++)
    {
        int x, y, s;
        cin >> x >> y >> s;
        m[s][x][y]++;
    }
    
    for (int k = 0; k < c; k++)
        for (int i = 1; i < maxc; i++)
            for (int j = 1; j < maxc; j++)
                m[k][i][j] += m[k][i - 1][j] + m[k][i][j - 1] - m[k][i - 1][j - 1];
            
    for (int i = 0; i < nq; i++)
    {
        int t, x1, y1, x2, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        
        int answer = 0;
        
        for (int dt = 0; dt < c; dt++)
        {
            int count = m[dt][x2][y2] - m[dt][x1 - 1][y2] - m[dt][x2][y1 - 1] + m[dt][x1 - 1][y1 - 1];
            //printf("jar %d count %d\n", (dt + t) % c, count);
            answer += ((dt + t) % c) * count;
        }
        
        cout << answer << '\n';
        //printf("\n");
    }
    
    return 0;
}