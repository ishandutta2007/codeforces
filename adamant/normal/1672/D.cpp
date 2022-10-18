#include <bits/stdc++.h>

#define int int64_t

using namespace std;

void solve() {
    int n;
    n = 10;
    cin >> n;
    int a[n], b[n];
    vector<int> sz(n);
    deque<int> pos[n];
    for(int i = 0; i < n; i++) {
        a[i] = rand() % n + 1;
        cin >> a[i];
        //cerr << a[i] << ' ';
        a[i]--;
        pos[a[i]].push_back(i);
        sz[i] = 1;
    }
    //cerr << endl;
    for(int i = 0; i < n; i++) {
        b[i] = rand() % n + 1;
        //cerr << b[i] << ' ';
        cin >> b[i];
        b[i]--;
    }
    //cerr << endl;
    int it = 0;
    for(int i = 0; i < n; i++) {
        if(it == n) {
            cout << "NO\n";
            return;
        }
        while(a[it] != b[i]) {
            //cerr << i << ' ' << it << ' ' << pos[a[it]].front() << endl;
            assert(!pos[a[it]].empty());
            assert(pos[a[it]].front() == it);
            pos[a[it]].pop_front();
            if(pos[a[it]].empty()) {
                cout << "NO\n";
                return;
            }
            sz[pos[a[it]].front()] += sz[it];
            it++;
            if(it == n) {
                cout << "NO\n";
                return;
            }
        }
        sz[it]--;
        if(sz[it] == 0) {
            pos[a[it]].pop_front();
            it++;
        }
    }
    cout << "YES\n";
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 10000;
    cin >> t;
    while(t--) {
        solve();
    }
}