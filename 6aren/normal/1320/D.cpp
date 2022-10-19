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
    return {(x.x + y.x) % P1, (x.y + y.y) % P2};
}

ii operator - (ii x, ii y) {
    return {(x.x - y.x + P1) % P1, (x.y - y.y + P2) % P2};
}

ii operator * (ii x, int y) {
    return {(1LL * x.x * y) % P1, (1LL * x.y * y) % P2};
}

ii operator * (ii x, ii y) {
    return {(x.x * 1LL *  y.x) % P1, (x.y * 1LL * y.y) % P2};
}

ii pwBase[N];
vector<ii> hs;

ii getHash(int l, int r) {
    return hs[l] - hs[r + 1] * pwBase[r - l + 1];
}

vector<int> v;
ii b[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    s = " " + s;
    v.pb(0);
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0') v.pb(i);
    }
    pwBase[0] = {1, 1};
    b[0] = {0, 0};
    for (int i = 1; i <= n; i++) {
        pwBase[i] = pwBase[i - 1] * BASE;
        b[i] = b[i - 1] * BASE + make_pair(3, 3); 
    }
    hs.resize(v.size() + 5);
    for (int i = (int) v.size() - 1; i >= 1; i--) {
        hs[i] = hs[i + 1] * BASE + make_pair(v[i] % 2 + 1, v[i] % 2 + 1);
    }
    int q;
    cin >> q;
    while (q--) {
        int l1, l2, len;
        cin >> l1 >> l2 >> len;
        int cnt1, cnt2;
        int l = lower_bound(all(v), l1) - v.begin();
        int r = upper_bound(all(v), l1 + len - 1) - v.begin() - 1;
        cnt1 = r - l + 1;
        ii hash1, hash2;
        if (l > r) hash1 = {-1, -1};
        else hash1 = getHash(l, r);
        l = lower_bound(all(v), l2) - v.begin();
        r = upper_bound(all(v), l2 + len - 1) - v.begin() - 1;
        cnt2 = r - l + 1;
        if (cnt1 != cnt2) {
            cout << "No\n";
            continue;
        }
        if (l > r) hash2 = {-1, -1};
        else hash2 = getHash(l, r);
        if (hash1 == hash2 && hash1 == make_pair(-1, -1)) {
            cout << "Yes\n";
            continue;
        }
        if (l1 % 2 == l2 % 2) {
            if (hash1 == hash2) cout << "Yes\n";
            else cout << "No\n";
        } else {
            if (hash1 + hash2 == b[cnt1]) cout << "Yes\n";
            else cout << "No\n"; 
        }
    }
    return 0;
}