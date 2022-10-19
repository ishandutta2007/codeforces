#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=1e5+7, SQ=507;
int dp[LIM][SQ], T[LIM];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    rep(i, n) cin >> T[i];
    for(int j=1; j<SQ; ++j) {
        for(int i=n-1; i>=0; --i) {
            if(i+j+T[i]>n) dp[i][j]=1;
            else dp[i][j]=dp[i+j+T[i]][j]+1;
        }
    }
    int q;
    cin >> q;
    while(q--) {
        int p, k;
        cin >> p >> k; --p;
        if(k<SQ) {
            cout << dp[p][k] << '\n';
        } else {
            int ans=0;
            while(p<n) {
                p+=T[p]+k;
                ++ans;
            }
            cout << ans << '\n';
        }
    }
}