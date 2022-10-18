#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define int int64_t

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    set<int> pos;
    for(int i = 0; i < n; i++) {
        int r;
        cin >> r;
        int a[r];
        for(int i = 0; i < r; i++) {
            cin >> a[i];
        }
        if(i == 0) {
            pos = set<int>(a, a + r);
        } else {
            set<int> nw(a, a + r);
            for(auto it = begin(nw); it != end(nw); ) {
                if(!pos.count(*it)) {
                    it = nw.erase(it);
                } else {
                    it++;
                }
            }
            pos = nw;
        }
    }
    for(auto it: pos) {
        cout << it << ' ';
    }
    return 0;
}