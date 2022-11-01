#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e15 + 10;
const ld EPS = 1e-8;
const ld PI = acos(-1);
const int M = 20;
const int N = 1e6 + 10;

set<int> poses[26];

void solve() {
    string s;
    cin >> s;
    for (int i = 0; i < (int)s.size(); ++i) {
        poses[s[i] - 'a'].insert(i);
    }
    int n;
    cin >> n;

    while (n--) {
        int type;
        cin >> type;
        if (type == 1) {
            int pos;
            cin >> pos;
            char ch;
            cin >> ch;
            --pos;
            poses[s[pos] - 'a'].erase(pos);
            poses[ch - 'a'].insert(pos);
            s[pos] = ch;
        } else {
            int l, r;
            cin >> l >> r;
            --l, --r;
            int cnt = 0;
            for (int i = 0; i < 26; i++) {
                auto it = poses[i].lower_bound(l);
                if (it != poses[i].end() && *it <= r) {
                    cnt++;
                }
            }
            cout << cnt << endl;
        }
    }

}

int main() {
    //freopen("in.txt", "r", stdin);
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
}