#include <bits/stdc++.h>

using namespace std;

const int N = 200'007;
const int T = 1 << 18;
const int MOD = 1'000'000'007;

int n;
int in[N];
int place[N];
long long tree[2][T + T];

long long newton2(int v)
{
    return 1LL * v * (v + 1) / 2;
}

void update(int t, int p, int v)
{
    p += T;
    while (p) {
        tree[t][p] += v;
        p >>= 1;
    }
}

long long query(int t, int from, int to)
{
    from += T, to += T;

    long long ans = 0;
    while (from <= to) {
        if (from & 1) {
            ans += tree[t][from];
        }

        if (!(to & 1)) {
            ans += tree[t][to];
        }

        from = (from + 1) >> 1;
        to = (to - 1) >> 1;
    }

    return ans;
}

int get(int p)
{
    int cur = 1;
    while (cur < T) {
        cur += cur;
        if (tree[0][cur] < p) {
            p -= tree[0][cur++];
        }
    }

    return cur - T;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &in[i]);
        place[in[i]] = i;
    }

    long long cur = 0;
    for (int i = 1; i <= n; ++i) {
        cur += query(0, place[i], n);

        update(0, place[i], 1);
        update(1, place[i], place[i]);

        long long ans = cur;
        int pos = get((i + 1) / 2);
        int len_bef = (i - 1) / 2;
        int len_aft = i - (i + 1) / 2;

//        printf("%d -> %d %d %d\n", i, pos, len_bef, len_aft);
        ans += 1LL * len_bef * pos - query(1, 1, pos - 1) - newton2(len_bef);
        ans += query(1, pos + 1, n) - 1LL * len_aft * pos - newton2(len_aft);
        printf("%lld%c", ans, " \n"[i == n]);
    }

    return 0;
}