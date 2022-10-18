#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if (s.back() == 'A') {
            cout << "NO\n";
            continue;
        }
        int flag = 1;
        int cnt = 0;
        for (char c : s)
            if (c == 'A')
                ++cnt;
            else {
                if (cnt == 0) flag = 0;
                --cnt;
            }
        if (!flag)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}