#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    char lastv = 'a', lasth = 'a';
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 1;
    for (char c: s) {
        if (c == 'R' || c == 'L') {
            if (lasth == 'a' || lasth == c) {
                lasth = c;
            } else {
                lasth = c;
                lastv = 'a';
                ans++;
            }
        } else {
            if (lastv == 'a' || lastv == c) {
                lastv = c;
            } else {
                lasth = 'a';
                lastv = c;
                ans++;
            }
        }
    }
    cout << ans << '\n';
}