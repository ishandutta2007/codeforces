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
#include <random>
#include <functional>

using namespace std;

#define F first
#define S second
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << ": "; for (auto& xxxx: a) cerr << xxxx << " "; cerr << endl;
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
typedef long double dbl;
typedef long long ll;
const int N = -1;
const ll INF = 1.01e9;
typedef vector<int> vi;



mt19937 rnd;

struct Node {
    Node *l, *r;
    int y, x;
    int cnt;
    int val;
    Node(int xx): l(NULL), r(NULL), y(rnd()), x(xx), cnt(1), val(xx) {}
};




int getCnt(Node* v) {
    return (v == NULL)? 0: v->cnt;
}

int getVal(Node* v) {
    return (v == NULL)? INF: v->val;
}

void upd(Node* v) {
    v->cnt = getCnt(v->l) + getCnt(v->r) + 1;
    v->val = min(getVal(v->l), min(getVal(v->r) - 1 - getCnt(v->l), v->x - getCnt(v->l))); 
}

Node* merge(Node* l, Node* r) {
    if (l == NULL) return r;
    if (r == NULL) return l;
    if (l->y > r->y) {
        l->r = merge(l->r, r);
        upd(l);
        return l;
    }
    else {
        r->l = merge(l, r->l);
        upd(r);
        return r;
    }
}

void split(Node* v, Node* &l, Node* &r, int key) {
    if (v == NULL) {
        l = r = NULL;
        return;
    }
    if (v->x < key) {
        split(v->r, v->r, r, key);
        upd(v);
        l = v;
    }  
    else {
        split(v->l, l, v->l, key);
        upd(v);
        r = v;
    }
}

Node* head;



void add(int x) {
    x--;
    //db(x);
    Node *l, *r;
    split(head, l, r, x);
    Node* tmp = new Node(x);
    head = merge(l, merge(tmp, r));
}

int main(){
#ifdef HOME 
    assert(freopen("E.in", "r", stdin));
#endif
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    vector<int> answer;
    head = NULL;

    multiset<int> down;
    //for (auto x: a) {
    for (int i = 0; i < sz(a); i++) {
        int x = a[i];
        down.insert(x);
        int mx = *down.rbegin();
        if (mx > -(int)down.size()) {
            down.erase(down.find(mx));
            add(mx);
        }

        int g = min(0, getVal(head) + (int)down.size());
        //db2(g, down.size());
        int res = -down.size() + (i + 1 - down.size()) + g;

        answer.pb(res);
    }

    for (auto x: answer) {
        printf("%d\n", x);
    }
    puts("");




    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}