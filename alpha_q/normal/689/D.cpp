#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
const int INF = 1e9 + 1000;

int n, t_a[N + N], t_b[N + N];

void init (void) {
    for (int i = n - 1; i; --i) {
        t_a[i] = max(t_a[i << 1], t_a[i << 1 | 1]);
        t_b[i] = min(t_b[i << 1], t_b[i << 1 | 1]);
    }
}

int query_a (int l, int r) {
    int result = -INF; ++r;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) result = max(result, t_a[l++]);
        if (r & 1) result = max(result, t_a[--r]);
    }
    return result;
}

int query_b (int l, int r) {
    int result = INF; ++r;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) result = min(result, t_b[l++]);
        if (r & 1) result = min(result, t_b[--r]);
    }
    return result;
}

int main (int argc, char const *argv[]) {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", t_a + n + i);
    for (int i = 0; i < n; ++i) scanf("%d", t_b + n + i);

    init();

    long long answer = 0;
    for (int i = 0; i < n; ++i) {
        int it = 18, lo = i, hi = n - 1, j_max = -INF, j_min = INF;
        while (it--) {
            int mid = (lo + hi) >> 1;
            int up = query_a(i, mid);
            int down = query_b(i, mid);

            if (up == down) j_max = max(j_max, mid), lo = mid + 1;
            else if (up < down) lo = mid + 1;
            else hi = mid - 1;
        }
        it = 18, lo = i, hi = n - 1;
        while (it--) {
            int mid = (lo + hi) >> 1;
            int up = query_a(i, mid);
            int down = query_b(i, mid);

            if (up == down) j_min = min(j_min, mid), hi = mid - 1;
            else if (up < down) lo = mid + 1;
            else hi = mid - 1;
        }
        answer += (long long) max(0, j_max - j_min + 1);
    }

    printf("%I64d\n", answer);
    return 0;
}