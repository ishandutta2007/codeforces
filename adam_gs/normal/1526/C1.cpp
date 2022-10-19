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
const ll INF=1e13+7;
ll T[LIM], uzyte[LIM], pref[LIM], mipref[LIM];
void solve() {
        int n, ans=0;
        cin >> n;
        rep(i, n) {
                cin >> T[i];
                if(T[i]>=0) {
                        uzyte[i]=T[i];
                        T[i]=-INF;
                        ++ans;
                }
        }
        rep(i, n) {
                ll ma=-INF, pos=-1;
                rep(j, n) {
                        pref[j]=0;
                        if(j) pref[j]=pref[j-1];
                        pref[j]+=uzyte[j];
                }
                for(int j=n-1; j>=0; --j) {
                        mipref[j]=pref[j];
                        if(j<n-1) mipref[j]=min(mipref[j], mipref[j+1]);
                }
                rep(j, n) {
                        if(T[j]>=ma && mipref[j]+T[j]>=0) {
                                ma=T[j];
                                pos=j;
                        }
                }
                if(pos==-1) break;
                ++ans;
                uzyte[pos]=T[pos];
                T[pos]=-INF;
        }
        cout << ans << '\n';
}
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int _=1;
        while(_--) solve();
}