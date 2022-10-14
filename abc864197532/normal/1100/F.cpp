#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << "Line(" << __LINE__ << ") " #x << ' ' << x << endl
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
template<typename A, typename B>
ostream& operator << (ostream& o, pair<A, B> a){
    return o << a.X << ' ' << a.Y;
}
template<typename A, typename B>
istream& operator >> (istream& o, pair<A, B> &a){
    return o >> a.X >> a.Y;
}
const int mod = 1e9 + 7, abc = 864197532, N = 400008, logN = 17, K = 333;

int basis[20], T[20];

void add(int x, int t) {
    for (int i = 19; ~i; --i) if (x >> i & 1) {
        if (basis[i]) {
            if (T[i] < t) {
                swap(basis[i], x);
                swap(T[i], t);
            }
        } else {
            basis[i] = x;
            T[i] = t;
            return;
        }
        x ^= basis[i];
    }
}

int query(int t) {
    int ans = 0;
    for (int i = 19; ~i; --i) if (!(ans >> i & 1) && basis[i] && t <= T[i]) {
        ans ^= basis[i];
    }
    return ans;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n;
    vector <int> a(n);
    vector <pii> Q[n];
    for (int i = 0; i < n; ++i) cin >> a[i];
    cin >> q;
    vector <int> ans(q);
    for (int i = 0, l, r; i < q; ++i) {
        cin >> l >> r, l--, r--;
        Q[r].eb(l, i);
    }
    for (int i = 0; i < n; ++i) {
        add(a[i], i);
        for (pii &A : Q[i]) {
            ans[A.Y] = query(A.X);
        }
    }
    for (int &i : ans) cout << i << '\n';
}