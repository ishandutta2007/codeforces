#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fc first
#define sc second
#define ll long long
#define forn(i, n) for (int i = 0; i < (int) (n); i++)
#define fort(i, j, n) for (int i = j; i < (int) (n); i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define bit(x) __builtin_popcount(x)

const int MAXN = (int) 2e5 + 7;

int it = 0;
int n;
int cur[MAXN];
int a[MAXN];
set <int> t;

void push(int who, int x) {
    if (!t.count(who)) {
        auto it = t.lower_bound(who);
        if (it != t.end()) push(*it, x);
        return;
    }
    if (x == 0) return;
    else {
        int need = a[who] - cur[who];
        if (x < need) {
            cur[who] += x;
            return;
        } else {
            cur[who] = a[who];
            int v = x - need;
            t.erase(who);
            auto it = t.lower_bound(who);
            if (it == t.end()) return;
            push(*it, v);
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        t.insert(i);
    }
    int m;
    scanf("%d", &m);
    while (m--) {
        int t, p, x;
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d%d", &p, &x);
            p--;
            push(p, x);
        } else {
            scanf("%d", &p);
            p--;
            printf("%d\n", cur[p]);
        }
    }
}