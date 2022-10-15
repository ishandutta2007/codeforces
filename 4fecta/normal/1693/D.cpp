#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 200005;

int n, a[MN], ans, rit[MN];

int get(int i) {
    stack<int> inc, dec;
    inc.push(0), dec.push(n + 1);
    for (int j = i; j <= n; j++) {
        if (inc.size() > 1 && a[j] < inc.top() && inc.top() < dec.top()) dec.push(inc.top()), inc.pop();
        if (a[j] > inc.top()) {inc.push(a[j]); continue;}
        if (a[j] < dec.top()) {dec.push(a[j]); continue;}
        return j - 1;
    }
    return n;
}

void solve(int l, int r) {
    if (l + 1 >= r) return;
    if (rit[l] == rit[r]) {
        for (int i = l; i <= r; i++) rit[i] = rit[l];
        return;
    }
    int mid = (l + r) >> 1;
    rit[mid] = get(mid);
    solve(l, mid), solve(mid, r);
}

int32_t main() {
    boost();

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    /*for (int i = 1; i <= n; i++) {
        stack<int> inc, dec;
        inc.push(0), dec.push(n + 1);
        for (int j = i; j <= n; j++) {
            if (inc.size() > 1 && a[j] < inc.top() && inc.top() < dec.top()) dec.push(inc.top()), inc.pop();
            if (a[j] > inc.top()) {inc.push(a[j]); ans++; continue;}
            if (a[j] < dec.top()) {dec.push(a[j]); ans++; continue;}
            break;
        }
    }*/
    rit[1] = get(1), rit[n] = get(n);
    solve(1, n);
    for (int i = 1; i <= n; i++) ans += rit[i] - i + 1;
    printf("%lld\n", ans);

    return 0;
}