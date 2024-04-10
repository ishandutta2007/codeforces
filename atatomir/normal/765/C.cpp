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

ll k, a, b;

void no_sol() {
    printf("-1");
    exit(0);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld%lld%lld", &k, &a, &b);

    if ( (a % k != 0) && (b / k == 0) )
        no_sol();

    if ( (b % k != 0) && (a / k == 0) )
        no_sol();

    printf("%lld", (a / k) + (b / k));



    return 0;
}