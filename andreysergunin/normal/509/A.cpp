#include <bits/stdc++.h>
#define sqr(a) ((a) * (a))

using namespace std;
const int MAXN = 11000;
const int INF = 1000000000;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    long long n, k;
    scanf("%I64d", &n);
    k = 1;
    for (int i = 1; i < n; i++)
        k = k * (n - 1 + i) / i;
    printf("%I64d", k);
}