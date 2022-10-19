#include<bits/stdc++.h>

#define st first
#define nd second
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

using namespace std;

///~~~~~~~~~~~~~~~~~~~~~~~~~~

void debug(){cerr<<"\n";}
template <typename H, typename... T>
void debug(H h, T... t) {cerr<<h; if (sizeof...(t)) cerr << ", "; debug(t...);}
#define deb(x...) cerr<<#x<<" = ";debug(x);

///~~~~~~~~~~~~~~~~~~~~~~~~~

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N=2e5+5, mod=1e9+7;
const long long INF=1e18;
vii E[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin>>n>>m;
    int sx, sy, fx, fy;
    cin>>sx>>sy>>fx>>fy;
    vector<pair<int, pii> > V;
    for(int i=1; i<=m; i++){
        int x, y;
        cin>>x>>y;
        V.pb(mp(i,mp(x, y)));
        E[0].pb(mp(i, min(abs(x-sx), abs(y-sy))));
        E[i].pb(mp(m+1, abs(x-fx)+abs(y-fy)));
    }
    E[0].pb(mp(m+1, abs(sx-fx)+abs(sy-fy)));
    sort(all(V), [](pair<int, pii> a, pair<int, pii> b){return a.nd.st<b.nd.st;});
    for(int i=1; i<m; i++){
        E[V[i-1].st].pb(mp(V[i].st, abs(V[i].nd.st-V[i-1].nd.st)));
        E[V[i].st].pb(mp(V[i-1].st, abs(V[i].nd.st-V[i-1].nd.st)));
    }
    sort(all(V), [](pair<int, pii> a, pair<int, pii> b){return a.nd.nd<b.nd.nd;});
    for(int i=1; i<m; i++){
        E[V[i-1].st].pb(mp(V[i].st, abs(V[i].nd.nd-V[i-1].nd.nd)));
        E[V[i].st].pb(mp(V[i-1].st, abs(V[i].nd.nd-V[i-1].nd.nd)));
    }
    vector<ll> d(m+5, INF);
    int N=m+2;
    d[0]=0;
    set<pair<ll, int> > S;
    for(int i=0; i<N; i++)S.insert(mp(d[i], i));
    while(S.size()){
        auto it=S.begin();
        int v=(*it).nd;
        //debug(v, d[v]);
        S.erase(it);
        for(auto u:E[v]){
            if(d[v]+u.nd<d[u.st]){
                S.erase(S.find(mp(d[u.st], u.st)));
                d[u.st]=d[v]+u.nd;
                S.insert(mp(d[u.st], u.st));
            }
        }
    }
    cout<<d[m+1];
}