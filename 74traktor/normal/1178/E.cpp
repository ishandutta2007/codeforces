#include <bits/stdc++.h>

using namespace std;

vector < int > pos[3];

main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int n = (int)s.size();
    for (int i = 0; i < n; ++i) {
        pos[s[i] - 'a'].push_back(i);
    }
    int k = n / 2;
    int l = 0, r = n - 1;
    string sum1 = "", sum2 = "";
    while (l <= r) {
        if (l == r) {
            sum1 += s[l];
            break;
        }
        if (s[l] == s[r]) {
            sum1 += s[l], sum2 += s[r];
            l++, r--;
        }
        else if (s[l] == s[r - 1] && l + 1 != r) {
            sum1 += s[l], sum2 += s[l];
            ++l, r -= 2;
        }
        else if (s[r] == s[l + 1] && l + 1 != r) {
            sum1 += s[l + 1], sum2 += s[l + 1];
            l += 2, r -= 1;
        }
        else if (s[r - 1] == s[l + 1] && l + 1 != r - 1) {
            sum1 += s[r - 1], sum2 += s[r - 1];
            r -= 2;
            l += 2;
        }
        else {
            sum1 += s[l];
            break;
        }
    }
    reverse(sum2.begin(), sum2.end());
    string ans = sum1 + sum2;
    if ((int)ans.size() >= k) cout << ans << '\n';
    else cout << "IMPOSSIBLE" << '\n';
    return 0;
}