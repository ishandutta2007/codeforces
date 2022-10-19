#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
#define lg(a) (31-__builtin_clz(a))
const int LIM=2e5+7;
int n, k, dp[1<<17], nxt[LIM][17], prawo[LIM];
string s;
bool f(int x) {
        rep(j, k) {
                rep(i, n) prawo[i]=nxt[i][j]=0;
                nxt[n][j]=n;
                for(int i=n-1; i>=0; --i) {
                        if(s[i]=='?' || s[i]=='a'+j) prawo[i]=prawo[i+1]+1;
                        if(prawo[i]>=x) nxt[i][j]=i+x-1;
                        else nxt[i][j]=nxt[i+1][j];
                }
        }
        rep(i, 1<<k) dp[i]=n;
        dp[0]=-1;
        rep(i, 1<<k) {
                if(dp[i]==n) continue;
                rep(j, k) if(!(i&(1<<j))) {
                        dp[i|(1<<j)]=min(dp[i|(1<<j)], nxt[dp[i]+1][j]);
                }
        }
        return dp[(1<<k)-1]<n;
}
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        cin >> n >> k >> s;
        int po=0, ko=n;
        while(po<ko) {
                int sr=(po+ko+1)/2;
                if(f(sr)) po=sr; else ko=sr-1;
        }
        cout << po << '\n';
}