#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define pb push_back

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int ans = 0;
    string s;
    cin >> s;
    for (auto &c : s) {
        if (c == '+') {
            ans++;
        }
        else {
            if (ans == 0) {
                continue;
            }
            ans--;
        }
    }
    cout << ans;
    return 0;
}