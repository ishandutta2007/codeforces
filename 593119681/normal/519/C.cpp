#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 100000 + 5

int n, m, ans;

int main()
{
    scanf("%d%d", &n, &m);
    printf("%d\n", min((n + m) / 3, min(n, m)));

    return 0;
}