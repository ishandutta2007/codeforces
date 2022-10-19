#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
const int LIM=2e5+7;
int T[LIM], dp[LIM];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    rep(i, n) cin >> T[i];
    for(int i=n-1; i>=0; --i) {
        if(T[i]==T[i+1]) dp[i]=dp[i+1];
        else dp[i]=i+1;
    }
    while(m--) {
        int l, r, x;
        cin >> l >> r >> x; --l; --r;
        if(T[l]!=x) {
            cout << l+1 << '\n';
            continue;
        }
        cout << (dp[l]>r?-1:dp[l]+1) << '\n';
    }
}