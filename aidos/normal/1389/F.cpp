#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = (int)1000200;
const ll inf = (1ll<<50);
int n;
int l[maxn];
int r[maxn];
int t[maxn];
vector<int> A[maxn], B[maxn];
int used[maxn];
void solve() {
    cin >> n;
    vector<int> d;
    for(int i = 0; i < n; i++) {
        cin >> l[i] >> r[i] >> t[i];
        d.push_back(l[i]);
        d.push_back(r[i]);
    }
    sort(d.begin(), d.end());
    d.resize(unique(d.begin(), d.end()) - d.begin());
    for(int i = 0; i < n; i++) {
        l[i] = lower_bound(d.begin(), d.end(), l[i]) - d.begin() + 1;
        r[i] = lower_bound(d.begin(), d.end(), r[i]) - d.begin() + 1;
        A[l[i]].push_back(i);
        B[r[i]].push_back(i);
    }
    set< pair<int, int> > S[4];
    int ans = n;
    for(int i = 1; i <= d.size(); i++) {
        for(int ind: A[i]) {
            S[t[ind]].insert(make_pair(r[ind], ind));
        }
        for(int ind: B[i]) {
            if(used[ind]) continue;
            S[t[ind]].erase(make_pair(r[ind], ind));
            if(S[3-t[ind]].size() > 0) {
                used[S[3-t[ind]].begin()->second] = 1;
                S[3-t[ind]].erase(S[3-t[ind]].begin());
                ans--;
            }
        }
    }
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}