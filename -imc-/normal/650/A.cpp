#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    scanf("%d", &n);
    
    map<int, int> nx, ny;
    map<pair<int, int>, int> nxy;
    
    for (int i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        
        nx[x]++;
        ny[y]++;
        nxy[make_pair(x, y)]++;
    }
    
    ll answer = 0;
    
    for (auto it: nx)
        answer += it.second * (ll)(it.second - 1) / 2;
    
    for (auto it: ny)
        answer += it.second * (ll)(it.second - 1) / 2;
    
    for (auto it: nxy)
        answer -= it.second * (ll)(it.second - 1) / 2;
    
    cout << answer << endl;
    
    return 0;
}