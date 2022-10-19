using namespace std;

#define visual

#ifdef visual
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <assert.h>
#include <functional>
#include <math.h>
#include <string>
#include <ctime>
#endif
#ifndef visual
#include <bits/stdc++.h>
#endif

typedef long long ll;

struct segt {

    struct node {
        ll t, mx, lazyby, lazyto;
        ll length, s, e;
        bool set;
        node* l;
        node* r;
    };

    node* rt;

    void build(int i, int j, node* v) {		
        v->mx = v->t = v->lazyby = v->lazyto = 0;
        v->length = j - i + 1;
        v->s = i;
        v->e = j;
        if (i == j) return;
        v->l = new node();
        v->r = new node();
        build(i, (i + j) / 2, v->l);
        build((i + j) / 2 + 1, j, v->r);
    }

    segt() {}
    segt(int n) {
        rt = new node();
        build(0, n - 1, rt);
    }

    inline void prop(node* v) {
        if (v->l != nullptr) {
            if (v->set) {
                v->l->lazyby = v->r->lazyby = 0;
                v->l->lazyto = v->r->lazyto = v->lazyto;
                v->l->set = v->r->set = true;
            }
            v->l->lazyby += v->lazyby;
            v->r->lazyby += v->lazyby;
        }
        if (v->set) {
            v->t = v->lazyto * v->length;
            v->mx = v->lazyto;
        }
        v->t += v->lazyby * v->length;
        v->mx += v->lazyby;
        v->set = v->lazyby = v->lazyto = 0;
    }

    void update(int i, int j, ll val, bool by, node* v) {
        if (j < v->s || v->e < i) return;
        if (i <= v->s && v->e <= j) {
            prop(v);
            if (by) v->lazyby += val;
            else {
                v->lazyto = val;
                v->set = true;
            }
            prop(v);
            return;
        }
        prop(v);
        update(i, j, val, by, v->l);
        update(i, j, val, by, v->r);
        prop(v->l);
        prop(v->r);
        v->t = v->l->t + v->r->t;
        v->mx = max(v->l->mx, v->r->mx);

    }

    void updateby(int i, int j, int val) { update(i, j, val, true, rt); }
    void updateto(int i, int j, int val) { update(i, j, val, false, rt); }


    ll query(int i, int j, bool m, node* v) {
        if (j < v->s || v->e < i) {
            if (m) return -1000000000;
            return 0;
        }
        prop(v);
        if (i <= v->s && v->e <= j) {
            if (m) return v->mx;
            return v->t;
        }
        ll l = query(i, j, m, v->l);
        ll r = query(i, j, m, v->r);
        if (m) return max(l, r);
        return l + r;
    }

    ll querysum(int i, int j) { return query(i, j, false, rt); }
    ll querymax(int i, int j) { return query(i, j, true, rt); }
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tests;
    cin >> tests;
    for(int casenum = 1; casenum <= tests; casenum++){
        int n, q;
        cin >> n >> q;
        string a, b;
        cin >> a >> b;
        segt s(n);
        for(int i=0; i<n; i++){
            if(b[i] == '1'){
                s.updateto(i, i, 1);
            }
        }
        bool ok = true;
        vector<pair<int, int> > vq;
        for(int i=0; i<q; i++){
            int x, y;
            cin >> x >> y;
                        x--;
            y--;
            vq.push_back({x, y});
        }
        reverse(vq.begin(), vq.end());

        for(auto vv : vq){
            int x = vv.first;
            int y = vv.second;
            int sm = s.querysum(x, y);
            int tot = (y - x + 1);
            if(sm * 2 == tot){
                ok = false;
                break;
            }
            if(sm * 2 > tot){
                s.updateto(x, y, 1);
            }else{
                s.updateto(x, y, 0);
            }
        }
        
        for(int i=0; i<n; i++){
            if(a[i] != ('0' + (s.querysum(i, i)))) ok = false;
        }
        if(!ok) {
            cout << "NO" << endl;

        }else{
            cout << "YES" << endl;
        }
    }
    
    
}