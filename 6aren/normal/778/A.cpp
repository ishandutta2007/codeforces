#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 200005;

string s, t;
int p[N], n;
bool has[N];

bool check(int k) {
    for (int i = k + 1; i < s.size(); i++) {
        has[p[i]] = 1;
    }
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        if (cur != t.size() - 1 && has[i] && s[i] == t[cur + 1]) cur++;
    }
    memset(has, 0, sizeof(has));
    return (cur == t.size() - 1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    cin >> s >> t;
    s = " " + s;
    t = " " + t;
    n = s.size() - 1;
    for (int i = 1; i <= n; i++) cin >> p[i];
    int l = 0, r = n - t.size() + 1;
    int ans = 0;
    while (r >= l) {
        int mid = (l + r) / 2;
        if (check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << ans;
    return 0;
}