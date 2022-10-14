#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 2e9 + 1;
const ll INFLL = 1e18 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        ll start = stoll(s);
        int n;
        cin >> n;
        s.insert(s.begin(), '0');
        int st = 0;
        for (auto &c : s) st += c - '0';
        if (st <= n) {
            cout << 0 << "\n";
            continue;
        }
        for (int i = (int)s.size() - 1; i > 0; i--) {
            s[i] = '0';
            if (s[i - 1] == '9') continue;
            int now = 1;
            for (int j = 0; j < i; j++) now += s[j] - '0';
            if (now <= n) {
                s[i - 1]++;
                ll finish = stoll(s);
                cout << finish - start << "\n";
                break;
            }
        }
    }
    return 0;
}