#include<bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pii pair<int, int>

const int INF = 2e9 + 1;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        set<int> zero, one;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') zero.insert(i);
            else one.insert(i);
        }
        vector<int> ans(n);
        int cur = 1;
        for (int i = 0; i < n; i++) {
            if (ans[i]) continue;
            int j = i;
            while (1) {
                ans[j] = cur;
                if (s[j] == '0') {
                    zero.erase(j);
                    auto it = one.upper_bound(j);
                    if (it == one.end()) break;
                    j = *it;
                } else {
                    one.erase(j);
                    auto it = zero.upper_bound(j);
                    if (it == zero.end()) break;
                    j = *it;
                }
            }
            cur++;
        }
        cout << cur - 1 << "\n";
        for (auto &c : ans) cout << c << " ";
        cout << "\n";
    }
    return 0;
}