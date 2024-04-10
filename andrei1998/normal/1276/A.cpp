#include <bits/stdc++.h>

using namespace std;

typedef long long int lint;

void solve(const string& str) {
    const int N = str.size();
    vector <int> ans;
    for (int i = 0; i < N; ++i) {
        if (i + 5 <= N && str.substr(i, 5) == "twone") {
            ans.push_back(i + 2);
            i += 4;
            continue;
        }
        if (i + 3 <= N && (str.substr(i, 3) == "two" || str.substr(i, 3) == "one")) {
            ans.push_back(i + 1);
            i += 2;
            continue;
        }
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] + 1 << " \n"[i + 1 == ans.size()];
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    int T = 0;
    cin >> T;
    while (T--) {
        string str;
        cin >> str;
        solve(str);
    }
    return 0;
}