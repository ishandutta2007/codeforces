#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = (int)5e5 + 10;
int n, m;
int a[maxn];
int dp[maxn];
set<int> s;
multiset<int> d;
void add(int x) {
    if(s.size() == 0) {
        s.insert(x);
        return;
    }
    auto it = s.lower_bound(x);
    if(it == s.end()) {
        it--;
        d.insert(x-*it);
    } else if(it == s.begin()) {
        d.insert(*it - x);
    } else {
        auto it2 = it;
        it2--;
        d.erase(d.find(*it-*it2));
        d.insert(*it-x);
        d.insert(x-*it2);
    }
    s.insert(x);
}
void del(int x) {
    if(s.size() < 2) {
        s.erase(x);
        return;
    }
    s.erase(x);
    auto it = s.upper_bound(x);
    if(it == s.end()) {
        it--;
        d.erase(d.find(x-*it));
    } else if(it == s.begin()) {
        d.erase(d.find(*it - x));
    } else {
        auto it2 = it;
        it2--;
        d.erase(d.find(*it-x));
        d.erase(d.find(x-*it2));
        d.insert(*it-*it2);
    }
}
void out() {
    if(s.size() <= 2) {
        cout << 0 << "\n";
        return;
    }
    cout << *(--s.end()) - *(s.begin()) - *(--d.end()) << "\n";
}
void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        add(x);
    }
    out();
    for(int i = 0; i < m; i++) {
        int t, x;
        cin >> t >> x;
        if(t == 0) del(x);
        else add(x);
        out();
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