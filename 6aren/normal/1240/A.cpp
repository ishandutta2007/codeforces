#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

const int N = 200005;

int n, p[N], cnt[N];
int x, y, a, b;
long long k;

bool check(int x) {
    vector<int> v;
    for (int i = 1; i <= x; i++) {
        v.pb(cnt[i]);
    }
    sort(all(v));
    long long sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += 1LL * v[i] * p[n - x + 1 + i] / 100;
    }
    return (sum >= k);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest;
    cin >> nTest;
    while (nTest--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
        }
        sort(p + 1, p + 1 + n);
        cin >> x >> a;
        cin >> y >> b;
        cin >> k;
        for (int i = 1; i <= n; i++) {
            cnt[i] = 0;
            if (i % a == 0) cnt[i] += x;
            if (i % b == 0) cnt[i] += y;
        }
        int l = 1, r = n;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(mid)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (l == n + 1) cout << "-1\n";
        else cout << l << '\n';
    }
    return 0;
}