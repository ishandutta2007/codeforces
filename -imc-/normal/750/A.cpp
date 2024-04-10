#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    
    int maxCan = 0;
    int needTime = 0;
    for (int nSolve = 1; nSolve <= n; nSolve++)
    {
        needTime += nSolve * 5;
        
        if (needTime + k <= 4 * 60)
            maxCan = nSolve;
    }
    
    cout << maxCan << endl;
    
    return 0;
}