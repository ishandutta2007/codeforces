#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t --) {
        int n;
        cin >> n;
        int last = -1;
        int fail = false;
        for(int i = 0; i < n; i ++) {
            int x;
            cin >> x;
            if(last > x) {
                fail = true;
            }
            last = x;
        }
        cout << (fail ? "YES" : "NO") << "\n";
    }
    return 0;
}