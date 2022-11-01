#include <bits/stdc++.h>

using namespace std;

int n, d, ans = 0, curr = 0;
string s;

int main (int argc, char const *argv[]) {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    cin >> n >> d;
    for (int i = 0; i < d; ++i) {
        cin >> s;
        bool check = 1;
        for (int j = 0; j < n; ++j) {
            if (s[j] == '0') {
                curr++;
                check = 0;
                break;
            }
        }
        if (check) curr = 0;
        ans = max(ans, curr);
    }
    cout << ans << endl;
    return 0;
}