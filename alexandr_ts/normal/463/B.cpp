#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int a[1000000];
int le[1000];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int energy = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        energy += a[i - 1] - a[i];
        if (energy < 0)
        {
            ans += abs(energy);
            energy = 0;
        }
    }
    cout << ans;
    return 0;
}