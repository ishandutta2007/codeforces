#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstdlib>

using namespace std;

typedef long long ll;
typedef long double ld;

ll a[1000000];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, d;
    ll s = 0;
    cin >> n >> d;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        s += a[i];
    }
    if(10 * (n - 1) > d - s)
    {
        cout << -1;
        return 0;
    }
    else
    {
        cout << (d - s) / 5;
    }
    return 0;
}