#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef long long ll;
typedef double ld;

int a[1000][1000];

int main()
{
    ld a;
    ld d;
    ll n;
    cin >> a >> d;
    cin >> n;
    ld dist = 0;
    for(int i = 0; i < n; i++)
    {
        dist += d;
        /*ll dist1 = (ll)(dist * 100000000);
        ll a1 = (ll)(a * 100000000);
        dist1 %= (4 * a1);
        dist = (ld)dist1 / 100000000;*/
        ll t1 = dist / (4 * a);
        dist -= t1 * 4 * a;
        if(dist <= a)
        {
            printf("%.6lf 0.000000\n", dist);
        }
        else if(dist <= 2 * a)
        {
            printf("%.6lf %.6lf\n", a, dist - a);
        }
        else if(dist <= 3 * a)
        {
            printf("%.6lf %.6lf\n", 3 * a - dist, a);
        }
        else
        {
            printf("0.000000 %.6lf\n", 4 * a - dist);
        }
    }
    return 0;
}