#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")
 
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <sstream>
#include <deque>
#include <queue>
#include <random>
#include <cassert>
 
using namespace std;
 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(12)
#define RANDOM srand(94385)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define f first
#define s second
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-9
#define mod 1000000007
#define inf 3000000000000000007ll
#define sz(a) signed(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define shuffle(a) \
    for (int i = 0; i < sz(a); ++i) \
        swap(a[i], a[rand() % sz(a)]);
 
template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmax(T &x, U y) { if (y > x) return x = y, true; return false; }
template<class T, class U> inline bool ifmin(T &x, U y) { if (y < x) return x = y, true; return false; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }

typedef ll key;
typedef struct node* pnode;

struct node {
    key k;
    int cnt = 1, p = rand();
    pnode l = nullptr, r = nullptr;
    node(int k) { this->k = k; }
};

ostream& operator<<(ostream& str, pnode n) {
    if (!n) return str;
    return str << n->l << n->k << ' ' << n->r; 
}

int getcnt(pnode n) {
    return n ? n->cnt : 0;
}

void upd(pnode n) {
    if (n) n->cnt = 1 + getcnt(n->l) + getcnt(n->r);
}

pnode merge(pnode a, pnode b) {
    if (!a) return b;
    if (!b) return a;
    if (a->p > b->p) {
        a->r = merge(a->r, b);
        upd(a);
        return a;
    } else {
        b->l = merge(a, b->l);
        upd(b);
        return b;
    }
}

void splitval(pnode t, key k, pnode &l, pnode &r) {
    if (!t) return void(l = r = t);
    if (t->k > k) {
        splitval(t->l, k, l, t->l);
        r = t;
    } else {
        splitval(t->r, k, t->r, r);
        l = t;
    }
    upd(l); upd(r);
}

void splitind(pnode t, int ind, pnode &l, pnode &r) {
    if (!t) return void(l = r = t);
    if (getcnt(t->l) < ind) {
        splitind(t->r, ind - getcnt(t->l) - 1, t->r, r);
        l = t;
    } else {
        splitind(t->l, ind, l, t->l);
        r = t;
    }
    upd(l); upd(r);
}

int lower_bound(pnode t, key k) {
    if (!t) return 0;
    if (t->k >= k) return lower_bound(t->l, k);
    return lower_bound(t->r, k) + getcnt(t->l) + 1;
}

int upper_bound(pnode t, key k) {
    if (!t) return 0;
    if (t->k > k) return upper_bound(t->l, k);
    return upper_bound(t->r, k) + getcnt(t->l) + 1;
}

int count(pnode t, key k) {
    return upper_bound(t, k) - lower_bound(t, k);
}

key kth(pnode t, int ind) {
    if (ind == getcnt(t->l)) return t->k;
    if (getcnt(t->l) > ind) return kth(t->l, ind);
    return kth(t->r, ind - getcnt(t->l) - 1);
}

void insert(pnode &t, key k) {
    pnode r;
    splitval(t, k, t, r);
    t = merge(t, new node(k));
    t = merge(t, r);
}

void insert(pnode &t, int ind, key k) {
    pnode r;
    splitind(t, ind, t, r);
    t = merge(t, new node(k));
    t = merge(t, r);
}

void erase(pnode &t, key k) {
    pnode m, r;
    splitind(t, upper_bound(t, k), t, r);
    splitind(t, lower_bound(t, k), t, m);
    t = merge(t, r);
}

void eraseone(pnode &t, key k) {
    pnode m, r;
    splitind(t, lower_bound(t, k), t, r);
    splitind(r, 1, m, r);
    t = merge(t, r);
}

map<int, pnode> add, del;

signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int mode, t, x;
        cin >> mode >> t >> x;
        if (!add.count(x)) add[x] = nullptr;
        if (!del.count(x)) del[x] = nullptr;
        if (mode == 1) {
            insert(add[x], t);
        }   
        if (mode == 2) {
            insert(del[x], t);
        }
        if (mode == 3) {
            cout << upper_bound(add[x], t) - upper_bound(del[x], t) << '\n';
        }
    }
    return 0;
}