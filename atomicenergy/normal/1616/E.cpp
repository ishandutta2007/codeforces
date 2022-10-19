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
        long long n;
        string s;
        string t;
        cin >> n >> s >> t;
        if(s < t){
            cout << 0 << endl;
            continue;

        }
        segt sg(n+5);
        for(int i=0; i<n+4; i++){
            sg.updateto(i, i, i);
        }
        vector<vector<int> > v(26);
        for(int i=0; i<s.size(); i++){
            v[s[i] - 'a'].push_back(i);
        }

        for(int i=0; i<26; i++){
            reverse(v[i].begin(), v[i].end());
        }
        
        string u = s;
        sort(u.begin(), u.end());
        if(u >= t){
            cout << -1 << endl;
            continue;
        }
        long long mn = n*n;
        long long cur = 0;
        for(int i=0; i<n; i++){
            int mnx = -1;
            for(int j=0; j<(t[i]-'a'); j++){
                if(v[j].size() == 0) continue;
                mn = min(mn, cur + sg.querymax(v[j].back(), v[j].back()));
            }

            //mn = find the first character in s less than b[i], if some exists
            if(v[t[i] - 'a'].size() == 0){ break; }

            cur += sg.querymax(v[t[i] - 'a'].back(), v[t[i] - 'a'].back());
            sg.updateby(v[t[i] - 'a'].back(), n+2, -1);
            v[t[i] - 'a'].pop_back();

            //x = find the first character in  equal to b[i]
            //
        }
        cout << mn << endl;

    }
    
}