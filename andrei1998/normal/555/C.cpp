#include <iostream>
#include <algorithm>

using namespace std;

struct node {
    int st, dr;
    int maxim;
    int lazy;

    node *left, *right;

    node (int _st = 0, int _dr = 0, int _maxim = 0, int _lazy = 0, node* _left = NULL, node* _right = NULL): st(_st), dr(_dr), maxim(_maxim), lazy(_lazy), left(_left), right(_right) {}
} *root_lin, *root_col;

void update (node *t, int st, int dr, int val) {
    if (t -> st == st && t -> dr == dr) {
        if (val > t -> lazy)
            t -> lazy = val;
        if (val > t -> maxim)
            t -> maxim = val;
        return ;
    }

    int mijl = ((t -> st + t -> dr) >> 1);
    if (dr <= mijl) {
        if (t -> left == NULL)
            t -> left = new node(t -> st, mijl);
        update(t -> left, st, dr, val);
    }
    else if (st > mijl) {
        if (t -> right == NULL)
            t -> right = new node(mijl + 1, t -> dr);
        update(t -> right, st, dr, val);
    }
    else {
        if (t -> left == NULL)
            t -> left = new node(t -> st, mijl);
        if (t -> right == NULL)
            t -> right = new node(mijl + 1, t -> dr);
        update(t -> left, st, mijl, val);
        update(t -> right, mijl + 1, dr, val);
    }

    if (val > t -> maxim)
        t -> maxim = val;
}

int query (node *t, int st, int dr) {
    //cout << "query " << t -> st << ' ' << t -> dr << ' ' << st << ' ' << dr << endl;
    if (t -> st == st && t -> dr == dr)
        return t -> maxim;

    int mijl = ((t -> st + t -> dr) >> 1);
    if (dr <= mijl) {
        if (t -> left == NULL)
            return t -> lazy;
        else
            return max(t -> lazy, query(t -> left, st, dr));
    }
    else if (st > mijl) {
        if (t -> right == NULL)
            return t -> lazy;
        else
            return max(t -> lazy, query(t -> right, st, dr));
    }
    else {
        int aux;
        if (t -> left == NULL)
            aux = t -> lazy;
        else
            aux = max(t -> lazy, query(t -> left, st, mijl));

        if (t -> right == NULL)
            return max(aux, t -> lazy);
        else
            return max(aux, max(t -> lazy, query(t -> right, mijl + 1, dr)));
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    int n = 0;
    cin >> n;

    root_lin = new node(1, n);
    root_col = new node(1, n);

    int q = 0;
    cin >> q;

    int col, lin;
    char l;

    int aux;
    while (q--) {
        cin >> col >> lin >> l;

        if (l == 'U') {
            aux = query(root_col, col, col) + 1;
            if (aux == lin + 1) {
                cout << "0\n";
                continue;
            }

            update(root_lin, aux, lin, col);
            update(root_col, col, col, lin);

            cout << lin - aux + 1 << '\n';
        }
        else {
            aux = query(root_lin, lin, lin) + 1;
            if (aux == col + 1) {
                cout << "0\n";
                continue;
            }

            update(root_col, aux, col, lin);
            update(root_lin, lin, lin, col);

            cout << col - aux + 1 << '\n';
        }
    }

    return 0;
}