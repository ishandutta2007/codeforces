#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define MOD 998244353
#define pi pair<int,int>
#define pl pair<ll,ll>
#define f first
#define s second

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        ll cntB = 0;
        ll cntR = 0;
        bool fail = false;
        for(int i = 0; i < n; i ++) {
            char c;
            cin >> c;
            if(c == 'W') {
                if(cntB*cntR == 0 && cntB + cntR > 0) {
                    fail = true;
                }
                cntB = 0;
                cntR = 0;
            } else if(c == 'B') {
                cntB ++;
            } else {
                cntR ++;
            }
        }
        if(cntB*cntR == 0 && cntB + cntR > 0) {
            fail = true;
        }
        cout << (fail ? "NO" : "YES") << "\n";
    }
    return 0;
}