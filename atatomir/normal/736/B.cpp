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



bool is_prime(ll x) {
    for (ll p = 2; p * p <= x; p++) {
        if (x % p == 0)
            return false;
    }

    return true;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld", &n);

    if (is_prime(n)) {
        printf("1");
        return 0;
    }

    if (n % 2 == 0) {
        printf("2");
    } else {
        if ( is_prime(n - 2) )
            printf("2");
        else
            printf("3");
    }


    return 0;
}