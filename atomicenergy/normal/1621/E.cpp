

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>


using namespace std;

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

int main(){
    int t;
    
    cin >> t;
    while (t-->0) {
        int n, m;
        cin >> n >> m;
        vector<long double> teach(n);
        for (int i = 0; i < n; i++) {
            cin >> teach[i];
        }
        sort(teach.begin(), teach.end());
        reverse(teach.begin(), teach.end());
        int tots = 0;

        vector< pair<long double, vector<pair<long double, int>> > > stud(m);
        for (int i = 0; i < m; i++) {
            vector<pair<long double, int>> v;
            vector<pair<long double, int>> u;
            long double sum = 0;
            long double x, y;
            cin >> x;
            for (int i = 0; i < x; i++) {
                cin >> y;
                v.push_back({ y, tots });
                sum += y;
                tots++;

            }
            for (int i = 0; i < x; i++) {
                u.push_back({ (sum - v[i].first) / (x - 1),  v[i].second });
            }
            stud.push_back({ sum / x, u });
        }

        sort(stud.begin(), stud.end());
        reverse(stud.begin(), stud.end());

        vector<bool> ans(tots, false);

        vector<vector<int> > ok(3, vector<int>(m));
        vector<vector<int> > rg(3, vector<int>(m));


        for (int i = 0; i < m; i++) {
            if (i > 0 && stud[i].first <= teach[i - 1]) ok[0][i] = 1;
            if (stud[i].first <= teach[i]) {
                ok[1][i] = 1;
            }
            if (i + 1 < n && stud[i].first <= teach[i + 1])ok[2][i] = 1;
        }

        for (int i = 0; i < 3; i++) {
            for (int j = m - 1; j >= 0; j--) {
                if (ok[i][j] == 0) {
                    rg[i][j] = -5;
                }
                else {
                    rg[i][j] = j;
                    if (j + 1 < m) {
                        rg[i][j] = max(rg[i][j], rg[i][j + 1]);
                    }
                }
            }
        }


        for (int i = 0; i < m; i++) {
            for (auto nwii : stud[i].second) {
                double nw = nwii.first;
                int ii = nwii.second;
                
                int lo = -1;
                int hi = m;
                while (hi - lo > 1) {
                    int md = (lo + hi) / 2;
                    if (stud[md].first < nw) hi = md;
                    else lo = md;
                }
                if (i <= lo) {
                    if ((0 > i - 1 ||rg[1][0] >= i-1 ) && (i + 1 > lo || rg[0][i+1] >= lo) && (hi > m - 1 || rg[1][hi] >= m-1)) {
                        if (teach[lo] >= nw) {
                            ans[ii] = true;
                        }
                    }
                }
                else if (i >= hi) {
                    if (( 0 > lo || rg[1][0] >= lo) && (hi > i - 1 || rg[2][hi] >= i-1) && (i + 1 > m - 1|| rg[1][i+1] >= m-1)) {
                        if (teach[hi] >= nw) {
                            ans[ii] = true;
                        }
                    }
                }
            }
            
        }

        for (auto b : ans) {
            if (b) cout << '1';
            else cout << '0';
        }
        cout << endl;

    }


}