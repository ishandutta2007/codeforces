#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 2e5 + 5, INF = 1e9;

struct atom {
    int l1, r1, l2, r2;
    atom (int a = 0, int b = 0, int c = 0, int d = 0) : l1(a), r1(b), l2(c), r2(d) {}
} t[N << 2];

atom merge(atom a, atom b) {
    if (a.l1 == -1 || b.l1 == -1) return atom(-1);
    atom ans;
    if (!a.l1 || !b.l1) {
        ans.l1 = a.l1 | b.l1;
        ans.r1 = a.r1 | b.r1;
    } else if (a.r1 < b.l1) {
        ans.l1 = a.l1;
        ans.r1 = b.r1;
    } else return atom(-1);
    if (!a.l2 || !b.l2) {
        ans.l2 = a.l2 | b.l2;
        ans.r2 = a.r2 | b.r2;
    } else if (a.r2 > b.l2) {
        ans.l2 = a.l2;
        ans.r2 = b.r2;
    } else return atom(-1);
    return ans;
}

int a[N], l[N], r[N], st[N], s[N], mx[N];
int n, top; ll ans;

void build(int u, int l, int r) {
    if (l == r) {
        if (l != 1) {
            if (a[l] > a[l - 1]) t[u] = atom(a[l], a[l], 0, 0);
            else t[u] = atom(0, 0, a[l], a[l]);
        }
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    t[u] = merge(t[u << 1], t[u << 1 | 1]);
}

atom query(int u, int L, int R, int l, int r) {
    if (l <= L && R <= r) return t[u];
    int mid = (L + R) >> 1;
    if (mid >= l && mid + 1 <= r) return merge(query(u << 1, L, mid, l, r), query(u << 1 | 1, mid + 1, R, l, r));
    if (mid >= l) return query(u << 1, L, mid, l, r);
    return query(u << 1 | 1, mid + 1, R, l, r);
}

void addseg(int l, int r, int _) {
    if (_ == 1) {
        l = n - l + 1; r = n - r + 1;
        swap(l, r);
    }
    // fprintf(stderr, "l = %d, r = %d\n", l, r);
    mx[l] = max(mx[l], r);
}

int dp1[N]; // a[i] > a[i + 1]
int dp2[N]; // a[i] < a[i + 1]

int getpos(int i, int val) {
    if (i == 1) return 1;
    int l = 2, r = i - 1, res = i;
    while (l <= r) {
        int mid = (l + r) >> 1;
        atom now = merge(query(1, 1, n, mid, i - 1), atom(a[i], a[i], val, val));
        if (now.l1 != -1 && now.l1 > now.l2) res = mid, r = mid - 1;
        else l = mid + 1;
    }
    atom now = atom(a[i], a[i], val, val);
    if (res != i) now = merge(query(1, 1, n, res, i - 1), now);
    // if (i == 4 && val == -INF) fprintf(stderr, "l1 = %d, l2 = %d\n", now.l1, now.l2);
    if (a[res - 1] < now.l1) {
        int l = 1, r = res - 2, ans = res - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (s[res - 1] - s[mid] == res - 1 - mid) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        if (ans == 1 || a[ans - 1] < now.l2) return ans;
        return dp1[ans - 1];
    } else {
        int l = 1, r = res - 2, ans = res - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (s[res - 1] - s[mid] == 0) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        if (ans == 1 || a[ans - 1] > now.l1) return ans;
        return dp2[ans - 1];
    }
}

int main() {
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]);
    for (int _ = 0; _ <= 1; _++) {
        if (_ == 1) reverse(a + 1, a + n + 1);
        top = 0;
        for (int i = 1; i <= n; i++) {
            while (top && a[st[top]] < a[i]) --top;
            if (top) l[i] = st[top] + 1;
            else l[i] = 1;
            st[++top] = i;
        }
        top = 0;
        for (int i = n; i >= 1; i--) {
            while (top && a[st[top]] < a[i]) --top;
            if (top) r[i] = st[top] - 1;
            else r[i] = n;
            st[++top] = i;
        }
        for (int i = 2; i <= n; i++) s[i] = s[i - 1] + (a[i] > a[i - 1]);
        build(1, 1, n);
        for (int i = 1; i < n; i++) {
            if (a[i] > a[i + 1]) {
                dp1[i] = i;
                int l = 1, r = i - 1, res = i;
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (s[i] - s[mid] == 0) res = mid, r = mid - 1;
                    else l = mid + 1;
                }
                dp1[i] = res;
                if (dp1[i] == 1 || a[dp1[i] - 1] > a[i + 1]) continue;
                dp1[i] = dp2[dp1[i] - 1];
            } else {
                dp2[i] = i;
                int l = 1, r = i - 1, res = i;
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (s[i] - s[mid] == i - mid) res = mid, r = mid - 1;
                    else l = mid + 1;
                }
                dp2[i] = res;
                if (dp2[i] == 1 || a[dp2[i] - 1] < a[i + 1]) continue;
                dp2[i] = dp1[dp2[i] - 1];
            }
        }
        for (int i = 1; i <= n; i++) {
            int l = i + 1, r = ::r[i], res = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (s[mid] - s[i + 1] == 0) res = mid, l = mid + 1;
                else r = mid - 1;
            }
            // fprintf(stderr, "!!!!!!!!!!!!!!! i = %d, _ = %d\n", i, _);
            if (res != -1) addseg(getpos(i, a[i + 1]), res, _);
            addseg(getpos(i, -INF), i, _);
        }
    }
    int maxn = 0;
    for (int i = 1; i <= n; i++) {
        maxn = max(maxn, mx[i]);
        ans += maxn - i + 1;
        // fprintf(stderr, "i = %d, maxn = %d\n", i, maxn);
    }
    print(ans, '\n');
    return 0;
}