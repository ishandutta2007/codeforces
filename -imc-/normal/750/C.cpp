#include <bits/stdc++.h>

using namespace std;

int main()
{
    const int INF = 1e9;
    
    int minCan = -INF, maxCan = INF;
    
    int n;
    cin >> n;
    
    int delta = 0;
    
    for (int i = 0; i < n; i++)
    {
        int changeBy, division;
        cin >> changeBy >> division;
        
        if (division == 1)
        {
            // x + delta in [1900, +inf)
            
            minCan = max(minCan, 1900 - delta);
        }
        else
        {
            // x + delta in (-inf, 1900)
            maxCan = min(maxCan, 1900 - 1 - delta);
        }
        
        delta += changeBy;
    }
    
    if (minCan > maxCan)
        cout << "Impossible" << endl;
    else if (maxCan == INF)
        cout << "Infinity" << endl;
    else
        cout << maxCan + delta << endl;
    
    return 0;
}