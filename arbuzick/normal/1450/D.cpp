#include <bits/stdc++.h>
#define int long long
#define double long double
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
const int R = 1 << 19;
int t[R*2], fl[R*2];
void build(){
    for (int i = R*2-1; i > 0; --i)
        fl[i] = -1;
    for(int i = R-1; i > 0; --i)
        t[i] = t[i*2] + t[i*2+1];
}
void push(int node, int l, int r){
    if(fl[node] != -1){
        int m = (l+r)/2;
        fl[node*2] = fl[node];
        fl[node*2+1] = fl[node];
        t[node*2] = fl[node]*(m-l);
        t[node*2+1] = fl[node]*(r-m);
    }
    fl[node] = -1;
}
int get(int ql, int qr, int node = 1, int nl = 0, int nr = R){
    if (ql <= nl && nr <= qr)
        return t[node];
    if (qr <= nl || nr <= ql)
        return 0;
    push(node, nl, nr);
    int nm = (nl+nr)/2;
    return get(ql, qr, node*2, nl, nm) + get(ql, qr, node*2+1, nm, nr);
}
void assign(int ql, int qr, int val, int node = 1, int nl = 0, int nr = R){
    if(ql <= nl && nr <= qr){
        fl[node] = val;
        t[node] = val*(nr-nl);
        return;
    }
    if(qr <= nl || nr <= ql)
        return;
    push(node, nl, nr);
    int nm = (nl+nr)/2;
    assign(ql, qr, val, node*2, nl, nm);
    assign(ql, qr, val, node*2+1, nm, nr);
    t[node] = t[node*2] + t[node*2+1];
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t2;
    cin >> t2;
    while (t2--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i], a[i]--;
        vector<int> used(n), dist(n, 0), nxt(n, n), prv(n, -1);
        vector<int> st;
        for (int i = 0; i < n; ++i) {
            used[a[i]] = 1;
            while (!st.empty() && a[st.back()] > a[i]) {
                nxt[st.back()] = i;
                st.pop_back();
            }
            st.pb(i);
        }
        st.clear();
        for (int i = n-1; i >= 0; --i) {
            while (!st.empty() && a[st.back()] > a[i]) {
                prv[st.back()] = i;
                st.pop_back();
            }
            st.pb(i);
        }
        for (int i = 0; i < n; ++i)
            dist[a[i]] = max(dist[a[i]], nxt[i]-prv[i]-1);
        assign(0, n, 1);
        for (int i = 0; i < n; ++i) {
            int l = dist[i], r = n-i;
            if (l < r)
                assign(l, r, 0);
            if (!used[i])
                assign(0, r, 0);
        }
        for (int i = 0; i < n; ++i)
            cout << get(i, i+1);
        cout << '\n';
    }
    return 0;
}