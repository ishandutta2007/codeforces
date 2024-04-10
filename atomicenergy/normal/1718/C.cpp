#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>

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

    void updateby(int i, int j, ll val) { update(i, j, val, true, rt); }
    void updateto(int i, int j, ll val) { update(i, j, val, false, rt); }


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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin >> t;
    while (t--) {
        long long n, q;
        cin >> n >> q;

        vector<long long> fs;
        vector<long long> f;
        vector<long long> offs;
        vector<vector<long long> > fm;
        vector<long long> v;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            v.push_back(x);
        }
        long long nn = n;
        for (int i = 2; i * i <= nn; i++) {
            if (nn % i == 0) {
                f.push_back(i);
                while (nn % i == 0) nn /= i;
            }
        }
        if (nn != 1) { f.push_back(nn); }
        int all = 0;
        for (auto k : f) {
            fs.push_back(n / k);
            offs.push_back(all);
            all += n / k;
            fm.push_back(vector<long long>(n / k));
        }
        segt s(all + 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < fs.size(); j++) {
                fm[j][i % fs[j]] += v[i];
            }
        }
        for (int z = 0; z < fs.size(); z++) {
            for (int y = 0; y < fm[z].size(); y++) {
                s.updateto(offs[z] + y, offs[z] + y, fm[z][y] * (fs[z]));
            }
        }
        cout << s.querymax(0, all) << endl;

        for (int i = 0; i < q; i++) {
            long long j, x;
            cin >> j >> x;
            j--;
            for (int k = 0; k < fs.size(); k++) {

                fm[k][j % fs[k]] += x - v[j];

                s.updateby(offs[k] + j % fs[k], offs[k] + j % fs[k], fs[k] * (x - v[j]));


            }
            v[j] = x;
            cout << s.querymax(0, all) << endl;

        }
    }
}