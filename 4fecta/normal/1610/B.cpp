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

int n, a[MN];

bool check(int num) {
    int l = 1, r = n;
    while (l < r) {
        if (a[l] == a[r]) l++, r--;
        else if (a[l] == num) l++;
        else if (a[r] == num) r--;
        else return false;

    }
    return true;
}

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int c1 = 0, c2 = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] != a[n - i + 1]) {
                c1 = a[i];
                c2 = a[n - i + 1];
                break;
            }
        }
        if (!c1 || check(c1) || check(c2)) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}