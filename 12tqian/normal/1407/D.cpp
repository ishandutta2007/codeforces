#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) {
    return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
    cout << "{"; for (int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "}"; }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    vector<int> t, b;
    t.push_back(0); b.push_back(0);
    vector<int> dist(n, n);
    dist[0] = 0;
    for (int i = 1; i < n; i++) {
        dist[i] = dist[i - 1] + 1;
        while (!t.empty() && h[i] <= h[t.back()]) {
            int x = h[t.back()];
            t.pop_back();
            if (h[i] < x && !t.empty()) {
                dist[i] = min(dist[i], dist[t.back()] + 1);
            }
        }
        while (!b.empty() && h[i] >= h[b.back()]) {
            int x = h[b.back()];
            b.pop_back();
            if (h[i] > x && !b.empty()) {
                dist[i] = min(dist[i], dist[b.back()] + 1);
            }
        }
        t.push_back(i);
        b.push_back(i);
    }
    cout << dist[n - 1] << '\n';
    return 0;
}