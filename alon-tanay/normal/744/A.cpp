#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define ld long double
#define pi pair<ll,ll>
#define pl pair<ll,ll>
#define vi vector<ll>
#define vl vector<ll>
#define f first
#define s second
#define vvi vector<vi>
#define vvl vector<vl>

using namespace std;
using namespace __gnu_pbds;

vector<ll> nei[1005];
bool vis[1005];
bool gov[1005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, m, k;
    cin >> n >> m >> k;
    
    for(ll i = 0; i < k; i ++) {
        ll x;
        cin >> x;
        gov[x] = true;
    }
    for(ll i = 0; i < m; i ++) {
        ll a, b;
        cin >> a >> b;
        nei[a].push_back(b);
        nei[b].push_back(a);
    }
    vector<ll> gov_sz;
    ll mxg = 0;
    for(ll i = 1; i <= n; i ++) {
        if(vis[i]) { continue; }
        deque<ll> bfs = {i};
        vis[i] = true;
        bool cgov = false;
        ll sz = 0;
        while(bfs.size()) {
            ll cur = bfs.back();
            sz ++;
            bfs.pop_back();
            if(gov[cur]) {
                cgov = true;
            }
            for(ll ne: nei[cur]) {
                if(!vis[ne]) {
                    vis[ne] = true;
                    bfs.push_front(ne);
                }
            }
        }
        if(cgov) {
            gov_sz.push_back(sz);
        } else {
            mxg += sz;
        }
    }
    sort(gov_sz.begin(),gov_sz.end());
    mxg += gov_sz[k-1];
    ll res = (mxg * (mxg-1)) / 2;
    for(ll i = 0; i < k - 1; i ++) {
        res += (gov_sz[i] * (gov_sz[i]-1)) / 2;
    }
    res -= m;
    cout << res;
    return 0;
}