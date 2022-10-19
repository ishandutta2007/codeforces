#include <iostream>
#include <vector>
#include <cmath>
#include <array>
#include <algorithm>
#include <random>
#include <chrono>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>

using namespace std;
#define int long long
const int INF = 1e9;

signed main(){
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        int w = 0;
        for (int i : a) w += i;
        map <int, int> d;
        for (int i : a) ++d[i];
        map <int, int> cur;
        queue <int> q;
        q.push(w);
        int cnt = 0;
        while (!q.empty() && cnt < n) {
            int now = q.front();
            q.pop();
            if (cur[now] == d[now]) {
                q.push(now / 2);
                q.push((now + 1) / 2);
                ++cnt;
            } else {
                ++cur[now];
            }
        }
        if (cnt == n - 1) cout << "YES\n";
        else cout << "NO\n";
    }
}