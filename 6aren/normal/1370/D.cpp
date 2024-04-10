#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 200005;

int a[N];
int n, k;

bool checkodd(int mid) {
    vector<int> pos;
    for (int i = 1; i <= n; i++) if (a[i] <= mid) pos.pb(i);
    int target0 = k / 2 + 1;
    int target1 = k / 2;
    int cur0 = 0;
    int pre = -1;
    for (int i = 0; i < pos.size(); i++) {
        if (pos[i] - pre > 1) {
            cur0++;
            pre = pos[i];
        } else continue;
    }
    if (cur0 >= target0) return 1;
    int cur1 = 0;
    pre = -1;
    for (int i = 0; i < pos.size(); i++) {
        if (pos[i] == 1 || pos[i] == n) continue;
        if (pos[i] - pre > 1) {
            cur1++;
            pre = pos[i];
        } else continue;
    }
    return (cur1 >= target1);
}

bool checkeven(int mid) {
    vector<int> pos;
    for (int i = 1; i <= n; i++) if (a[i] <= mid) pos.pb(i);
    int cur = 0;
    int pre = -1;
    for (int i = 0; i < pos.size(); i++) {
        if (pos[i] == n) continue;
        if (pos[i] - pre > 1) {
            cur++;
            pre = pos[i];
        } else continue;
    }
    if (cur >= k / 2) return true;
    reverse(all(pos));
    cur = 0;
    pre = n + 2;
    for (int i = 0; i < pos.size(); i++) {
        if (pos[i] == 1) continue;
        if (pos[i] - pre < -1) {
            cur++;
            pre = pos[i];
        } else continue;
    }   
    return (cur >= k / 2);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int l = 1, r = 1000000000;
    int ans = -1;
    while (r >= l) {
        int mid = (l + r) / 2;
        if ((k % 2 && checkodd(mid)) || (k % 2 == 0 && checkeven(mid))) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    cout << ans;
    return 0;
}