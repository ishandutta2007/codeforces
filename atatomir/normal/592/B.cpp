#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

long long n;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%I64d", &n);
    printf("%I64d", (n - 2) * (n - 2));

    return 0;
}