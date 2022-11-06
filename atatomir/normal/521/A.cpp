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

#define maxN 100011
#define mod 1000000007

int n, i, maxi, cnt;
char s[maxN];
int sum[maxN];
ll ans;

int get_id(char c) {
    if (c == 'C') return 1;
    if (c == 'A') return 2;
    if (c == 'G') return 3;
    return 4;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d\n%s", &n, s + 1);
    for (i = 1; i <= n; i++) sum[get_id(s[i])]++;

    maxi = sum[1];
    for (i = 2; i <= 4; i++) maxi = max(maxi, sum[i]);
    for (i = 1; i <= 4; i++) cnt += (maxi == sum[i]);

    ans = 1;
    for (i = 1; i <= n; i++)
        ans = (ans * cnt) % mod;

    printf("%lld", ans);


    return 0;
}