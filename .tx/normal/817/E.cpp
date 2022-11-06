#include <bits/stdc++.h>
#ifdef JLOCAL
#include "stress.h"
#endif
using namespace std;

#define rep(i, z, n) for (int i = (z); i < int(n); ++i)
#define repr(i, n, z) for (int i = int(n) - 1; i >= (z); --i)
#define shl(n) (1 << (n))
#define hbit(n, i) (((n) >> (i)) & 1)

#define STRESS 0
using lint = long long;

struct node {
    node* ch[2] = {0, 0};
    int size = 0;
};

void add(node* n, int x) {
    repr(i, 30, 0) {
        int c = hbit(x, i);
        if (n->ch[c] == 0) {
            n->ch[c] = new node();
        }
        n = n->ch[c];
        n->size++;
    }
}

void rem(node* n, int x) {
    repr(i, 30, 0) {
        int c = hbit(x, i);
        n = n->ch[c];
        n->size--;
    }
}

int get(node* n, int y, int l) {
    int res = 0;
    repr(i, 30, 0) {
        if (!n) {
            break;
        }
        int tz = hbit(y, i);
        if (hbit(l, i)) {
            res += n->ch[tz] ? n->ch[tz]->size : 0;
            n = n->ch[tz ^ 1];
        } else {
            n = n->ch[tz];
        }
    }
    return res;
}

void solve(istream& cin, ostream& cout) {
    int n;
    cin >> n;
    node* root = new node();
    rep(i, 0, n) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            add(root, x);
        } else if (t == 2) {
            int x;
            cin >> x;
            rem(root, x);
        } else {
            int y, l;
            cin >> y >> l;
            cout << get(root, y, l) << "\n";
        }
    }
}

int main() {
#if !defined(JLOCAL) || !STRESS
#ifdef JLOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve(cin, cout);
#else
    srand();
    for (int ti = 0; ti < 100; ti++) {
        stress::gen();
        stress::stupid();
        ifstream in("input.txt");
        ofstream out("output.txt");
        solve(in, out);
        out.flush();
        stress::check();
    }
    cout << "ok" << endl;
#endif
    return 0;
}//jpnxoi