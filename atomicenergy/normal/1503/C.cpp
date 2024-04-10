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

    void updateby(ll i, ll j, ll val) { update(i, j, val, true, rt); }
    void updateto(ll i, ll j, ll val) { update(i, j, val, false, rt); }


    ll query(ll i, ll j, bool m, node* v) {
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

    ll querysum(ll i, ll j) { return query(i, j, false, rt); }
    ll querymax(ll i, ll j) { return query(i, j, true, rt); }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    ll n;
    cin >> n;
    vector<pair<ll, ll> > v;
    ll cur = 0;
    for(ll i=0; i<n; i++){
        ll x, y;
        cin >> x >> y;
        v.push_back({x, y});
        cur += y;
    }

    sort(v.begin(), v.end());
    cur += v.back().first - v[0].first;
    segt s(n+1); 
    segt t(n+1);
    for(ll i=n-1; i>=0; i--){
        ll b = 0;
        pair<ll, ll> p = {v[i].first + v[i].second, 0};
        ll ii = lower_bound(v.begin(), v.end(), p) - v.begin();
        //cout << ii << endl;
        b = s.querymax(ii, n) + min(v[i].second, v.back().first - v[i].first);
        if(i < n-1) t.updateby(i+1, n-1, v[i+1].first - v[i].first);
        b = max(b, t.querymax(i+1, ii-1));
        //cout << b << endl;
        s.updateto(i, i, b);
        t.updateto(i, i, b);
    }
    cout << cur - s.querymax(0, 0) << endl;
    
}