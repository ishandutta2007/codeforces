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

const int maxN = 333;

int n, nodes, i, j, cnt;
int d[maxN];
vector< pair<int, int> > edges;

int main()
{
//    freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &d[i]);
    nodes = d[n] + 1;

    while (n > 1) {
        cnt = d[1];

        for (i = 1; i <= cnt; i++) {
            for (j = 1; j <= nodes - i; j++) {
                edges.pb(mp(nodes - i + 1, j));
            }
        }

        n--; nodes -= cnt;
        for (i = 1; i <= n; i++) d[i] -= cnt;
        
        for (i = 1; i < n; i++) d[i] = d[i + 1];
        n--;
        nodes = d[n] + 1;
    }

    nodes = d[1] + 1;
    if (n == 1)
        for (i = 1; i <= nodes; i++)
            for (j = i + 1; j <= nodes; j++)
                edges.pb(mp(i, j));

    printf("%d\n", edges.size());
    for (auto e : edges)
        printf("%d %d\n", e.first, e.second);


    return 0;
}