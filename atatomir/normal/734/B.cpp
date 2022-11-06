#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

ll k2, k3, k5, k6;
ll a, b, c;
ll ans;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld%lld%lld%lld", &k2, &k3, &k5, &k6);

    a = k2;
    b = k3;
    c = min(k5, k6);

    c = min(a, c);
    ans += c * 256;
    a -= c;

    ans += min(a, b) * 32;

    printf("%lld", ans);


    return 0;
}