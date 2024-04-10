#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    string s1 = s, t1 = t;
    sort(s1.begin(), s1.end());
    sort(t1.begin(), t1.end());
    if (s1 != t1) {
        cout << -1;
        return 0;
    }
    vector <int> ans;
    for (int i = 0; i < n; i++) {
        if (s[i] == t[i]) {
            continue;
        }
        int j = i + 1;
        for (; s[j] != t[i]; j++) {}
        j--;
        while (j >= i) {
            ans.push_back(j);
            swap(s[j], s[j + 1]);
            j--;
        }
    }
    cout << ans.size() << "\n";
    for (auto c : ans) {
        cout << c + 1 << " ";
    }
    return 0;
}