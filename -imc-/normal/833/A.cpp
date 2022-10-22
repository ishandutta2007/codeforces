#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

void solve()
{
    int a, b;
    cin >> a >> b;
    
    li cCube = a * (li)b;
    
    li low = 0, high = 1e6 + 100;
    
    while (low + 1 != high)
    {
        li m = (low + high) / 2;
        if (m * m * m > cCube)
            high = m;
        else
            low = m;
    }
    
    if (low * low * low != cCube || a % low != 0 || b % low != 0)
    {
        cout << "No\n";
        return;
    }
    
    cout << "Yes\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int nt;
    cin >> nt;
    
    for (int i = 0; i < nt; i++)
        solve();
    
    return 0;
}