#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll,ll>;
using pl = pair<ll,ll>;
using vi = vector<ll>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;

#define f first
#define s second
#define setind DEBUG_INDENT = 
#define enl "\n";
#define debug(k) for(ll _ = 0; _ < DEBUG_INDENT; _ ++) { cout << "  "; } cout << #k << ": " << k << enl;

const ll MOD = 1e9 + 7;
const ll MODL = 1e9 + 7;

using namespace __gnu_pbds;

template<typename T>
using pbds = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll DEBUG_INDENT = 0;
const ll mxN = 200005;
const ll mxP = 18;
vi nei[mxN];
ll depth[mxN];
ll subsize[mxN];
ll sup[mxN][mxP];

void dfs(ll node, ll par = -1) {
    ll sz = 1;
    // cout << node << ": " << depth[node] << endl;
    for(ll ne : nei[node]) {
        if(ne == par) {continue; }
        depth[ne] = depth[node] + 1;
        dfs(ne,node);
        sup[ne][0] = node;
        sz += subsize[ne];
    }
    subsize[node] = sz;
}

ll N;
ll lift(ll a, ll d) {
    if(a == N) { return 0; }
    if(d <= 0) { return a; }
    // cout << "lift " << a << " " << d<< endl;
    for(ll p = 0; p < mxP; p ++) {
        if(d&1) {
            a = sup[a][p];
        }
        d >>= 1;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        N = n;
        for(ll i = 0; i <= n; i ++) {
            nei[i].clear();
            depth[i] = 0;
            subsize[i] = 0;
        }
        for(ll i = 1; i < n; i ++) {
            ll a, b;
            cin >> a >> b;
            nei[a].push_back(b);
            nei[b].push_back(a);
        }
        dfs(0);
        for(ll p = 1; p < mxP; p ++) {
            for(ll i = 0; i < n; i ++) {
                sup[i][p] = sup[sup[i][p-1]][p-1];
            }
        }
        vector<ll> res(n+1);
        vector<ll> vis(n+1);
        ll l = 0, r = 0;
        ll root_l = 0;

        ll res0 = 0;
        for(ll ne : nei[0]) {
            res0 += (subsize[ne] * (subsize[ne]-1))/2;
        }
        res[0] = res0;
        ll res1 = (n-subsize[1])*(n-subsize[1]);
        for(ll ne : nei[0]) {
            if(lift(1,depth[1]-1) == ne) {
                root_l = ne;
                ll dif = depth[1];
                ll cur = 1;
                for(ll j = 0; j < dif; j ++) {
                    cur = sup[cur][0];
                    vis[cur] = true;
                }
                ll sub = subsize[ne]-subsize[1];
                res1 -= sub*sub;
            } else {
                ll sub = subsize[ne];
                res1 -= sub*sub;
            }
        }
        res1 --;
        res1 /= 2;
        res[1] = res1;
        l = 1;
        vis[1] = true;
        // cout << res0 << " " << res1 << endl;
        for(ll i = 2; i <= n; i ++) {
            // add i-1
            ll cur = i - 1;
            ll cc = cur;
            // cout << "~~~~~\n";
            // cout << i << ": " << l << " " << r << endl;
            if(!vis[cur]) {
                ll dif = depth[cur]-depth[l];
                if(dif > 0 && lift(cur,dif) == l) {
                    for(ll j = 1; j < dif; j ++) {
                        cur = sup[cur][0];
                        vis[cur] = true;
                    }
                    l = cc;
                } else if(r == 0) {
                    if(lift(cur,depth[cur]-1) == root_l) {
                        break;
                    } else {
                        dif = depth[cur];
                        for(ll j = 1; j < dif; j ++) {
                            cur = sup[cur][0];
                            vis[cur] = true;
                        }
                        r = cc;
                    }
                } else {
                    dif = depth[cur]-depth[r];
                    if(dif > 0 && lift(cur,dif) == r) {
                        for(ll j = 1; j < dif; j ++) {
                            cur = sup[cur][0];
                            vis[cur] = true;
                        }
                        r = cc;
                    } else {
                        break;
                    }
                }
            }
            // cout << "new: " << l << " " << r << endl;
            if(vis[i]) { continue; }
            ll cur_res;
            // cout << "YE" << endl;
            if(r == 0) {
                // cout << 0 << endl;
                if(lift(i,depth[i]-1) != root_l) {
                    // cout << lift(i,depth[i]-1) << endl;
                    cur_res = (n-subsize[root_l]-subsize[i])*(subsize[l]);
                } else if(lift(i,depth[i]-depth[l]) == l) {
                    // cout << 1 << endl;
                    cur_res = (n-subsize[root_l])*(subsize[l]-subsize[i]);
                } else {
                    // cout << 2 << endl;
                    cur_res = (n-subsize[root_l])*(subsize[l]);
                }
            } else {
                // cout << 1 << endl;
                // cout << i << " " << r << endl;
                // cout << depth[i]-depth[r] << endl;
                if(lift(i,depth[i]-depth[r]) == r) {
                    // cout << 0 << endl;
                    cur_res = (subsize[r]-subsize[i])*(subsize[l]);
                } else if(lift(i,depth[i]-depth[l]) == l) {
                    // cout << 1 << endl;
                    cur_res = (subsize[r])*(subsize[l]-subsize[i]);
                } else {
                    // cout << 2 << endl;
                    cur_res = (subsize[r])*(subsize[l]);
                }
            }
            // cout << "res: " << cur_res << endl;
            res[i] = cur_res;
        }
        for(ll r : res) {
            cout << r << " ";
        }
        cout << "\n";
    }
    return 0;
}


/*
1
2
1 0
*/

/*
1
4
0 1
0 2
2 3
*/

/*
1
6
0 2
2 3
2 4
4 5
4 1
*/

/*
1
8
0 7
7 2
0 6
6 3
6 4
4 5
4 1
*/