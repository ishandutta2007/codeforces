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
const int mod = 1e9 + 7, abc = 864197532, N = 200001, logN = 17;

multiset <lli> m1;
multiset <lli, greater <lli>> m2;
int k;
lli ans = 0;

void add(lli a) {
    if (k == 0) return;
    if (m1.size() < k) m1.insert(a), ans += a;
    else {
        if (*m1.begin() < a) {
            ans -= *m1.begin();
            m2.insert(*m1.begin());
            m1.erase(m1.begin());
            m1.insert(a);
            ans += a;
        } else {
            m2.insert(a);
        }
    }
}

void del(lli a) {
    if (m2.empty() || *m2.begin() < a) {
        m1.erase(m1.lower_bound(a));
        ans -= a;
        if (!m2.empty()) {
            m1.insert(*m2.begin());
            ans += *m2.begin();
            m2.erase(m2.begin());
        }
    } else {
        m2.erase(m2.lower_bound(a));
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, a;
    cin >> n >> a >> k;
    vector <pii> A(n);
    lli cur = 0;
    vector <int> neg;
    for (int i = 0; i < n; ++i) {
        cin >> A[i].X >> A[i].Y;
        if (A[i].X - A[i].Y > 0) add(A[i].X - A[i].Y);
        else neg.pb(A[i].X - A[i].Y);
        cur += A[i].Y;
    }
    if (k == 0) return cout << cur << endl, 0;
    lli tans = ans;
    for (int i = 0; i < n; ++i) {
        if (A[i].X - A[i].Y > 0) del(A[i].X - A[i].Y);
        lli na = (1ll * A[i].X) << a;
        if (na - A[i].Y > 0) add(na - A[i].Y);
        tans = max(tans, ans);
        if (na - A[i].Y > 0) del(na - A[i].Y);
        if (A[i].X - A[i].Y > 0) add(A[i].X - A[i].Y);
    }
    cout << tans + cur << endl;
}