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

ll n;

int main()
{
    scanf("%lld", &n);
    if (n == 1) {
        printf("-1");
        return 0;
    }

    printf("%lld %lld %lld", n, n + 1, n * (n + 1));



    return 0;
}