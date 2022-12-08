#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int even = -1;
        int odd = -1;
        bool fail = false;
        for(int i = 0; i < n; i ++) {
            int x;
            cin >> x;
            if(x&1) {
                if(odd > x) {
                    fail = true;
                }
                odd = x;
            } else {
                if(even > x) {
                    fail = true;
                }
                even = x;
            }
        }
        cout << (fail ? "No" : "Yes") << "\n";
    }

    return 0;
}