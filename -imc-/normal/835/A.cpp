#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int s;
    int v1, v2, t1, t2;
    cin >> s >> v1 >> v2 >> t1 >> t2;
    
    int delta = 2 * (t2 - t1) + (v2 - v1) * s;
    if (delta < 0)
        cout << "Second\n";
    else if (delta > 0)
        cout << "First\n";
    else
        cout << "Friendship\n";
    
    return 0;
}