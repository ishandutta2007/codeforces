#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define ll long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

int gcd(int a, int b) {
    if (!a)
        return b;
    return gcd(b % a, a);
}

struct Node{
    int mn, cnt, g;
    Node() {
        mn = INT_MAX;
        cnt = 0;
        g = 0;
    }
};

Node merge(Node a, Node b) {
    Node ans;
    if (a.mn == b.mn)
        ans.cnt = a.cnt + b.cnt;
    if (a.mn < b.mn)
        ans.cnt = a.cnt;
    if (a.mn > b.mn)
        ans.cnt = b.cnt;
    ans.mn = min(a.mn, b.mn);
    ans.g = gcd(a.g, b.g);
    return ans;
}

vector <int> a;
vector <Node> tr;

void build(int v, int vl, int vr) {
    if (vr - vl == 1) {
        tr[v].mn = a[vl], tr[v].cnt = 1, tr[v].g = a[vl];
        return;
    }
    int vm = vl + vr >> 1;
    build(2 * v, vl, vm), build(2 * v + 1, vm, vr);
    tr[v] = merge(tr[2 * v], tr[2 * v + 1]);
}

Node get(int v, int vl, int vr, int l, int r) {
    if (vr <= l || r <= vl)
        return Node();
    if (l <= vl && vr <= r)
        return tr[v];
    int vm = vl + vr >> 1;
    return merge(get(2 * v, vl, vm, l, r), get(2 * v + 1, vm, vr, l, r));
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    a.resize(n);
    forn (i, 0, n)
        cin >> a[i];
    tr.resize(4 * n);
    build(1, 0, n);
    int q;
    cin >> q;
    while (q --> 0) {
        int l, r;
        cin >> l >> r;
        l--;
        Node ans = get(1, 0, n, l, r);
        if (ans.g == ans.mn) 
            cout << r - l - ans.cnt;
        else 
            cout << r - l;
        cout << "\n";
    }
    return 0;
}