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
vector<int>V[LIM];
ll kol[LIM], T[LIM];
void solve() {
        int n, m;
        cin >> n >> m;
        ll x=0;
        rep(i, n) {
                kol[i]=0;
                V[i].clear();
        }
        rep(i, n) cin >> T[i];
        rep(i, n) {
                int a;
                cin >> a;
                T[i]=a-T[i];
                x+=T[i];
        }
        rep(i, m) {
                int a, b;
                cin >> a >> b; --a; --b;
                V[a].pb(b);
                V[b].pb(a);
        }
        if(abs(x)%2==1) {
                cout << "NO\n";
                return;
        }
        queue<int>q;
        q.push(0);
        kol[0]=1;
        ll sum1=0, sum2=0;
        while(!q.empty()) {
                int p=q.front(); q.pop();
                if(kol[p]==1) sum1+=T[p];
                else sum2+=T[p];
                for(auto i : V[p]) {
                        if(!kol[i]) {
                                kol[i]=kol[p]^3;
                                q.push(i);
                        } else if(kol[i]==kol[p]) {
                                cout << "YES\n";
                                return;
                        }
                }
        }
        cout << (sum1==sum2?"YES":"NO") << '\n';
}
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int _;
        cin >> _;
        while(_--) solve();
}