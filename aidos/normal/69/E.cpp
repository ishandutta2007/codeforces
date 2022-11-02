
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = (int)5e5 + 10;
int n, m, k;

void solve() {
    cin >> n >> k;
    vector<int> a, b;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a.push_back(x);

    }
    map<int, int> cnt;
    set<int> s;
    for(int i = 0; i < n; i++) {
        if(cnt[a[i]] == 1) {
            s.erase(a[i]);
        }
        cnt[a[i]]++;
        if(cnt[a[i]] == 1) {
            s.insert(a[i]);
        }
        if(i >= k) {
            if(cnt[a[i-k]] == 1) {
                s.erase(a[i-k]);
            }
            cnt[a[i-k]]--;
            if(cnt[a[i-k]] == 1) {
                s.insert(a[i-k]);
            }
        }
        if(i >= k-1) {
            if(s.size() == 0) {
                cout << "Nothing\n";
            } else {
                cout << *s.rbegin() << "\n";
            }
        }
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    //cin >> t;
    for(int i=1; i <= t; i++) {
        solve();
    }
    return 0;
}