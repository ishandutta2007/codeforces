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

const int maxN = 22;

int n, m, i, j;
pair<int, int> A[maxN], B[maxN];
vector<int> loc, glob;

void comb(pair<int, int> p1, pair<int, int> p2) {
    if (p1.first > p1.second) swap(p1.first, p1.second);
    if (p2.first > p2.second) swap(p2.first, p2.second);

    if (p1 == p2) return;
    if (p1.first == p2.first) loc.pb(p1.first);
    if (p1.second == p2.second) loc.pb(p1.second);
    if (p1.first == p2.second) loc.pb(p1.first);
    if (p1.second == p2.first) loc.pb(p1.second);
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++) scanf("%d%d", &A[i].first, &A[i].second);
    for (i = 1; i <= m; i++) scanf("%d%d", &B[i].first, &B[i].second);

    for (i = 1; i <= n; i++) {
        loc.clear();
        for (j = 1; j <= m; j++)
            comb(A[i], B[j]);

        sort(loc.begin(), loc.end());
        loc.resize(unique(loc.begin(), loc.end()) - loc.begin());

        if (loc.size() > 1) {
            printf("-1");
            return 0;
        }
        for (auto e : loc) glob.pb(e);
    }

    for (i = 1; i <= m; i++) {
        loc.clear();
        for (j = 1; j <= n; j++)
            comb(B[i], A[j]);

        sort(loc.begin(), loc.end());
        loc.resize(unique(loc.begin(), loc.end()) - loc.begin());

        if (loc.size() > 1) {
            printf("-1");
            return 0;
        }
        for (auto e : loc) glob.pb(e);
    }

    sort(glob.begin(), glob.end());
    glob.resize(unique(glob.begin(), glob.end()) - glob.begin());

    if (glob.size() == 1)
        printf("%d", glob[0]);
    else
        printf("0");

    return 0;
}