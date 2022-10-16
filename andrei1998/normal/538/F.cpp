#include <iostream>
#include <algorithm>

#define NMAX 200005
using namespace std;

struct node {
    int st, dr;
    int sum;

    node *left, *right;

    node (int st = 0, int dr = 0, int sum = 0, node *left = NULL, node *right = NULL): st(st), dr(dr), sum(sum), left(left), right(right) {}
};

void ins (node *root, int pos) {
    if (root -> st == root -> dr && root -> st == pos) {
        root -> sum = 1;

        return ;
    }

    int mijl = (root -> st + root -> dr) >> 1;

    if (pos <= mijl) {
        if (root -> left == NULL)
            root -> left = new node(root -> st, mijl);
        else
            root -> left = new node(root -> left -> st, root -> left -> dr, root -> left -> sum, root -> left -> left, root -> left -> right);
        ins(root -> left, pos);
    }
    else {
        if (root -> right == NULL)
            root -> right = new node(mijl + 1, root -> dr);
        else
            root -> right = new node(root -> right -> st, root -> right -> dr, root -> right -> sum, root -> right -> left, root -> right -> right);
        ins(root -> right, pos);
    }

    root -> sum = 0;
    if (root -> left != NULL)
        root -> sum += root -> left -> sum;
    if (root -> right != NULL)
        root -> sum += root -> right -> sum;
}

int query (node *root, int st, int dr) {
    if (root -> st == st && root -> dr == dr)
        return root -> sum;

    int mijl = ((root -> st + root -> dr) >> 1);

    if (dr <= mijl) {
        if (root -> left != NULL)
            return query(root -> left, st, dr);
        else
            return 0;
    }
    else if (st > mijl) {
        if (root -> right != NULL)
            return query(root -> right, st, dr);
        else
            return 0;
    }
    else {
        int ans = 0;

        if (root -> left != NULL)
            ans += query(root -> left, st, mijl);
        if (root -> right != NULL)
            ans += query(root -> right, mijl + 1, dr);

        return ans;
    }
}

int n;
struct elem {
    int val, pos;
    node *root;

    elem (int val = 0): val(val) {}
} elems[NMAX];

bool operator< (const elem &a, const elem &b) {
    return a.val < b.val;
}

int query (int st, int dr, int val) { //Cate sunt intre st si dr si sunt < val
    node* root = elems[lower_bound(elems + 1, elems + n + 1, val) - elems - 1].root;

    return query(root, st, dr);
}

int v[NMAX];
int anss[NMAX];

int main()
{
    ios_base :: sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> v[i];

    elems[0].val = -1000000005;
    elems[0].root = new node(1, n);

    for (int i = 1; i <= n; i++) {
        elems[i].pos = i;
        elems[i].val = v[i];

        elems[i].root = NULL;
    }

    sort(elems + 1, elems + n + 1);
    for (int i = 1; i <= n; i++) {
        elems[i].root = new node(1, n, elems[i - 1].root -> sum, elems[i - 1].root -> left, elems[i - 1].root -> right);
        ins(elems[i].root, elems[i].pos);
    }

    /*int q = 1000;
    //cin >> q;

    int a, b, val;
    while (q--) {
        cin >> a >> b >> val;

        cout << query(a, b, val) << '\n';
    }*/

    int k;
    int st, dr;

    for (int i = 1; i <= n; i++) {
        for (k = 1; k < n; k++) {
            st = k * (i - 1) + 2;
            dr = k * i + 1;

            if (st > n)
                break;
            if (dr > n)
                dr = n;

            anss[k] += query(st, dr, v[i]);
        }
    }

    for (int i = 1; i < n; i++)
        cout << anss[i] << ' ';
    cout << endl;

    return 0;
}