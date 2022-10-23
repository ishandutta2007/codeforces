#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    int l = 0;
    while (l < n) {
        while (l < n and s[l] != 'x') ++l;
        int r = l;
        while (r < n and s[r] == 'x') ++r;
        ans += max(r - l - 2, 0);
        l = r;
    }
    cout << ans << '\n';
    return 0;
}