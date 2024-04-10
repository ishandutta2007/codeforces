#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

int n, q;
int a[1005];

int main() {
    boost();

    cin >> q;
    for (; q; q--) {

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a, a + n);

        int lo = n - 1;
        int cnt = 1;
        while (lo && a[lo - 1] >= cnt + 1) {
            cnt++;
            lo--;
        }

        printf("%d\n", cnt);
    }

    return 0;
}