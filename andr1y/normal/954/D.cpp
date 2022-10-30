#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define ull unsigned ll
#define pll pair<ll, ll>
#define itr(a) begin(a), end(a)
#define pb push_back
#define x first
#define y second
#define endl '\n'
#define FAST cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define FILES(namein, nameout) freopen(namein, "r", stdin); freopen(nameout, "w", stdout);
#define M 1000000007
#define N 1000
#define INF LLONG_MAX/2-1
#define NINF -INF-1
#define F(i, n) for(ll i =0;i<n;i++)
using namespace std;
template<typename T, typename D> ostream& operator<<(ostream& os, const pair<T, D> V){return os << "(" << V.x << ";" << V.y << ")";}
template<typename T> ostream& operator<<(ostream& os, const vector<T> V){os << "array: " << endl; for(auto i:V)os << i << " "; return os << endl;}
template<typename T, size_t S> ostream& operator<<(ostream& os, const array<T, S> V){os << "vector: " << endl; for(auto i:V)os << i << " "; return os << endl;}
vector<ll> d[N];
ll dist1[N], dist2[N];
bool was1[N], was2[N];
priority_queue<pll, vector<pll>, greater<pll>> q1, q2;
map<pll, bool> lp;
main(){
    FAST;
    ll n, m, s, t;
    cin >> n >> m >> s >> t;
    --s, t--;
    for(ll i =0, u, v;i<m;i++){
        cin >> u >> v;
        u--, v--;
        d[u].pb(v);
        d[v].pb(u);
        lp[{min(u, v), max(u, v)}] = true;
    }
    for(ll i =0;i<n;i++) dist1[i] = INF, dist2[i] = INF;
    q1.push({0, s});
    while(!q1.empty()){
        pll now = q1.top();
        while(was1[now.y]){
            q1.pop();
            if(q1.empty()) break;
            now = q1.top();
        }
        if(was1[now.y]) break;
        q1.pop();
        was1[now.y]= true;
        dist1[now.y] = now.x;
        for(auto i : d[now.y]){
            if(!was1[i]){
                q1.push({now.x + 1, i});
            }
        }
    }
    q2.push({0, t});
    while(!q2.empty()){
        pll now = q2.top(); while(was2[now.y]){ q2.pop(); if(q2.empty()) break; now = q2.top(); } if(was2[now.y]) break; q2.pop();
        was2[now.y]= true; dist2[now.y] = now.x; for(auto i : d[now.y]){ if(!was2[i]){ q2.push({now.x + 1, i}); } }
    }
    ll dist_orig = dist1[t], res = 0;
    for(ll i = 0;i<n;i++){
        for(ll j = i+1;j<n;j++){
            if(lp[{i, j}]) continue;
            if(!(dist1[i] + 1 + dist2[j] < dist_orig || dist1[j] + 1 + dist2[i] < dist_orig)){
                res++;
                /*cerr << " *  i :" << i << "  j :" << j << "  dist1[i] :" << dist1[i] << "  dist2[i] :" << dist2[i] << "  dist1[j] :" << dist1[j] << "  dist2[j] :" << dist2[j]
                << "  dist_orig :" << dist_orig << endl;*/
            }
        }
    }
    cout << res;
}