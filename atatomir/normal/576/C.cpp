#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

#define maxN 1000011
#define maxStrip 1024

int n, i;
vector < pair<int, int> > Strip[maxStrip];
pair<int, int> aux;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d",&n);
    for (i = 1; i <= n; i++) {
        scanf("%d%d", &aux.first, &aux.second);
        aux.first /= 1000;
        Strip[aux.first].pb(mp(aux.second, i));
    }

    for (i = 0; i <= 1000; i++) {
        sort(Strip[i].begin(), Strip[i].end());
        if (i & 1) reverse(Strip[i].begin(), Strip[i].end());

        for (auto e : Strip[i]) printf("%d ", e.second);
    }

    return 0;
}