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

#define maxN 200011

int n, a, b, k, i, dim, cnt, j;
char s[maxN];
vector<int> pos;
int possib, need;

vector<int> ans;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d%d\n%s", &n, &a, &b, &k, s + 1);

    pos = {0};
    for (i = 1; i <= n; i++)
        if (s[i] == '1')
            pos.pb(i);
    pos.pb(n + 1);

    for (i = 1; i < pos.size(); i++) {
        dim = pos[i] - pos[i - 1] - 1;
        possib += dim / b;
    }

    need = possib - (a - 1);
    if (need <= 0) {
        printf("0");
        return 0;
    }

    for (i = 1; i < pos.size() && need > 0; i++) {
        dim = pos[i] - pos[i - 1] - 1;
        cnt = min(need, dim / b);
        need -= cnt;

        for (j = 1; j <= cnt; j++)
            ans.pb(pos[i - 1] + b * j);
    }

    printf("%d\n", ans.size());
    for (auto e : ans)
        printf("%d ", e);


    return 0;
}