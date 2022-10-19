#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)
#define sz(s) ((int) (s).size())

const int P1 = 1000000007;
const int P2 = 1000000009;
const int BASE = 1000001;
const int N = 200005;

ii operator + (ii x, ii y) {
    return {(x.x + y.x) % P1, 0};
}

ii operator - (ii x, ii y) {
    return {(x.x - y.x + P1) % P1, 0};
}

ii operator * (ii x, int y) {
    return {(1LL * x.x * y) % P1, 0};
}

ii operator * (ii x, ii y) {
    return {(x.x * 1LL *  y.x) % P1, 0};
}

ii pwBase[N];
vector<ii> hs[26];

void init(string s) {
    int n = s.size();
    pwBase[0] = {1, 1};
    for (int i = 1; i < N; i++) {
        pwBase[i] = pwBase[i - 1] * BASE;
    }
    for (int i = 0; i < 26; i++) {
        hs[i].resize(n + 1, make_pair(0, 0));
        for (int j = n - 1; j >= 0; j--) {
            hs[i][j] = hs[i][j + 1] * BASE + make_pair(s[j] - 'a' == i, s[j] - 'a' == i);
        }
    }
}

ii getHash(int l, int r, int c) {
    return hs[c][l] - hs[c][r + 1] * pwBase[r - l + 1];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int n, m;
    string s;
    cin >> n >> m >> s;
    init(s);
    while (m--) {
        int x, y, len;
        cin >> x >> y >> len;
        x--;
        y--;
        vector<ii> vx, vy;
        for (int i = 0; i < 26; i++) {
            vx.emplace_back(getHash(x, x + len - 1, i));
            vy.emplace_back(getHash(y, y + len - 1, i));
        }
        sort(all(vx));
        sort(all(vy));
        bool ok = 1;
        for (int i = 0; i < 26; i++) {
            if (vx[i] != vy[i]) ok = 0;
        }
        puts(ok ? "YES" : "NO");
    }
    return 0;
}