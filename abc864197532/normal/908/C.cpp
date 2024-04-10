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
const int mod = 1e9 + 7, abc = 864197532, N = 200087, logN = 17, K = 3e6;

double dis(int a, int c) {
    return sqrt(c * c - a * a);
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, r;
    cin >> n >> r;
    vector <int> x(n);
    vector <double> ans(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        double cur = r;
        for (int j = 0; j < i; ++j) if (abs(x[i] - x[j]) <= r * 2) {
            cur = max(cur, ans[j] + dis(abs(x[i] - x[j]), r * 2));
        }
        ans[i] = cur;
    }
    cout << fixed << setprecision(10);
    for (double i : ans) cout << i << ' ';
    cout << endl;
}