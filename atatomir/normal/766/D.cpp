#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 200011

int n, m, q, i, tp, id1, id2;
string s, s2;
map<string, int> M;

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

    cin >> n >> m >> q;
    for (i = 1; i <= n; i++) {
        cin >> s;
        M[s] = i;
    }

    for (i = 1; i <= 2 * n; i++) dad[i] = i;
    for (i = 1; i <= m; i++) {
        cin >> tp >> s >> s2;
        id1 = M[s];
        id2 = M[s2];

        if (tp == 1) {
            if (Find(id1) == Find(n + id2)) {
                printf("NO\n");
            } else {
                printf("YES\n");
                Merge(id1, id2);
                Merge(n + id1, n + id2);
            }
        } else {
             if (Find(id1) == Find(id2)) {
                printf("NO\n");
            } else {
                printf("YES\n");
                Merge(id1, n + id2);
                Merge(n + id1, id2);
            }
        }
    }

    for (i = 1; i <= q; i++) {
        cin >> s >> s2;
        id1 = M[s];
        id2 = M[s2];

        if (Find(id1) == Find(id2))
            printf("1\n");
        else
        if (Find(id1) == Find(n + id2))
            printf("2\n");
        else
            printf("3\n");
    }



    return 0;
}