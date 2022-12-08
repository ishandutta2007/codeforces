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

struct Seg {
    int val;
    int laz = 0;
    int l, r, mid;
    Seg *ls, *rs;
    Seg(int l, int r): l(l), r(r), mid((l+r)/2) {
        if(l + 1 < r) {
            ls = new Seg(l,mid);
            rs = new Seg(mid,r);
        }
        val = (r-l);
    }
    void print() {
        cout << l << " " << r << ": " << val << "\n";
        if(l + 1 < r) {
            ls->print();
            rs->print();
        }
    }
    void add(int a, int b) {
        if(a >= r || b <= l) { return; }
        if(a <= l && b >= r) {
            val = 0;
            laz = 1;
            return;
        }
        ls->add(a,b);
        rs->add(a,b);
        if(!laz) {
            val = ls->val + rs->val;
        }
    }
    void dec(int a, int b) {
        if(a >= r || b <= l) { return; }
        if(a <= l && b >= r) {
            if(l + 1 < r) {
                val = ls->val + rs->val;
            } else {
                val = 1;
            }
            laz = 0;
            return;
        }
        ls->dec(a,b);
        rs->dec(a,b);
        if(!laz) {
            val = ls->val + rs->val;
        }
    }
};

int k,n;

pi U[262144];
pi D[262144];

void rec(int l, int r, int i) {
    if(l + 1 == r) {
        return;
    }
    int mid = (l+r)/2;
    U[n-i-1] = {l,mid};
    D[n-i-1] = {mid,r};
    rec(mid,r,i*2);
    rec(l,mid,i*2+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> k;
    n = (1<<k);
    rec(0,n,1);
    Seg seg(0,n);
    string ws;
    cin >> ws;
    for(int p = 0; p < n - 1; p ++) {
        if(ws[p] == '0') {
            // cout << D[p].f << " - " << D[p].s << endl;
            seg.add(D[p].f,D[p].s);
        } else if(ws[p] == '1') {
            seg.add(U[p].f,U[p].s);
        }
    }
    // cout << seg.val << "!" << endl;
    int q;
    cin >> q;
    for(int qi = 0; qi < q; qi ++) {
        // seg.print();
        int p;
        cin >> p;
        p --;
        if(ws[p] == '0') {
            seg.dec(D[p].f,D[p].s);
        } else if(ws[p] == '1') {
            seg.dec(U[p].f,U[p].s);
        }
        char c;
        cin >> c;
        ws[p] = c;
        if(ws[p] == '0') {
            seg.add(D[p].f,D[p].s);
        } else if(ws[p] == '1') {
            seg.add(U[p].f,U[p].s);
        }
        cout << seg.val << "\n";
    }
    return 0;
}