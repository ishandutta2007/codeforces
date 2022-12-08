#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;

#define f first
#define s second
#define setind DEBUG_INDENT = 
#define enl "\n";
#define debug(k) for(int _ = 0; _ < DEBUG_INDENT; _ ++) { cout << "  "; } cout << #k << ": " << k << enl;

const int MOD = 1e9 + 7;
const ll MODL = 1e9 + 7;

using namespace __gnu_pbds;

template<typename T>
using pbds = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

int DEBUG_INDENT = 0;

int difs[] = {1,-2,1};

struct Seg {
    vector<ll> seg;
    int n;
    Seg(vector<pl> xs): n(xs.size()) {
        seg.resize(2*n);
        for(int i = 0; i < n; i ++) {
            seg[i+n] = xs[i].s;
        }
        for(int i = n - 1; i; i --) {
            seg[i] = max(seg[i<<1],seg[(i<<1)|1]);
        }
    }
    ll query(int a, int b) {
        ll res = -3e9;
        for(a += n, b += n; a < b; a >>= 1, b >>= 1) {
            if(a&1) {
                res = max(res,seg[a++]);
            }
            if(b&1) {
                res = max(res,seg[--b]);
            }
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, M;
        cin >> n >> M;
        vector<pi> ds(n);
        vector<pair<int,pi>> evs;
        vector<vector<int>> D(n,vector<int>(3));
        for(int i = 0; i < n; i ++) {
            int x, p;
            cin >> x >> p;
            evs.push_back({x-p,{0,i}});
            evs.push_back({x,{1,i}});
            evs.push_back({x+p,{2,i}});
            ds[i] = {x,p};
        }
        sort(evs.begin(),evs.end());
        int sz = evs.size();
        ll dif = 0;
        ll cur = 0;
        ll tim = -3e9;
        vector<pl> ps;
        vector<pl> psS;
        vector<pl> psB;
        for(int i = 0; i < sz; i ++) {
            ll x = evs[i].f;
            ll d = evs[i].s.f;
            cur += dif * (x-tim);
            if(tim != x) {
                // cout << x << " " << cur << endl;
                ps.push_back({x,cur});
                psS.push_back({x,cur-x});
                psB.push_back({x,cur+x});
                tim = x;
            }
            D[evs[i].s.s][d] = ps.size()-1;
            dif += difs[d];
        }
        Seg nor(ps);
        Seg sl(psS);
        Seg bl(psB);
        sz = ps.size();
        for(int i = 0; i < n; i ++) {
            ll l = D[i][0];
            ll m = D[i][1];
            ll r = D[i][2];
            // cout << "~~~ " << i << " | " << l << " " << m << " " << r << endl;
            // cout << nor.query(r,sz) << " " << nor.query(0,l) << endl;
            // cout << (sl.query(l,m)+ps[l].f) << " " << (bl.query(m,r)-ps[r].f) << endl;
            // cout << (max(max(nor.query(r,sz),nor.query(0,l)),max(sl.query(l,m)+ps[l].f,bl.query(m,r)-ps[r].f))) << " <= " << m << endl;
            if(max(max(nor.query(r,sz),nor.query(0,l)),max(sl.query(l,m)+ps[l].f,bl.query(m,r)-ps[r].f)) <= M) {
                cout << "1";
                // cout << "YES!!!" << endl;
            } else {
                cout << "0";
            }
        }
        cout << "\n";
    }
    return 0;
}

/*
1
3 6
1 5
5 5
3 4
*/