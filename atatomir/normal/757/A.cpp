#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

#define maxN 100011

int n, i;
char s[maxN];
int cnt[1111];

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%s", s + 1);
    n = strlen(s + 1);

    for (i = 1; i <= n; i++) cnt[s[i]]++;

    int ans = min(cnt['B'], cnt['u'] / 2);
    ans = min(ans, cnt['l']);
    ans = min(ans, cnt['b']);
    ans = min(ans, cnt['a'] / 2);
    ans = min(ans, cnt['s']);
    ans = min(ans, cnt['r']);

    printf("%d", ans);


    return 0;
}