#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <ctime>
#include <queue>

using namespace std;

int k = 1;

struct node{
    node() : ans(0), open(0), close(0), left(0), right(0) {};
    int ans;
    int open;
    int close;
    int left;
    int right;
};

vector<node> tree;

node v;

node merge(node a, node b) {
    node c;
    c.left = a.left;
    c.right = b.right;
    int x = min(a.open, b.close);
    c.ans = a.ans + b.ans + 2 * x;
    c.open = a.open + b.open - x;
    c.close = a.close + b.close - x;
    return c;
}

node getAns(int a, int l, int r) {
    if (tree[a].left == l && tree[a].right == r)
        return tree[a];
    int m = (tree[a].left + tree[a].right) / 2;
    if (r <= m)
        return getAns(2 * a, l, r);
    if (m <= l)
        return getAns(2 * a + 1, l, r);
    return merge(getAns(2 * a, l, m), getAns(2 * a + 1, m, r));
}

int main() {
    int n;
    string s;
    cin >> s;
    n = (int)s.size();
    while (k < n)
        k *= 2;
    tree.resize(2 * k);
    for (int i = 0; i < n; i++) {
        if (s[i] == '(')
            tree[k + i].open = 1;
        else
            tree[k + i].close = 1;
    }
    for (int i = 0; i < k; i++) {
        tree[k + i].left = i;
        tree[k + i].right = i + 1;
    }
    for (int i = k - 1; i >= 1; i--)
        tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        cout << getAns(1, l - 1, r).ans << endl;
    }
    return 0;
}