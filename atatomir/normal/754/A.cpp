#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

#define maxN 111

int n, i, j;
int v[maxN];
bool nz;

bool ok[maxN];
int from[maxN];

vector< pair<int, int> > ans;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        if (v[i] != 0) nz = true;
        v[i] += v[i - 1];
    }

    ok[0] = true;
    for (i = 1; i <= n; i++) {
        for (j = 0; j < n; j++) {
            if (ok[j] && v[i] - v[j] != 0) {
                ok[i] = true;
                from[i] = j;
                break;
            }
        }
    }

    if (ok[n] == false) {
        printf("NO\n");
        return 0;
    } else {
        printf("YES\n");
    }


    int act = n;
    while (act != 0) {
        ans.pb(mp(from[act] + 1, act));
        act = from[act];
    }

    printf("%d\n", ans.size());
    sort(ans.begin(), ans.end());
    for (auto e : ans)
        printf("%d %d\n", e.first, e.second);


    return 0;
}