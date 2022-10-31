// -- //
#include <bits/stdc++.h>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
vector<pll> d[N];
vector<pair<ll, ll>> d2[N];
ll a[N];
bool was[N];
pll ee[N];
ll kek[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n, m, k;cin>>n>>m>>k;
    for(ll u, v, x, i=0;i<m;i++){
        cin >> u >> v >> x;
        d[u].push_back({v, x});
        d[v].push_back({u, x});
    }
    for(ll i = 0;i<k;i++){
        cin >> ee[i].y >> ee[i].x;
        d[1].push_back({ee[i].y, -ee[i].x});
        d[ee[i].y].push_back({1, -ee[i].x});
    }
    priority_queue<pll, vector<pll>, greater<pll>> pq;pq.push({0, 1});
    while(!pq.empty()){
        pll now=pq.top();pq.pop();
        while(was[now.y]&&!pq.empty()){
            now=pq.top();pq.pop();
        }
        if(was[now.y]) break;
        was[now.y]=1;
        a[now.y]=now.x;
        for(auto i : d[now.y]){
            if(!was[i.x]) pq.push({now.x+abs(i.y), i.x});
        }
    }
    ll ec=0;
    for(ll i = 1;i<=n;i++){
        for(auto j : d[i]){
            if(a[i]+abs(j.y)==a[j.x]){
                kek[j.x]++;
            }
        }
    }
    ll res=0;
    for(ll i =0;i<k;i++){
        if(a[ee[i].y]<ee[i].x) res++;
        else if(kek[ee[i].y]>1) kek[ee[i].y]--, res++;
    }
    cout<<res;
}