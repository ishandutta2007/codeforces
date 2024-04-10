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
const int LIM=1e7+7;
ll sum[LIM], ans[LIM];
void solve() {
        ll x;
        cin >> x;
        if(ans[x]) cout << ans[x];
        else cout << -1;
        cout << '\n';
}
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        for(int i=1; i<LIM; ++i) {
                for(int j=i; j<LIM; j+=i) sum[j]+=i;
                if(sum[i]<LIM && !ans[sum[i]]) ans[sum[i]]=i;
        }
        int _=1;
        cin >> _;
        while(_--) solve();
}