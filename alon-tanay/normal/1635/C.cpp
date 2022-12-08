#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define MOD 1000000007

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> xs(n);
        for(int i = 0; i < n; i ++) {
            cin >> xs[i];
        }
        if(xs[n-2] > xs[n-1]) {
            cout << "-1\n";
            continue;
        }
        if(xs[n-1] >= 0) {
            cout << (n - 2) << "\n";
            for(int i = n - 2; i >= 1; i --) {
                cout << i << " " << (n-1) << " " << (n) << "\n";
            }
            continue;
        }
        bool fail = false;
        for(int i = n - 2; i >= 0; i --) {
            if(xs[i] > xs[i+1]) {
                cout << "-1\n";
                fail = true;
                break;
            }
        }
        if(fail) { continue; }
        cout << "0\n";
    }

    return 0;
}