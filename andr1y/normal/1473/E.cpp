// -- //
#include <bits/stdc++.h>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
ll l[4*N];
bool w[4*N];
vector<pll> d[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n, m;
    cin >> n >> m;
    for(ll a, b, c, i = 0;i<m;i++){
        cin >> a >> b >> c;
        d[a].push_back({b, c});
        d[b].push_back({a, c});
    }
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, 1});
    while(!pq.empty()){
        pll now = pq.top();pq.pop();
        while(!pq.empty()&&w[now.y]){
            now=pq.top();pq.pop();
        }
        if(w[now.y]) break;
        ll cv = now.y, cl = now.x;
        l[cv]=cl;
        w[cv]=1;
        ll code = (cv-1)/n, v = (cv-1)%n+1;
        for(auto i : d[v]){
            ll nv=  code*n+i.x;
            if(!w[nv]){
                pq.push({cl+i.y, nv});
            }
            if((code&1)==0){
                if(!w[nv+n]){
                    pq.push({cl+i.y+i.y, nv+n});
                }
            }
            if((code&2)==0){
                if(!w[nv+n+n]){
                    pq.push({cl, nv+n+n});
                }
            }
            if((code&3)==0){
                if(!w[nv+n+n+n]){
                    pq.push({cl+i.y, nv+n+n+n});
                }
            }
        }
    }
    for(ll i = 2;i<=n;i++) cout<<l[n+n+n+i]<<' ';
}