#include <bits/stdc++.h>
#define pi pair<ll,ll>
#define ll long long
// #define // p(n) cout << n << endl;

using namespace std;

const ll mx = 200004;
ll depth[mx];
ll submx[mx];
ll h[mx];
vector<ll> nei[mx];

ll dfs(ll node, ll par = -1) {
    ll sub = h[node];
    for(ll ne : nei[node]) {
        if(ne == par) {continue;}
        sub = max(sub,dfs(ne,node));
    }
    return submx[node] = sub;
}

ll total = 0;

ll dfs2(ll node, ll par = -1) {
    ll mxx = 0;
    for(ll ne : nei[node]) {
        if(ne == par) {continue;}
        ll alt = dfs2(ne,node);
        if(alt > mxx) {
            mxx = alt;
        }
    }
    // cout << "node " << node << endl;
    if(h[node] > mxx) {
        // cout << "s " << h[node] << " " << node << endl;
        total += h[node] - mxx;
        mxx = h[node];
    }
    return mxx;
}

bool line[mx];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll n;
    cin >> n;
    vector<pi> hs(n);
    for(ll i = 0; i < n; i ++) {
        ll x;
        cin >> x;
        hs[i] = {x,i+1};
        h[i+1] = x;
    }
    sort(hs.begin(), hs.end());
    
    for(ll i = 1; i < n; i ++) {
        ll a,b;
        cin >> a >> b;
        nei[a].push_back(b);
        nei[b].push_back(a);
    }

    ll b = hs[n-1].second;
    ll bh = hs[n-1].first;
    total = bh * 2;
    dfs(b);
    ll mxne = 0;
    ll mxsub = -1;

    ll mxne2 = 0;
    ll mxsub2 = -1;
    for(ll ne : nei[b]) {
        if(submx[ne] >= mxsub) {
            mxne2 = mxne;
            mxsub2 = mxsub;

            mxsub = submx[ne];
            mxne = ne;
        } else if(submx[ne] > mxsub2) {
            mxsub2 = submx[ne];
            mxne2 = ne;
        }
    }
    stack<ll> bar;
    ll node = mxne;
    ll par = b;
    line[b] = true;
    bar.push(b);
    while(nei[node].size() > 1) {
        bar.push(node);
        // p(node)
        line[node] = true;
        mxsub = -1;
        mxne = 0;
        for(ll ne : nei[node]) {
            if(ne == par) {continue;}
            if(submx[ne] > mxsub) {
                mxsub = submx[ne];
                mxne = ne;
            }
        }
        par = node;
        node = mxne;
    }
    // p(node)
    // p("~")
    bar.push(node);
    line[node] = true;
    if(nei[b].size() > 1) {
        node = mxne2;
        par = b;
        while(nei[node].size() > 1) {
            // p(node)
            bar.push(node);
            line[node] = true;
            mxsub = -1;
            mxne = 0;
            for(ll ne : nei[node]) {
                if(ne == par) {continue;}
                if(submx[ne] > mxsub) {
                    mxsub = submx[ne];
                    mxne = ne;
                }
            }
            par = node;
            node = mxne;
        }
        // p(node)
        // p("~")
        line[node] = true;
        bar.push(node);
    }
    while(bar.size()) {
        ll cur = bar.top();
        // cout << cur << endl;
        bar.pop();
        for(ll ne : nei[cur]) {
            if(!line[ne]) {
                line[ne] = true;
                dfs2(ne,cur);
            }
        }
    }

    cout << total;
    return 0;
}