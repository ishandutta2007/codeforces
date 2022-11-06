#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

ll f() {

    int n;
    string s;
    cin >> n >> s;
    vector<int> dpL(n+1, 0), dpR(n+1, 0);
    for(int i = 1; i <= n; ++i) {
        if(s[i-1] != 'L')
            continue;
        dpL[i] = (i == 1 || s[i-2] != 'R' ? 1 : 2 + dpL[i-2]);
    }
    for(int i = n - 1; i >= 0; --i) {
        if(s[i] != 'R')
            continue;
        dpR[i] = (i == n - 1 || s[i+1] != 'L' ? 1 : 2 + dpR[i+2]);
    }

    for(int i = 0; i <= n; ++i)
        cout << 1 + max(dpL[i], dpR[i]) + min(dpL[i], dpR[i]) << ' ';
    cout << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);


    int t;
    cin >> t;
    while(t--) {
//     auto res = f();
//     cout << res << '\n';
f();
    }
    return 0;
}