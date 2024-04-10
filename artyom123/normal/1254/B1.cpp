#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back

const long long INF = 1e18 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    int s = 0;
    for (auto &c : a) s += c;
    long long ans = INF;
    for (int k = 2; k <= n; k++) {
        if (s % k != 0) continue;
        vector<int> ind;
        long long now_ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) continue;
            ind.pb(i);
            if ((int)ind.size() == k) {
                long long tmp = INF;
                long long sum = 0;
                for (auto &c : ind) sum += c;
                long long now = 0;
                long long cnt = 0;
                for (auto &c : ind) {
                    tmp = min(tmp, c * cnt - now + (sum - now) - c * (k - cnt));
                    cnt++;
                    now += c;
                }
                now_ans += tmp;
                ind.clear();
            }
        }
        ans = min(ans, now_ans);
    }
    cout << (ans == INF ? -1 : ans);
    return 0;
}