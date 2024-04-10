#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

int dis[100005];
bool check[100005];
int nque = 0;

bool query(int x, int y) {
    nque++;
    cout << 1 << ' ' << x << ' ' << y << endl;
    string s;
    cin >> s;
    return (s == "TAK" ? 1 : 0);
    // return (dis[x] <= dis[y]);
}

int solve(int l, int r) {
    if (l > r) return 0;
    if (r - l <= 1) {
        if (query(l, r)) return l;
        else return r;
    }
    int mid = (l + r) / 2;
    // cout << l << ' ' << r << ' ' << mid << endl;
    if (query(mid, mid + 1)) return solve(l, mid);
    else return solve(mid + 1, r);
}

// mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count()); // or mt19937 for int
// long long Rand(long long l, long long r) {
//     if (r < l) return 0;
//     return l + rng() % (r - l + 1);
// }

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    // vector<int> gen;
    // for (int i = 1; i <= n; i++) {
    //     gen.pb(i);
    // }
    // random_shuffle(gen.begin(), gen.end());
    // for (int i = 0; i < k; i++) check[gen[i]] = 1;
    // for (int i = 0; i <= n + 1; i++) dis[i] = 1e9;
    // for (int i = 1; i <= n; i++) {
    //     if (check[i]) dis[i] = 0;
    //     else dis[i] = min(dis[i], dis[i - 1] + 1);
    // }
    // for (int i = n; i >= 1; i--) {
    //     if (check[i]) dis[i] = 0;
    //     else dis[i] = min(dis[i], dis[i + 1] + 1);
    // }
    int ans1 = solve(1, n);
    int ans2 = solve(1, ans1 - 1);
    if (ans2 == 0 || !query(ans2, ans1)) {
        ans2 = solve(ans1 + 1, n);
    }
    cout << 2 << ' ' << ans1 << ' ' << ans2 << endl;
    // cout << nque << ' ' << check[ans1] << ' ' << check[ans2];
    return 0;
}