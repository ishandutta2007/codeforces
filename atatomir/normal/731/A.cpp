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

#define maxN 111

int n, i;
char s[maxN];
char act;
int ans, dif;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%s", s + 1);
    n = strlen(s + 1);

    act = 'a';
    for (i = 1; i <= n; i++) {
        dif = s[i] - act;
        if (dif < 0) dif = -dif;

        ans += min(dif, 26 - dif);
        act = s[i];
    }

    printf("%d", ans);


    return 0;
}