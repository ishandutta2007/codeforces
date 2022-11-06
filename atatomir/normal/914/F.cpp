#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <bitset>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 100011
#define sigma 26

int n, m, i, q, tp, l, r;
char s[maxN], c, src[maxN];
bitset<maxN> data[sigma], ans, full;

void solve() {
    int i, j, id;

    m = strlen(src + 1);
    ans = full;

    if (r - l + 1 < m) {
        printf("0\n");
        return;
    }

    for (i = 1; i <= m; i++) {
        id = src[i] - 'a';
        ans &= (data[id] >> (i - 1));
    }

    //for (i = 1; i <= n; i++) cerr << data[0][i] << ' ';
    //cerr << '\n';

    int sol = (ans >> l).count() - (ans >> r + 1 - m + 1).count();
    printf("%d\n", sol);
}

int main()
{
    //freopen("test.in","r",stdin);
    //freopen("*.out","w",stdout);

    scanf("%s%d", s + 1, &q);
    n = strlen(s + 1);

    for (i = 1; i <= n; i++)
        data[s[i] - 'a'][i] = 1, full[i] = 1;

    for (i = 1; i <= q; i++) {
        scanf("%d", &tp);

        if (tp == 1) {
            scanf("%d %c", &l, &c);
            data[s[l] - 'a'][l] = 0;
            data[c - 'a'][l] = 1;
            s[l] = c;
        } else {
            scanf("%d%d %s", &l, &r, src + 1);
            solve();
        }
    }


    return 0;
}