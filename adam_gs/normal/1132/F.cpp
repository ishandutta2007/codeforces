#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=507;
int kiedy[1000], dp[LIM][LIM], nxt[LIM];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    string x;
    cin >> n >> x;
    rep(i, 1000) kiedy[i]=n;
    for(int i=n-1; i>=0; --i) {
        nxt[i]=kiedy[x[i]];
        kiedy[x[i]]=i;
    }
    for(int rozmiar=1; rozmiar<=n; ++rozmiar) {
        for(int i=0, j=rozmiar-1; j<n; ++i, ++j) {
            if(rozmiar==1) dp[i][j]=1;
            else {
                dp[i][j]=dp[i+1][j]+1;
                int p=nxt[i];
                while(p<=j) {
                    int dpnew=dp[p][j];
                    if(i<p-1) dpnew+=dp[i+1][p-1];
                    dp[i][j]=min(dp[i][j], dpnew);
                    p=nxt[p];
                }
            }
        }
    }
    cout << dp[0][n-1] << '\n';
}