#include <bits/stdc++.h>
using namespace std;
const int N = 200005;

int n;

map<int, int> xx, yy;
map<int, map<int, int> > mp;

int main()
{
    long long ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        ans += xx[x];
        ans += yy[y];
        ans -= mp[x][y];
        xx[x]++;
        yy[y]++;
        mp[x][y]++;
    }
    cout << ans << endl;
    return 0;
}