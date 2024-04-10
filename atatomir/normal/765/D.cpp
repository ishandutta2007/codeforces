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

int n, i;
int p[maxN];
vector<int> who[maxN];
vector<int> extra;



int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
        who[p[i]].pb(i);
    }

    for (i = 1; i <= n; i++) {
        if (who[i].empty()) continue;

        bool ok = false;
        for (auto e : who[i])
            if (e == i)
                ok = true;

        if (ok == false) {
            printf("-1");
            return 0;
        }

        extra.pb(i);
        for (auto e : who[i])
            p[e] = extra.size();
    }

    printf("%d\n", extra.size());
    for (i = 1; i <= n; i++) printf("%d ", p[i]);
    printf("\n");
    for (auto e : extra) printf("%d ", e);


    return 0;
}