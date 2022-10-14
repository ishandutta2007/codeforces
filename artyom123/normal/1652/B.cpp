#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define ld long double
#define pb emplace_back
#define ll long long

const ll INFLL = 1e18;
const int INF = 1e9 + 1;

void solve() {
    string s;
    cin >> s;
    vector<int> lst(26, -1);
    for (int i = 0; i < (int)s.size(); i++) lst[s[i] - 'a'] = i;
    for (int i = 0; i < (int)s.size(); i++) {
        if (lst[s[i] - 'a'] == i) {
            for (int j = i; j < (int)s.size(); j++) cout << s[j];
            cout << "\n";
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}