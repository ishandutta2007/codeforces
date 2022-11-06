#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxQ 200011

struct intr {
    int l1, l2;
    int up, left;

    bool operator<(const intr& who) const {
        return l1 < who.l1;
    }
};

int n, q, i;
int x, y;
set<intr> S;
char dir;
map<int, bool> M;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &q);
    S.insert({1, n, 0, 0});

    for (i = 1; i <= q; i++) {
        scanf("%d%d %c", &x, &y, &dir); swap(x, y);
        if (M[x]) {
            printf("0\n");
            continue;
        }
        M[x] = true;

        auto it = S.lower_bound((intr){x + 1, 0, 0, 0}); it--;
        auto act = *it;
        S.erase(it);

        if (dir == 'U') {
            printf("%d\n", x - act.l1 + 1 + act.up);
            if (x != act.l1)
                S.insert({act.l1, x - 1, act.up, 0});
            if (x != act.l2)
                S.insert({x + 1, act.l2, act.up + (x - act.l1 + 1), act.left});
        } else {
            printf("%d\n", act.l2 - x + 1 + act.left);
            if (x != act.l1)
                S.insert({act.l1, x - 1, act.up, act.left + (act.l2 - x + 1)});
            if (x != act.l2)
                S.insert({x + 1, act.l2, 0, act.left});
        }
    }


    return 0;
}