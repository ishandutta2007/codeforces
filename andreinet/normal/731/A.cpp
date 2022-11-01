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

    string s;
    cin >> s;

    int ans = 0;
    char prev = 'a';

    for (char c: s) {
        int c1 = (c - prev + 26) % 26;
        int c2 = (prev - c + 26) % 26;
        ans += min(c1, c2);
        prev = c;
    }
    cout << ans << '\n';
}