#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 1e9 + 1;
const ll INFLL = 1e18 + 1;

long long get(vector<int> &now, int x) {
    long long ans = 0;
    int j = 0;
    for (int i = (int)now.size() - 1; i >= 1; i--) {
        while (j + 1 < i && now[i] + now[j] < x) j++;
        ans += (now[i] + now[j] >= x ? i - j : 0);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    long long ans = 0;
    vector<int> now;
    for (int i = 0; i <= 29; i++) {
        now.clear();
        for (auto &c : a) now.pb(c & ((1 << (i + 1)) - 1));
        sort(all(now));
        ans ^= (((get(now, (1 << i)) + get(now, (1 << i) + (1 << (i + 1))) - get(now, (1 << (i + 1)))) % 2) << i);
    }
    cout << ans;
    return 0;
}