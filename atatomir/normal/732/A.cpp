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

ll k, r;
ll i;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld %lld", &k, &r);
    for (i = 1; i <= 10; i++) {
        ll pay = i * k;

        if (pay % 10 == 0 || pay % 10 == r) {
            printf("%lld", i);
            return 0;
        }
    }



    return 0;
}