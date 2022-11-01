/// Alexandr Tsaplin 19.08.16

#include "bits/stdc++.h"
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define TASK_NAME "salesman"

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 1e5;
const ll INF = 2e16 + 1;
const ll MOD = 1e9 + 7;
const int BITS = 30;

struct node {
    int cnt;
    int num;
    node *l, *r;
    node() {}
    node (int cnt, int num): cnt(cnt), num(num), l(NULL), r(NULL) {}
};

void inc(node *root, int num) {
    //cout << root->num << endl;
    node *v = root;
    v->cnt++;
    for (int i = BITS; i >= 0; i--) {
        if (num & (1 << i)) {
            if (!v->r)
                v->r = new node(0, v->num + (1 << i));
            v = v->r;
            v->cnt++;
        }
        else {
            if (!v->l)
                v->l = new node(0, v->num);
            v = v->l;
            v->cnt++;
        }
        //cout << i << " " << v->num << " " << v->cnt <<  endl;
    }
}

void dec(node *root, int num) {
    node *v = root;
    v->cnt--;
    for (int i = BITS; i >= 0; i--) {
        if (num & (1 << i))
            v = v->r;
        else
            v = v->l;
        v->cnt--;
//        if (v->cnt == 0) {
//            //cout << "!! " << v->num << endl;
//            //v = NULL;
//            break;
//        }
    }
}
//
int get(node *root, int num) {
    int ans = 0;
    node *v = root;
    for (int i = BITS; i >= 0; i--) {
        if (!v->r || v->r->cnt <= 0) {
            ans += (1 << i) & num;
            v = v->l;
        }
        else if (!v->l || v->l->cnt <= 0) {
            //cout << "!!" << " " << v->num << " " << num << endl;
            if (!(num & (1 << i)))
                ans += (1 << i);
            v = v->r;
        }
        else {
            assert(v->l && v->r);
            if (!(num & (1 << i))) {
                ans += (1 << i);
                v = v->r;
            }
            else {
                ans += (1 << i);
                v = v->l;
            }
        }
        //cout << v->num << endl;
    }
    //cout << "num " << v->num << endl;
    return ans;
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    int n;
    cin >> n;
    node *root = new node(0, 0);
    inc(root, 0);

    fr(i1, n) {
        char typ;
        int x;
        cin >> typ >> x;
        if (typ == '+') {
            inc(root, x);
        }
        else if (typ == '-') {
            dec(root, x);
        }
        else {
            cout << get(root, x) << endl;
        }
    }
}