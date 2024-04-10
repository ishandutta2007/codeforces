#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back

long long lol(long long x) {return (x + 1) * x / 2;}
long long kek(long long a, long long b) {return (a + b) * (b - a + 1) / 2;}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    long long x;
    cin >> x;
    vector<long long> d(n);
    for (auto &c : d) cin >> c;
    long long sum = 0;
    int r = 0;
    long long now = d[0];
    long long ans = 0;
    for (int l = 0; l < n; l++) {
        while (now + d[(r + 1) % n] <= x) {
            r++;
            r %= n;
            sum += lol(d[r]);
            now += d[r];
        }
        //cout << l << " " << r << " " << now << " " << sum << endl;
        if (d[l] >= x) {
            ans = max(ans, kek(d[l] - x + 1, d[l]));
            now = d[l + 1];
            r++;
            continue;
        }
        if (now == x) {
            ans = max(ans, lol(d[l]) + sum);
        } else {
            long long right_move = min(d[l] - 1, d[(r + 1) % n] - (x - now));
            ans = max(ans, sum + kek(1 + right_move, d[l]) + kek(1, x - now + right_move));
        }
        if (l == r) {
            now = d[l + 1];
            r++;
            continue;
        }
        now -= d[l];
        sum -= lol(d[(l + 1) % n]);
    }
    cout << ans;
    return 0;
}