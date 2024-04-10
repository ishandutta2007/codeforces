#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << #x << ' ' << x << endl;
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const int mod = 1e9 + 7, abc = 864197532, N = 100087, logN = 17, K = 3e6;

struct chess {
    char c;
    int x, y;
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector <chess> v[4];
    int n, x, y, a, b;
    cin >> n >> a >> b;
    char c;
    for (int i = 0; i < n; ++i) {
        cin >> c >> x >> y;
        if (a + b == x + y) v[0].pb({c, x, y});
        if (a - b == x - y) v[1].pb({c, x, y});
        if (a == x) v[2].pb({c, x, y});
        if (b == y) v[3].pb({c, x, y});
    }
    bool is = false;

    chess u = {'A', -1, -1}, d = {'A', -1, -1};
    for (chess &A : v[0]) {
        if (A.x > a) {
            if (u.c == 'A' || u.x > A.x) u = A;
        } else {
            if (d.c == 'A' || d.x < A.x) d = A;
        }
    }
    if (u.c == 'B' || u.c == 'Q') is = true;
    if (d.c == 'B' || d.c == 'Q') is = true;

    u = {'A', -1, -1}, d = {'A', -1, -1};
    for (chess &A : v[1]) {
        if (A.x > a) {
            if (u.c == 'A' || u.x > A.x) u = A;
        } else {
            if (d.c == 'A' || d.x < A.x) d = A;
        }
    }
    if (u.c == 'B' || u.c == 'Q') is = true;
    if (d.c == 'B' || d.c == 'Q') is = true;

    u = {'A', -1, -1}, d = {'A', -1, -1};
    for (chess &A : v[2]) {
        if (A.y > b) {
            if (u.c == 'A' || u.y > A.y) u = A;
        } else {
            if (d.c == 'A' || d.y < A.y) d = A;
        }
    }
    if (u.c == 'R' || u.c == 'Q') is = true;
    if (d.c == 'R' || d.c == 'Q') is = true;

    u = {'A', -1, -1}, d = {'A', -1, -1};
    for (chess &A : v[3]) {
        if (A.x > a) {
            if (u.c == 'A' || u.x > A.x) u = A;
        } else {
            if (d.c == 'A' || d.x < A.x) d = A;
        }
    }
    if (u.c == 'R' || u.c == 'Q') is = true;
    if (d.c == 'R' || d.c == 'Q') is = true;

    cout << (is ? "YES\n" : "NO\n");
}