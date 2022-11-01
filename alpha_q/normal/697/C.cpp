#include <bits/stdc++.h>

using namespace std;

map <long long, long long> M;
int q, id;
long long u, v, w, ans;
map <long long, int> two;

void update (void) {
    while (u != v) {
        if (u > v) swap(u, v);
        M[v] += w;
        v >>= 1;
    }
}

long long query (void) {
    long long ans = 0;
    while (u != v) {
        if (u > v) swap(u, v);
        ans += M[v];
        v >>= 1;
    }
    return ans;
}

int main (int argc, char const *argv[]) {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    for (long long i = 0; i < 64; ++i) {
        two[1LL << i] = (int) i;
    }

    scanf("%d", &q); while (q--) {
        scanf("%d", &id);
        if (id == 1) {
            scanf("%I64d %I64d %I64d", &u, &v, &w);
            update();
        } else {
            scanf("%I64d %I64d", &u, &v);
            printf("%I64d\n", query());
        }
    }
    return 0;
}