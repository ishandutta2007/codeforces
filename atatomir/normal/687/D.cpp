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

#define maxN 2111
#define maxM 1000011

int n, m, q, i, x, y, l, r, last;
pair< pair<int, int>, pair<int, int> > E[maxM];
int dad[maxN];


int Find(int x) {
    if (dad[x] == x) return x;
    dad[x] = Find(dad[x]);
    return dad[x];
}

bool Merge(int x, int y) {
    x = Find(x);
    y = Find(y);

    if (x == y) return false;
    dad[x] = y;
    return true;
}



int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d%d", &n, &m, &q);
    for (i = 1; i <= m; i++) {
        scanf("%d%d%d", &E[i].second.first, &E[i].second.second, &E[i].first.first);
        E[i].first.second = i;
    }

    sort(E + 1, E + m + 1);
    reverse(E + 1, E + m + 1);

    for (int qq = 1; qq <= q; qq++) {
        scanf("%d%d", &l, &r);

        for (i = 1; i <= n; i++) dad[i] = i, dad[n + i] = n + i;

        last = -1;
        for (i = 1; i <= m; i++) {
            if (E[i].first.second < l || E[i].first.second > r) continue;
            x = E[i].second.first;
            y = E[i].second.second;

            Merge(x, n + y);
            Merge(n + x, y);

            if (Find(x) == Find(y)) {
                last = E[i].first.first;
                break;
            }
        }

        printf("%d\n", last);
    }



    return 0;
}