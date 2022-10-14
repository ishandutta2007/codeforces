#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct se {
    int par, size, x, next, beg, en;
    se () {}
    se (int _x) {
        par = _x;
        x = _x;
        size = 1;
        next = -1;
        beg = x;
        en = x;
    }
};

int parent(int x, vector <se> &p) {
    if (p[x].par == x) {
        return x;
    }
    p[x].par = parent(p[x].par, p);
    return p[x].par;
}

int union_sets(int a, int b, vector <se> &p) {
    a = parent(a, p);
    b = parent(b, p);
    if (p[a].size < p[b].size) {
        swap(a, b);
    }
    p[p[a].en].next = p[b].beg;
    p[a].en = p[b].en;
    p[b].par = a;
    p[a].size += p[b].size;
    return a;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector <se> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = se(i);
    }
    int ans = -1;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        ans = union_sets(x, y, p);
    }
    while (ans != -1) {
        cout << ans + 1 << " ";
        ans = p[ans].next;
    }
    return 0;
}