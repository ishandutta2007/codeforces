#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    int a[n];
    int cnt[2] = {0};
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for(int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if(t == 1) {
            int x;
            cin >> x;
            x--;
            cnt[a[x]]--;
            a[x] = 1 - a[x];
            cnt[a[x]]++;
        } else {
            int k;
            cin >> k;
            cout << (k <= cnt[1] ? 1 : 0) << "\n";
        }
    }
}