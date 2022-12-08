#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        string s;
        int n, k;
        cin >> n >> k;
        cin >> s;
        if(k == 0) {
            cout << "1\n";
            continue;
        }
        int res = 1;
        for(int i = 0, j = n-1; i < j; i ++, j --) {
            if(s[i] != s[j]) {
                res = 2;
                break;
            }
        }
        cout << res << "\n";
    }
    return 0;
}