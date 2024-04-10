#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

struct data {
    long long a, b, c, rank;
    bool operator < (const data &d) const {
        if (c == d.c) {
            if (b == d.b) {
                return a < d.a;
            } return b < d.b;
        } return c < d.c;
    }
};

int n, id1 = -1, id2 = -1;
long long tmp[5], maximum = -1;
data d[N];

int main (int argc, char const *argv[]) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld %lld %lld", tmp, tmp + 1, tmp + 2);
        sort(tmp, tmp + 3);
        d[i].a = tmp[0], d[i].b = tmp[1], d[i].c = tmp[2], d[i].rank = i;
        
        if (maximum < tmp[0]) {
            maximum = tmp[0], id1 = i;
        }
    }

    sort(d + 1, d + n + 1);

    for (int i = 1; i < n; ++i) {
        if (d[i].b == d[i + 1].b and d[i].c == d[i + 1].c) {
            long long now_a = d[i].a + d[i + 1].a;
            tmp[0] = now_a, tmp[1] = d[i].b, tmp[2] = d[i].c;
            sort(tmp, tmp + 3);
            if (maximum < tmp[0]) {
                maximum = tmp[0];
                id1 = d[i].rank, id2 = d[i + 1].rank;
            }
        }
    }

    if (id2 == -1) {
        printf("1\n%d\n", id1);
    } else {
        printf("2\n%d %d\n", id1, id2);
    }
    return 0;
}