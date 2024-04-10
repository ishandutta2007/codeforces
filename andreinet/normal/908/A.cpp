#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

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

    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    char even[] = {'0', '2', '4', '6', '8'};
    int ans = 0;
    for (char c: s) {
        if ('a' <= c && c <= 'z') {
            ans += find(vowels, vowels + 5, c) != vowels + 5;
        } else {
            ans += find(even, even + 5, c) == even + 5;
        }
    }
    cout << ans << '\n';
}