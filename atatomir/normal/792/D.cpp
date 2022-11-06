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

struct node {
    ll id, l, r;
};

ll n, q, dim, i, act, sz, pos, l, r, mid;
char s[100011];
vector<node> aux;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%lld%lld", &n, &q);
    for (i = 1; i <= q; i++) {
        memset(s, 0, sz + 3);
        scanf("%lld\n%s", &act, s + 1);
        sz = strlen(s + 1);

        aux = {(node){(n + 1) / 2, 1, n}};
        while (aux.back().id != act) {
            l = aux.back().l;
            r = aux.back().r;
            mid = aux.back().id;

            if (act < mid) {
                aux.pb({(l + mid - 1) / 2, l, mid - 1});
            } else {
                aux.pb({(mid + 1 + r) / 2, mid + 1, r});
            }
        }

        for (pos = 1; pos <= sz; pos++) {
            if (s[pos] == 'U') {
                if (aux.size() == 1) continue;
                aux.pop_back();
            }

            if (s[pos] == 'L') {
                l = aux.back().l;
                r = aux.back().r;
                mid = aux.back().id;

                if (l == r) continue;
                aux.pb({(l + mid - 1) / 2, l, mid - 1});
            }

            if (s[pos] == 'R') {
                l = aux.back().l;
                r = aux.back().r;
                mid = aux.back().id;

                if (l == r) continue;
                aux.pb({(r + mid + 1) / 2, mid + 1, r});
            }
        }

        printf("%lld\n", aux.back().id);
    }


    return 0;
}