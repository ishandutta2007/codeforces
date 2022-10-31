#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    int ans = -1;
    int t = 0;
    int prev = -1;
    for (int i = 0; i < n; i++) {
        int cur;
        cin >> cur;
        if (cur != prev)
            t++;
        else
            t = 1;
        prev = cur;
        //cout << t << " ";
        ans = max(ans, t);
    }
    cout << ans;
    return 0;
}