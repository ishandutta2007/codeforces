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
const int MAXA=1e7+7;
int cp[MAXA], jaka[MAXA];
map<int,int>mp;
void solve() {
        mp.clear();
        int n, k;
        cin >> n >> k;
        int T[n];
        rep(i, n) {
                cin >> T[i];
                T[i]=jaka[T[i]];
        }
        int nxt[n];
        for(int i=n-1; i>=0; --i) {
                if(!mp[T[i]]) {
                        nxt[i]=n;
                } else nxt[i]=mp[T[i]];
                mp[T[i]]=i;
        }
        int akt=n, ans=1;
        rep(i, n) {
                if(akt==i) {
                        ++ans;
                        akt=n;
                }
                akt=min(akt, nxt[i]);
        }
        cout << ans << '\n';
}
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        rep(i, MAXA) jaka[i]=i;
        for(int i=2; i<MAXA; ++i) {
                if(cp[i]) continue;
                for(int j=i; j<MAXA; j+=i) {
                        cp[j]=1;
                        int ile=0;
                        while(jaka[j]%i==0) {
                                ile^=1;
                                jaka[j]/=i;
                        }
                        if(ile) jaka[j]*=i;
                }
        }
        int t;
        cin >> t;
        while(t--) solve();
}