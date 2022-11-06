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

ll a, b, n;
ll i;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld", &n);
    a = 1, b = 2; i = 1;

    while (b <= n - a) {
        i++;
        a += b;
        swap(a, b);
    }

    printf("%lld", i);

    return 0;
}