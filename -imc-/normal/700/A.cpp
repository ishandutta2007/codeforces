#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    double l, v1, v2;
    
    cin >> n >> l >> v1 >> v2 >> k;
    
    int nGroups = (n + k - 1) / k;
    
    double x = (l / v1) / (1 / v1 + (1 / v2 + (1 - v1 / v2) / (v1 + v2)) * (nGroups - 1));
    double answer = x / v2 + (l - x) / v1;
    
    cout << fixed << setprecision(12) << answer << endl;
    
    //cout << x << endl;
    
    return 0;
}