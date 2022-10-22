#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, h;
    cin >> n >> h;
    
    for (int k = 1; k < n; k++)
        cout << fixed << setprecision(12) << sqrtl(k / (long double)n) * h << ' ';
    cout << endl;
    
    return 0;
}