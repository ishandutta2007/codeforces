#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define mod 1000000007
#define inf 1000000000

struct node {
    node* son[2];
    int key;
    int le, here, ri;
    int lazy;

    node() {
        son[0] = son[1] = NULL;
        key = -1;
        le = here = ri = lazy = 0;
    }
} *nil;

vector<int> ord;

void prop(node *act) {
    if (act == nil) return;
    if (act->lazy == 0) return;

    act->son[0]->le += act->lazy;
    act->son[0]->here += act->lazy;
    act->son[0]->ri += act->lazy;
    act->son[0]->lazy += act->lazy;

    act->son[1]->le += act->lazy;
    act->son[1]->here += act->lazy;
    act->son[1]->ri += act->lazy;
    act->son[1]->lazy += act->lazy;

    act->lazy = 0;
}

void compute(node* act) {
    if (act == nil) return;
    prop(act);

    act->le = act->ri = act->here;
    if (act->son[0] != nil)
        act->le = act->son[0]->le;
    if (act->son[1] != nil)
        act->ri = act->son[1]->ri;
}

void rot_left(node* &act) {
    prop(act);
    prop(act->son[0]);

    node* aux = act->son[0];
    act->son[0] = aux->son[1];
    aux->son[1] = act;
    act = aux;

    compute(act->son[1]);
    compute(act);
}

void rot_right(node* &act) {
    prop(act);
    prop(act->son[1]);

    node* aux = act->son[1];
    act->son[1] = aux->son[0];
    aux->son[0] = act;
    act = aux;

    compute(act->son[0]);
    compute(act);
}

void balance(node* &act) {
    if (act == nil) return;

    if (act->key < act->son[0]->key)
        rot_left(act);
    if (act->key < act->son[1]->key)
        rot_right(act);

}

bool check(node* act, int val) {
    prop(act);

    if (act == nil) return false;

    if (act->here == val) return true;
    if (val < act->here)
        return check(act->son[0], val);
    else
        return check(act->son[1], val);
}

void insert(node* &act, int val) {
    prop(act);

    if (act == nil) {
        act = new node();
        act->son[0] = act->son[1] = nil;
        act->key = rand() % mod;
        act->le = act->here = act->ri = val;
        return;
    }

    if (val < act->here)
        insert(act->son[0], val);
    else
        insert(act->son[1], val);

    balance(act);
    compute(act);
}

void remove(node* &act, int val) {
    if (act == nil) {
        cerr << "Error act == nil\n";
        exit(101);
        return;
    }
    prop(act);

    if (act->son[0] == nil && act->son[1] == nil) {
        act = nil;
        return;
    }

    if (act->here == val) {
        if (act->son[0]->key > act->son[1]->key)
            rot_left(act);
        else
            rot_right(act);
    }

    if (act->here == val) {
        cerr << "Error here == val\n";
        exit(102);
        return;
    }

    if (val < act->here)
        remove(act->son[0], val);
    else
        remove(act->son[1], val);

    compute(act);
}

void add(node* &act, int l, int r) {
    if (act == nil) return;
    prop(act);

    if (l <= act->le && act->ri <= r) {
        act->le++;
        act->ri++;
        act->here++;
        act->lazy++;
        return;
    }

    if (l < act->here) add(act->son[0], l, r);
    if (r > act->here) add(act->son[1], l, r);

    if (l <= act->here && act->here <= r)
        act->here++;

    compute(act);
}

int first_greater(node* act, int val) {
    if (act == nil) {
        cerr << "error";
        return 0;
    }

    prop(act);
    if (act->son[0] == nil && act->son[1] == nil)
        return act->here;

    if (act->son[0] != nil && act->son[0]->ri > val)
        return first_greater(act->son[0], val);

    if (act->here > val) return act->here;

    return first_greater(act->son[1], val);
}

void walk(node* act) {
    if (act == nil) return;
    prop(act);

    walk(act->son[0]);
    ord.pb(act->here);
    walk(act->son[1]);
}

int n, i, l, r;
node* Head;

void print() {
    ord.clear();
    walk(Head);
    for (auto e : ord) if (e <= inf) cerr << e << ' ';
    cerr << '\n';
}

int main()
{
    //freopen("test.in","r",stdin);
    srand(time(NULL));

    nil = new node();
    Head = nil;
    cin >> n;

    insert(Head, 0);
    for (i = 1; i <= n + 3; i++) insert(Head, inf + i);

    for (i = 1; i <= n; i++) {
        cin >> l >> r;

        /*cerr << "bef ";
        print();*/

        int vv = first_greater(Head, r - 1);
        remove(Head, vv);

        /*cerr << "mid ";
        print();*/

        if (l <= r - 1) add(Head, l, r - 1);

        /*cerr << "mid2 ";
        print();*/

        insert(Head, l);

        //cerr << "aft ";
        //print();

    }

    walk(Head);
    for (i = 0; ord[i] <= inf; i++);

    cout << i - 1;

    return 0;
}