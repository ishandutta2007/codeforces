#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 100005;

int n, k, a[MN], b[MN];
char c;

bool check(int len) {
    for (int l = 1; l + len - 1 <= n; l++) {
        int r = l + len - 1;
        if (a[r] - a[l - 1] <= k || b[r] - b[l - 1] <= k) return true;
    }
    return false;
}

int main() {
    boost();

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> c;
        a[i] = a[i - 1];
        b[i] = b[i - 1];
        if (c == 'a') a[i]++;
        else b[i]++;
    }

    int lo = 1, hi = n, mid;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        mid += (lo + hi) & 1;
        if (check(mid)) lo = mid;
        else hi = mid - 1;
    }

    printf("%d\n", lo);

    return 0;
}