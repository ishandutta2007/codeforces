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

    void build(ll i, ll j, node* v) {		
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
    segt(ll n) {
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

    void update(ll i, ll j, ll val, bool by, node* v) {
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

    void updateto(ll i, ll j, ll val) { update(i, j, val, false, rt); }


    ll query(ll i, ll j, bool m, node* v) {
        if (j < v->s || v->e < i) {
            if (m) return -1;
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

    ll querymax(ll i, ll j) { return query(i, j, true, rt); }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    ll n;
    cin >> n;
    vector<ll> h;
    for(ll i=0; i<n; i++){
        ll x;
        cin >> x;
        h.push_back(x);
    }
    vector<ll> b;
    for(ll i=0; i<n; i++){
        ll x;
        cin >> x;
        b.push_back(x);
    }

    vector<vector<ll>> st;
    //st.push_back({0, -10000000ll * 10000000ll, 0});
    for(ll i=0; i<n; i++){
        ll curbf = -10000000ll * 10000000ll;
        ll curaf = -10000000ll * 10000000ll;
        while(!st.empty() && h[st.back()[0]] > h[i]){
            auto tm = st.back();
            st.pop_back();
            curbf = max(curbf, tm[1]);
            curbf = max(curbf, tm[2] );
            curaf = max(curaf, tm[1] + b[i]);
            curaf = max(curaf, tm[2] + b[i]);
        }
        if(st.empty()){

            st.push_back({i, curbf, max(curaf, b[i])});
        }
        else{
            auto tm = st.back();
            curbf = max(curbf, tm[1] + b[tm[0]]);
            curbf = max(curbf, tm[2] );
            curaf = max(curaf, tm[2]);
            curaf = max(curaf, tm[1] + b[tm[0]]);
            curaf = max(curaf, tm[2] + b[i]);
            st.push_back({i, curbf, curaf});
            //for(auto v : st){cout << v[0] << " " << v[1] << " " << v[2] << endl;}
            //cout << endl;
        }
    }
    cout << st.back()[2] << endl;
    
    
}