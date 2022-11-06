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

int n, k, i, dim, need, fr, la;
char s[maxN];
vector<int> v;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d\n", &n, &k);
    for (i = 1; i <= n; i++) {
        memset(s, 0, sizeof(s));
        scanf("%s\n", s + 1);
        v.pb(strlen(s + 1));
    }

    memset(s, 0, sizeof(s));
    scanf("%s\n", s + 1);
    need = strlen(s + 1);

    sort(v.begin(), v.end());

    for (i = 0; i < v.size(); i++) {
        if (v[i] != need) continue;

        if (fr == 0) fr = i + 1;
        la = i + 1;
    }

    int ans = fr + ((fr - 1) / k) * 5;
    printf("%d ", ans);

    ans = la + ((la - 1) / k) * 5;
    printf("%d\n", ans);

    return 0;
}