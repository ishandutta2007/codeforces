#include<bits/stdc++.h>

using namespace std;

#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first
#define  s              second
#define  newl           cout<<"\n";
#define  pb             push_back
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<"\n";
#define  deb2(a,b)      cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()

typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll, ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  2e6 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

int n, k;
vector <int> adj[N];

void solve() {
    cin >> n >> k;
    vector <int> d(n + 1, 0), w(n + 1, INFi);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        d[u]++;
        d[v]++;
    }
    queue <int> q;
    for (int i = 1; i <= n; i++) {
        if (d[i] <= 1) w[i] = 1, q.push(i);
    }
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (auto it : adj[x]) {
            d[it]--;
            if (d[it] <= 1 && w[it] == INFi) {
                w[it] = w[x] + 1;
                q.push(it);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        // deb2(i, w[i])
        if (w[i] > k) ans++;
        adj[i].clear();
    }
    deb1(ans)
}

int main() {
    GODSPEED;
    int test = 1;
    cin >> test;
    for (int i = 1; i <= test; i++) {
        solve();
    }
}