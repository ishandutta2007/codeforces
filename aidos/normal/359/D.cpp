#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm = (int)1e7 + 100;
const int maxn = (int) 5e5 + 100;
const int mod = (int)1e9+7;
long long ans = 0;
int a[maxn];
int n;
int L[maxn];
int R[maxn];
void solve() {
    cin >> n;
    vector< pair<int, int> > d;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) {
        vector< pair<int, int> > nd;
        for(int j = 0; j < d.size(); j++) {
            int cur = __gcd(d[j].second, a[i]);
            if(nd.size() == 0 || nd.back().second != cur) {
                nd.push_back(make_pair(d[j].first, cur));
            }
        }
        if(nd.size() == 0 || nd.back().second != a[i]) {
            nd.push_back(make_pair(i, a[i]));
            L[i] = i;
        } else {
            L[i] = nd.back().first;
        }
        d.swap(nd);
    }
    d.clear();
    for(int i = n-1; i >= 0; i--) {
        vector< pair<int, int> > nd;
        for(int j = 0; j < d.size(); j++) {
            int cur = __gcd(d[j].second, a[i]);
            if(nd.size() == 0 || nd.back().second != cur) {
                nd.push_back(make_pair(d[j].first, cur));
            }
        }
        if(nd.size() == 0 || nd.back().second != a[i]) {
            nd.push_back(make_pair(i, a[i]));
            R[i] = i;
        } else {
            R[i] = nd.back().first;
        }
        d.swap(nd);
    }
    int j = 0;
    int cnt = 0;
    set< pair<int, int> > S;
    for(int i = 0; i < n; i++) {
        if(R[i] - L[i] == R[j] - L[j]) {
            S.insert(make_pair(L[i], R[i]));
        } else if(R[i] - L[i] > R[j] - L[j]) {
            j = i;
            S.clear();
            S.insert(make_pair(L[i], R[i]));
        }
    }
    cout << S.size() << " " << R[j] - L[j] << "\n";
    for(auto d: S) {
        cout << d.first+1 << " ";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}