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
const int mod = 1e9 + 7, abc = 864197532, N = 200087, logN = 17, K = 333;

bool P[N];
vector <int> v;

void build() {
    for (int i = 0; i < N; ++i) P[i] = true;
    for (int i = 2; i < N; ++i) if (P[i]) {
        for (int j = i + i; j < N; j += i) {
            P[j] = false;
        }
    }
    for (int i = 2; i < N; ++i) if (P[i]) v.pb(i);
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
        int p = *lower_bound(all(v), n + 1);
        cout << 1ll * p * *lower_bound(all(v), n + p) << endl;
    }
}