#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    string s, t;
    cin >> n >> s >> t;
    vector <int> ans;
    swap(s, t);
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            int idx = -1;
            for (int j = i + 1; j < n; j++) {
                if (t[j] == s[i]) {
                    idx = j;
                    break;
                }
            }
            if (idx == -1) {
                cout << idx;
                return 0;
            }
            for (int j = idx - 1; j >= i; j--) {
                ans.push_back(j);
                swap(t[j], t[j + 1]);
            }
        }
    }
    cout << ans.size() << "\n";
    for (int i : ans)
        cout << i + 1 << " ";
    return 0;
}