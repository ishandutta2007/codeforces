#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

#define maxN 55

int n, i, j;
int x;
int maxi[maxN];
vector< pair<int, int> > aux;
int ans[maxN];

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        maxi[i] = 0;
        for (j = 1; j <= n; j++) {
            scanf("%d", &x);
            maxi[i] = max(maxi[i], x);
        }
        aux.pb(mp(maxi[i], i));
    }

    sort(aux.begin(), aux.end());
    for (i = 0; i < aux.size(); i++)
        ans[ aux[i].second ] = i + 1;


    for (i = 1; i <= n; i++)
        printf("%d ", ans[i]);

    return 0;
}