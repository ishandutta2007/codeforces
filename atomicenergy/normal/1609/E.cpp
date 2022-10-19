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
        ll abt, abmx, ablazyby, ablazyto;
        ll bct, bcmx, bclazyby, bclazyto;
        ll anst, ansmx, anslazyby, anslazyto;
        ll length, s, e;
        bool abset, bcset, ansset;
        node* l;
        node* r;
    };

    node* rt;

    void build(int i, int j, node* v) {		
        v->abmx = v->abt = v->ablazyby = v->ablazyto = 0;
        v->bcmx = v->bct = v->bclazyby = v->bclazyto = 0;
        v->ansmx = v->anst = v->anslazyby = v->anslazyto = 0;
        
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
            if (v->abset) {
                v->l->ablazyby = v->r->ablazyby = 0;
                v->l->ablazyto = v->r->ablazyto = v->ablazyto;
                v->l->abset = v->r->abset = true;
            }
            if (v->bcset) {
                v->l->bclazyby = v->r->bclazyby = 0;
                v->l->bclazyto = v->r->bclazyto = v->bclazyto;
                v->l->bcset = v->r->bcset = true;
            }
            if (v->ansset) {
                v->l->anslazyby = v->r->anslazyby = 0;
                v->l->anslazyto = v->r->anslazyto = v->anslazyto;
                v->l->ansset = v->r->ansset = true;
            }    
            
            v->l->ablazyby += v->ablazyby;
            v->r->ablazyby += v->ablazyby;
            v->l->bclazyby += v->bclazyby;
            v->r->bclazyby += v->bclazyby;
            v->l->anslazyby += v->anslazyby;
            v->r->anslazyby += v->anslazyby;
        }
        if (v->abset) {
            v->abt = v->ablazyto * v->length;
            v->abmx = v->ablazyto;
        }
        if (v->bcset) {
            v->bct = v->bclazyto * v->length;
            v->bcmx = v->bclazyto;
            }
        if (v->ansset) {
            v->anst = v->anslazyto * v->length;
            v->ansmx = v->anslazyto;
        }
        v->abt += v->ablazyby * v->length;
        v->abmx += v->ablazyby;
        v->abset = v->ablazyby = v->ablazyto = 0;
        v->bct += v->bclazyby * v->length;
        v->bcmx += v->bclazyby;
        v->bcset = v->bclazyby = v->bclazyto = 0;
        v->anst += v->anslazyby * v->length;
        v->ansmx += v->anslazyby;
        v->ansset = v->anslazyby = v->anslazyto = 0;
    }

    void update(int i, int j, ll val, bool by, node* v, bool ab) {
        if (j < v->s || v->e < i) return;
        if (i <= v->s && v->e <= j) {
            prop(v);
            if (by) {
                if(ab) {
                    v->ablazyby += val;
                    v->anslazyby += val;
                }
                else {
                    v->bclazyby += val;
                    v->anslazyby += val;
                }
            }
            else {
                if(ab){
                    v->ablazyto = val;
                    v->abset = true;
                }else{
                    v->bclazyto = val;
                    v->bcset = true;
                }
            }
            prop(v);
            return;
        }
        prop(v);
        update(i, j, val, by, v->l, ab);
        update(i, j, val, by, v->r, ab);
        prop(v->l);
        prop(v->r);
        v->abt = v->l->abt + v->r->abt;
        v->abmx = min(v->l->abmx, v->r->abmx);
        v->bct = v->l->bct + v->r->bct;
        v->bcmx = min(v->l->bcmx, v->r->bcmx);
        v->ansmx = min(v->l->abmx + v->r->bcmx, min(v->l->ansmx, v->r->ansmx));
    }

    void updateby(int i, int j, int val, bool ab) { update(i, j, val, true, rt, ab); }
    void updateto(int i, int j, int val, bool ab) { update(i, j, val, false, rt, ab); }


    ll query(int i, int j, bool m, node* v) {
        if (j < v->s || v->e < i) {
            if (m) return 1000000000;
            return 0;
        }
        prop(v);
        if (i <= v->s && v->e <= j) {
            if (m) return v->ansmx;
            return v->anst;
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
    
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    segt abc(n+1);

    int totbs = 0;
    for(int i=0; i<n; i++){
        if(s[i] == 'a'){
            abc.updateby(i+1, n+1, 1, true);
        }
        if(s[i] == 'b'){
            abc.updateby(0, i, 1, true);
            abc.updateby(i+1, n+1, 1, false);
            totbs ++;
        }
        if(s[i] == 'c'){
            abc.updateby(0, i, 1, false);
        }
    }
    for(int i=0; i<q; i++){
        int x;
        char c;
        cin >> x >> c;
        x--;
        if(s[x] == 'a'){
            abc.updateby(x+1, n+1, -1, true);
        }
        if(s[x] == 'b'){
            abc.updateby(0, x, -1, true);
            abc.updateby(x+1, n+1, -1, false);
            
            totbs--;
        }
        if(s[x] == 'c'){
            abc.updateby(0, x, -1, false);
        }
        s[x] = c;
        if(c == 'a'){
            abc.updateby(x+1, n+1, 1, true);
        }
        if(c == 'b'){
            abc.updateby(0, x, 1, true);
            abc.updateby(x+1, n+1, 1, false);
            totbs++;
        }
        if(c == 'c'){
            abc.updateby(0, x, 1, false);
        }
        cout << abc.querymax(0, n+1)-totbs << endl;
    }
    
}