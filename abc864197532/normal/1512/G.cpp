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
const int mod = 1e9 + 7, abc = 864197532, N = 10000001, K = 111;

int val[N];
lli sum[N];
int lp[N];

void build() {
    vector <int> p;
    for (int i = 2; i < N; ++i) {
        if (!lp[i]) {
            p.push_back(i);
            lp[i] = i;
        }
        for (int j = 0; 1ll * p[j] * i < N; ++j) {
            lp[p[j] * i] = p[j];
            if (i % p[j] == 0) break;
        }
    }
    sum[1] = 1;
    val[1] = 1;
    for (int i = 2; i < N; ++i) {
        int j = i, v = 1;
        while (j % lp[i] == 0) j /= lp[i], v = (v * lp[i]) + 1;
        sum[i] = sum[j] * v;
        if (sum[i] < N && !val[sum[i]]) val[sum[i]] = i;
    }
}


int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    build();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << (val[n] ? val[n] : -1) << endl;
    }
}