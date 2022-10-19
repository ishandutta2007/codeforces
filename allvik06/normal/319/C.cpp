#include <bits/stdc++.h>
#define int long long
const int INF = 1e18;
using namespace std;

struct line {
    int k, b;
    double x;
    line() {

    }
    line(int kk, int bb) {
        k = kk;
        b = bb;
        x = INF;
    }
};

vector <line> st;
double f(line a, line b) {
    return (double)(b.b - a.b) / (double)(a.k - b.k);
}
void add(line a) {
    if (st.empty()) {
        st.push_back(a);
        return;
    }
    if (!st.empty() && a.k >= st.back().k) {
        return;
    }
    while (st.size() > 1 && st[st.size() - 2].x >= f(a, st.back())) {
        st.pop_back();
    }
    st.back().x = f(st.back(), a);
    st.push_back(a);
}

line get(double x) {
    int l = -1, r = st.size() - 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (st[m].x >= x) {
            r = m;
        }
        else {
            l = m;
        }
    }
    return st[r];
}
signed main() {
    int n;
    cin >> n;
    vector <int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n ; ++i) {
        cin >> b[i];
    }
    line tmp(b[0], 0);
    add(tmp);
    for (int i = 1; i < n; ++i) {
        tmp = get((double)a[i]);
        tmp.b = tmp.b + tmp.k * a[i];
        tmp.k = b[i];
        tmp.x = (double)INF;
        add(tmp);
    }
    tmp = get(a[n - 1]);
    cout << tmp.k * a[n - 1] + tmp.b;
    return 0;
}