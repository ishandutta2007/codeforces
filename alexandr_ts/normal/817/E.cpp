#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define mp make_pair
#define pb push_back
#define F first
#define S second
using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1e9 + 7;
const int M = 1e3 + 5;
const int N = 1e6 + 5;
const int POW = 28;
const ll MOD = 1000 * 1000 * 1000 + 7;

struct node {
    int sum, i;
    node *t0, *t1;
    node() {}
    node(int sum, int i):sum(sum), i(i), t0(NULL), t1(NULL){}
};

void add(node* root, int p, int pw, int val) {
    if ((1 << pw) & p) {
        root->sum += val;
        if (pw == 0) {
            if (!root->t1)
                root->t1 = new node(0, pw - 1);
            root->t1->sum += val;
            return;
        }
        if (!root->t1)
            root->t1 = new node(0, pw - 1);
        add(root->t1, p, pw - 1, val);
    }
    else {
        root->sum += val;
        if (pw == 0) {
            if (!root->t0)
                root->t0 = new node(0, pw - 1);
            root->t0->sum += val;
            return;
        }
        if (!root->t0)
            root->t0 = new node(0, pw - 1);
        add(root->t0, p, pw - 1, val);
    }
}

int Sum(node* v) {
    if (!v) return 0;
    return v->sum;
}

int get(node* root, int p, int l, int pw, int side = 0) {
    if (!root) return 0;
    //cout << p << " " << l << " " << pw << " " << root->sum << " " << Sum(root->t0) << " " << side << endl;
    if (pw == -1) return 0;
    if (((1 << pw) & l) && !((1 << pw) & p))
        return Sum(root->t0) + get(root->t1, p, l, pw - 1, 1);
    if (!((1 << pw) & l) && !((1 << pw) & p))
        return get(root->t0, p, l, pw - 1, 0);
    if (((1 << pw) & l) && ((1 << pw) & p))
        return Sum(root->t1) + get(root->t0, p, l, pw - 1, 0);
    if (!((1 << pw) & l) && ((1 << pw) & p))
        return get(root->t1, p, l, pw - 1, 1);
}

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    node *root = new node(0, POW);

    fr(i, n) {
        int t, p;
        cin >> t >> p;
        if (t == 1) {
            add(root, p, POW, 1);
        }
        if (t == 2) {
            add(root, p, POW, -1);
        }
        if (t == 3) {
            int l;
            cin >> l;
            cout << get(root, p, l, POW) << endl;
        }
    }
}