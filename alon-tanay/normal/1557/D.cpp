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

const int MX = 6e5+5;
struct Seg {
    pi val = {0,-1};
    pi lazy = {-1e9,-1e9};
    int l, r, mid;
    Seg *ls, *rs;
    Seg(int l, int r): l(l), r(r), mid((l+r)/2) {
        if(l + 1 < r) {
            ls = new Seg(l,mid);
            rs = new Seg(mid,r);
        }
    }
    void updateLazy() {
        if(l + 1 == r) {
            val = max(val,lazy);
            lazy = {-1e9,-1e9};
            return;
        }
        if(lazy.f == -1e9) { return; }
        val = max(val,lazy);
        ls->lazy = max(ls->lazy,lazy);
        rs->lazy = max(rs->lazy,lazy);
        lazy = {-1e9,-1e9};
    }
    void update(int a, int b, pi x) {
        updateLazy();
        if(a >= r || b <= l) { return; }
        if(a <= l && b >= r) {
            lazy = max(lazy,x);
            updateLazy();
            return;
        }
        ls->update(a,b,x);
        rs->update(a,b,x);
        val = max(ls->val,rs->val);
    }
    pi query(int a, int b) {
        updateLazy();
        if(a >= r || b <= l) { return {-1e9,-1e9}; }
        if(a <= l && b >= r) { return val; }
        return max(ls->query(a,b),rs->query(a,b));
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    set<pi> idxd;
    set<int> lcs;
    int n, m;
    cin >> n >> m;
    vector<int> lst(n);
    vector<vector<pi>> segs(n);
    for(int i = 0; i < m; i ++) {
        int idx, l, r;
        cin >> idx >> l >> r;
        lcs.insert(l-1);
        lcs.insert(r);
        segs[idx-1].push_back({l-1,r});
    }
    int idx =0;
    for(int l : lcs) {
        idxd.insert({l,idx});
        idx ++;
    }
    Seg seg(0,MX);
    int res = 0;
    for(int i = 0; i < n; i ++) {
        // cout << "~~~~" << endl;
        // for(int j = 0; j < 6; j ++) {
        //     cout << "{" << seg.query(j,j+1).f << " " << seg.query(j,j+1).s << "} ";
        // }
        // cout << "\n";
        pi q = {-1e9,-1e9};
        for(pi &lr : segs[i]) {
            lr.f = idxd.lower_bound({lr.f,-1})->s;
            lr.s = idxd.lower_bound({lr.s,-1})->s;
            pi c = seg.query(lr.f,lr.s);
            // cout << "  " << c.f << " " << c.s << "\n";
            q = max(q,seg.query(lr.f,lr.s));
        }
        lst[i] = q.s;
        // cout << q.f << " " << q.s << endl;
        for(pi lr : segs[i]) {
            // cout << "! " << lr.f << " " << lr.s << endl;
            seg.update(lr.f,lr.s,{q.f+1,i});
            // cout << seg.ls->val.f << " " << seg.ls->val.s << endl;
        }
    }
    pi q = seg.query(0,MX);
    cout << n-q.f << "\n";
    vector<bool> rem(n);
    int cur = q.s;
    while(cur >= 0) {
        rem[cur] = true;
        cur = lst[cur];
    }
    for(int i = 0; i < n; i ++) {
        if(!rem[i]) {
            cout << i+1 << " ";
        }
    }
    return 0;
}