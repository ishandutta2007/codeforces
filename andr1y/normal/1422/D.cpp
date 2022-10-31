// -- //
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> yree;
const ll N = 1e5+228;
pll a[N];
pll xs[N], ys[N];
vector<pll> d[N];
inline ll dist(ll e, ll b){
    return min(abs(a[e].x-a[b].x),abs(a[e].y-a[b].y));
}
bool was[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll m, n;
    cin >> m >> n;
    ll sx, sy, fx, fy;
    cin >> sx >> sy >> fx >> fy;
    xs[0]={sx, 0};
    ys[0]={sy, 0};
    a[0]={sx, sy};
    for(ll i = 1;i<=n;i++){
        cin >> a[i].x >> a[i].y;
        xs[i]={a[i].x, i};
        ys[i]={a[i].y, i};
    }
    sort(xs, xs+n+1);
    sort(ys, ys+n+1);
    for(ll i = 1;i<=n;i++){
        d[xs[i].y].push_back({xs[i-1].y, dist(xs[i].y, xs[i-1].y)});
        d[xs[i-1].y].push_back({xs[i].y, dist(xs[i].y, xs[i-1].y)});
        d[ys[i].y].push_back({ys[i-1].y, dist(ys[i].y, ys[i-1].y)});
        d[ys[i-1].y].push_back({ys[i].y, dist(ys[i].y, ys[i-1].y)});
    }
    ll res=abs(sx-fx)+abs(sy-fy);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, 0});
    while(!pq.empty()){
        pll now = pq.top();pq.pop();
        while(was[now.y]&&!pq.empty()){
            now = pq.top();pq.pop();
        }
        if(was[now.y]) break;
        ll v = now.y, l = now.x;
        was[v]=1;
        res=min(res, l+abs(a[v].x-fx)+abs(a[v].y-fy));
        for(auto i : d[v]){
            pq.push({l+i.y, i.x});
        }
    }
    cout<<res;
}