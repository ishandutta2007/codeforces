#include <bits/stdc++.h>
#define ll long long
#define INF 1000000000000000000

using namespace std;

struct LazySeg {
    ll val = 0;
    ll lazy = 0;
    int l, r, mid;
    LazySeg *ls, *rs;
    LazySeg(int l, int r): l(l), r(r), mid((l+r)/2) {
        if(l + 1 < r) {
            ls = new LazySeg(l,mid);
            rs = new LazySeg(mid,r);
        }
    }
    void updateLazy() {
        if(lazy) {
            if(l + 1 < r) { 
                ls->lazy += lazy;
                rs->lazy += lazy;
            }
            val += lazy;
            lazy = 0;
        }
    }
    void update(int a, int b, ll x) {
        if(a <= l && b >= r) {
            lazy += x;
            updateLazy();
            return;
        }
        updateLazy();
        if(a >= r || b <= l) { return; }
        ls->update(a,b,x);
        rs->update(a,b,x);
        val = min(ls->val, rs->val);
    }
    ll query(int a, int b) {
        updateLazy();
        if(a >= r || b <= l) { return INF; }
        if(a <= l && b >= r) {
            return val;
        }
        return min(ls->query(a,b),rs->query(a,b));
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n;
    LazySeg seg(0,n);
    for(int i = 0; i < n; i ++) { 
        ll x;
        cin >> x;
        seg.update(i,i+1,x);
    }
    cin >> m;
    cin.ignore();
    while(m --) {
        string s;
        getline(cin, s);
        istringstream is(s);
        vector<int> input((istream_iterator<int>(is)), istream_iterator<int>());
        int l = input[0];
        int r = input[1];
        if(input.size() == 2) {
            if(l <= r) {
                cout << seg.query(l,r+1) << "\n";
            } else {
                cout << min(seg.query(0,r+1),seg.query(l,n)) << "\n";
            }
        } else {
            ll val = input[2];
            if(l <= r) {
                seg.update(l,r+1,val);
            } else {
                seg.update(0,r+1,val);
                seg.update(l,n,val);
            }
        }
    }
    return 0;
}

/*

*/