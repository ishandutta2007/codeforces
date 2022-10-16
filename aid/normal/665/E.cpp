#include <iostream>

using namespace std;

struct Node {
    int val;
    Node *l, *r;

    Node(): val(0), l(0), r(0) {}
};

const int MAXN = 1000 * 1000 + 5, LOGX = 30;
int a[MAXN], s[MAXN], freeNode;
Node nodes[(LOGX + 5) * MAXN];

Node *newNode() {
    return nodes + freeNode++;
}

int get(Node *v, int x, int k, int h) {
    if(h == -1)
        return v->val;
    if(k & (1 << h)) {
        if(x & (1 << h)) {
            if(!v->l)
                v->l = newNode();
            return get(v->l, x, k, h - 1);
        }
        else {
            if(!v->r)
                v->r = newNode();
            return get(v->r, x, k, h - 1);
        }
    }
    else {
        if(x & (1 << h)) {
            if(!v->r)
                v->r = newNode();
            return (v->l? v->l->val : 0) + get(v->r, x, k, h - 1);
        }
        else {
            if(!v->l)
                v->l = newNode();
            return (v->r? v->r->val : 0) + get(v->l, x, k, h - 1);
        }
    }
}

void update(Node *v, int x, int h) {
    v->val++;
    if(h == -1)
        return;
    if(x & (1 << h)) {
        if(!v->r)
            v->r = newNode();
        update(v->r, x, h - 1);
    }
    else {
        if(!v->l)
            v->l = newNode();
        update(v->l, x, h - 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    s[0] = 0;
    for(int i = 0; i < n; i++)
        s[i + 1] = (s[i] ^ a[i]);
    n++;
    Node *root = newNode();
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        ans += get(root, s[i], k, LOGX - 1);
        update(root, s[i], LOGX - 1);
    }
    cout << ans << '\n';
    return 0;
}