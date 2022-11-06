#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

#define maxN 200011

int n, i, cnt, bb, ans;
int p[maxN];
int b[maxN];
bool us[maxN];

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &p[i]);
    for (i = 1; i <= n; i++) scanf("%d", &b[i]);

    for (i = 1; i <= n; i++) {
        bb += b[i];
        if (us[i]) continue;

        cnt++;
        for (int node = i; us[node] == false; us[node] = true, node = p[node]);
    }

    ans = 0;
    if (cnt > 1) ans += cnt;
    if (bb % 2 == 0) ans++;


    printf("%d", ans);


    return 0;
}