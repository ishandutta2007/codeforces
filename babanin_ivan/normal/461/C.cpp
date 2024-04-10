#include <iostream> 
#include <cstdio> 
#include <set> 
#include <map> 
#include <vector> 
#include <queue> 
#include <stack> 
#include <cmath> 
#include <algorithm> 
#include <cstring> 
#include <bitset> 
#include <ctime> 
#include <sstream>
#include <stack> 
#include <cassert> 
#include <list> 
#include <deque>
//#include <unordered_set> 
using namespace std;
typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define mp make_pair 
#define pb push_back
#define y1 botva
#define all(s) s.begin(), s.end() 
void solve();

#define NAME "changemeplease"
int main() {
#ifdef YA 
    //cerr << NAME << endl;
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout); 
    clock_t start = clock();
#else 
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
#endif 
    ios_base::sync_with_stdio(false);
    cout << fixed;
    cout.precision(10);
    int t = 1;
    //cin >> t;  
    for (int i = 1; i <= t; ++i) {
        //cout << "Case #" << i << ": ";
        solve();
    }
#ifdef YA 
    //cout << "\n\n\nTime:" << ((clock() - start) / 1.0 / CLOCKS_PER_SEC);
#endif 
    return 0;
}

int n, q;

struct tree {
    tree* l;
    tree* r;
    int val;
    int sum;
    bool rev;
    bool ch;
    int y;
    int cnt;
};

#define getSize(v) ((v)?((v)->cnt):0)
#define getSum(v) ((v)?((v)->sum):0)
#define merge merg

tree t[200000];
int kt;

int random() {
    return (rand() << 15) ^ rand();
}

tree* newNode(int y, int val) {
    t[kt].y = y;
    t[kt].val = val;
    t[kt].l = t[kt].r = NULL;
    t[kt].sum = val;
    t[kt].cnt = 1;
    t[kt].rev = t[kt].ch = 0;
    kt++;
    return &t[kt - 1];
}

void relax(tree*& v) {
    if (v == NULL)
        return ;
    if (v->rev) {
        swap(v->l, v->r);
        v->rev = false;
        if (v->l) {
            v->l->rev = !v->l->rev;
        }
        if (v->r) {
            v->r->rev = !v->r->rev;
        }
    }
}

void calc(tree* v) {
    if (v == NULL)
        return ;
    v->cnt = 1 + getSize(v->l) + getSize(v->r);
    relax(v->l);
    relax(v->r);
    v->sum = v->val + getSum(v->l) + getSum(v->r);
}

void split(tree* v, int x, tree*& l, tree*& r) {
    if (v == NULL) {
        l = r = NULL;
        return ;
    }
    relax(v);
    if (x <= getSize(v->l)) {
        r = v;
        split(v->l, x, l, r->l);
    }
    else {
        l = v;
        split(v->r, x - getSize(v->l) - 1, l->r, r);
    }
    calc(l);
    calc(r);
}

tree* merge(tree* l, tree* r) {
    if (l == NULL)
        return r;
    if (r == NULL)
        return l;
    relax(l);
    relax(r);
    tree* res;
    if (l->y > r->y) {
        res = l;
        res->r = merge(l->r, r);
    }
    else {
        res = r;
        res->l = merge(l, r->l);
    }
    calc(res);
    return res;
}

void solve() {
    cin >> n >> q;
    tree* root = NULL;
    
    for (int i = 0; i < n; ++i) {
        root = merge(root, newNode(random(), 1));
    }
    
    int curw = n;

    for (int t = 0; t < q; ++t) {
        int type;
        cin >> type;
        if (type == 1) {
            int p;
            cin >> p;
            //++p;
            int pr = curw - p;
            curw = max(p, pr);
            tree* left;
            tree* right;
            split(root, p, left, right);
            int com = min(p, pr);

            tree* leftleft;
            tree* leftr;
            tree* rightleft;
            tree* rightr;

            split(left, p - com, leftleft, leftr);
            split(right, com, rightleft, rightr);
            
            vector <tree*> tmp1(com, 0);
            vector <tree*> tmp2(com, 0);
            for (int i = 0; i < com; ++i) {
                split(leftr, 1, tmp1[i], leftr);
                split(rightleft, 1, tmp2[i], rightleft);
            }
            for (int i = 0; i < com; ++i) {
                tmp2[i]->val += tmp1[com - i - 1]->val;
                tmp2[i]->sum += tmp1[com - i - 1]->val;
            }
            root = tmp2[0];
            for (int i = 1; i < com; ++i) {
                root = merge(root, tmp2[i]);
            }
            if (leftleft != NULL) {
                leftleft->rev = !leftleft->rev;
                root = merge(root, leftleft);
            }
            else {
                root = merge(root, rightr);
            }
        }
        else {
            int l, r;
            cin >> l >> r;
            //++l;
            //++r;

            tree* left;
            tree* right;
            tree* middle;
            tree* rightright;
            split(root, l, left, right);
            split(right, r - l, middle, rightright);
            cout << getSum(middle) << endl;
            root = merge(left, middle);
            root = merge(root, rightright);
        }
    }
}