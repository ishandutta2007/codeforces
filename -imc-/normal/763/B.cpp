#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    cout << "YES\n";
    for (int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        cout << (x1 % 2 + 2) % 2 * 2 + (y1 % 2 + 2) % 2 + 1 << '\n';
    }
    
    return 0;
}