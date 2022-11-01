#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pdd = pair<ld,ld>;
using vi = vector<int>;

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define x first
#define y second

const int maxn = 1e6, mod = 1e9 + 7, INF = 1e9;
const ll llINF = 1e18;
const ld pi = acos(-1.0), eps = 1e-6;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    int n, m; cin >> n >> m;
    if(m == 1) return cout << 0, 0;
    vi a[m];
    multiset<int> s;
    for(int i = 0; i < n; i++) {
        int p, c; cin >> p >> c;
        a[p-1].pb(c);
        if(p!=1) s.insert(c);
    }
    for(int i=0; i<m; i++) sort(all(a[i]));
    ll ans=llINF;
    for(int x = 0; x <= (n-1)/2; x++) {
        multiset<int> ss = s;
        int me = sz(a[0]);
        ll cur=0;
        vi pos(m, 0);
        for(int i=1; i<m; i++) {
            while(sz(a[i]) - pos[i] > x) ss.erase(ss.find(a[i][pos[i]])), cur += a[i][pos[i]++], me++;
        }
        while(me <= x) {
            cur += *ss.begin();
            ss.erase(ss.begin());
            me++;
        }
        ans = min(ans, cur);
    }
    cout<<ans;
}