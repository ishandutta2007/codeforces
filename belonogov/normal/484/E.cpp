#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 1e5 + 10;
const long long INF = 1e9 + 19;

struct Data {
    int left, right, val, len;
    Data(int x):left(x), right(x), val(x), len(1) { }
};

struct Node {
    Node *l, *r;
    Data data;
    Node(int x): l(NULL), r(NULL), data(x) { }
};

int n, m;
int a[N];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

Data merge(Data A, Data B) {
    Data C(0);
    C.len = A.len + B.len;
    C.left = (A.left == A.len)? A.len + B.left: A.left;
    C.right = (B.right == B.len)? B.len + A.right: B.right;
    C.val = max(max(A.val, B.val), A.right + B.left);
    return C;
}

void upd(Node * v) {
    v->data = merge(v->l->data, v->r->data);
}

Node * build(int ll, int rr) {
    if (ll + 1 == rr) {
        return new Node(1);
    }
    Node * v = new Node(0);
    v->l = build(ll, (ll + rr) / 2);
    v->r = build((ll + rr) / 2, rr);
    upd(v);
    return v;
}

Node * add(Node * v, int ll, int rr, int pos) {
    if (pos < ll) return v;
    if (rr <= pos) return v;
    if (ll + 1 == rr) {
        return new Node(0);
    }
    Node * u = new Node(0);
    u->l = add(v->l, ll, (ll + rr) / 2, pos);
    u->r = add(v->r, (ll + rr) / 2, rr, pos);
    upd(u);
    return u;
}

Data getMaxLen(Node * v, int ll, int rr, int l, int r) {
    if (ll >= r || l >= rr) return Data(0);
    if (l <= ll && rr <= r) {
        return v->data;
    }
    auto r1 = getMaxLen(v->l, ll, (ll + rr) / 2, l, r);
    auto r2 = getMaxLen(v->r, (ll + rr) / 2, rr, l, r);
    return merge(r1, r2);
}

void solve() {
    vector < pair < int, int > > tmp;
    vector < pair < int, Node * > > ver;
    for (int i = 0; i < n; i++)
        tmp.pb(mp(a[i], i));
    sort(tmp.begin(), tmp.end());
    ver.pb(mp(0, build(0, n)));
    for (int i = 0; i < (int)tmp.size(); ) {
        int j = i;
        Node * head = ver.back().sc;
        for (; i < (int)tmp.size() && tmp[j].fr == tmp[i].fr; i++) {
            head = add(head, 0, n, tmp[i].sc);
        }
        ver.pb(mp(tmp[j].fr, head));
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int l, r, w;
        scanf("%d%d%d", &l, &r, &w);
        l--;
        int ll = 0;
        int rr = ver.size() - 1;
        while (rr - ll > 1) {
            int mid = (ll + rr) / 2;
            int tmp = getMaxLen(ver[mid].sc, 0, n, l, r).val;
            if (tmp >= w)
                ll = (ll + rr) / 2;
            else
                rr = (ll + rr) / 2;
        }
        printf("%d\n", ver[rr].fr);
    }



}

void printAns() {

}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
            printAns();
        }
    }
    else {
        stress();
    }

    return 0;
}