#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll w[300000];
ll h[300000];

int main()
{
    ll n, max1 = -1, max2 = -1, sm = 0, pos1, pos2;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> w[i] >> h[i];
        sm += w[i];
        if (max1 < h[i])
            max2 = max1, max1 = h[i], pos2 = pos1, pos1 = i;
        else if (max2 < h[i])
            max2 = h[i], pos2 = i;
    }
    for (ll i = 0; i < n; i++)
    {
        if (i != pos1)
            cout << max1 * (sm - w[i]) << " ";
        else
            cout << max2 * (sm - w[i]) << " ";
    }
}