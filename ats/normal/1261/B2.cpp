#include <bits/stdc++.h>

using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

template <class T> struct Fenwick {
    int n;
    V<T> seg;
    Fenwick(int _n = 0) : n(_n), seg(n + 1) {}
    /// ix
    void add(int i, T x) {
        i++;
        while (i <= n) {
            seg[i] += x;
            i += i & -i;
        }
    }
    /// [0, i)sum
    T sum(int i) {
        T s = 0;
        while (i > 0) {
            s += seg[i];
            i -= i & -i;
        }
        return s;
    }
    /// [a, b)sum
    T sum(int a, int b) { return sum(b) - sum(a); }
    /// sum[0, idx) >= xidx(sum[0, n) < x  n+1)
    int sum_lower_bound(T x) {
        if (x <= 0)
            return 0;
        int res = 0, len = 1;
        while (2 * len <= n)
            len *= 2;
        for (; len >= 1; len /= 2) {
            if (res + len <= n && seg[res + len] < x) {
                res += len;
                x -= seg[res];
            }
        }
        return res + 1;
    }
};

struct Query {
    int k;
    int pos;
    int idx;
    bool operator<(const Query &r){
        return k < r.k;
    }
} ;
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> B(N);
    vector<pair<int, int>> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i].first;
        B[i] = A[i].first;
        A[i].first *= -1;
        A[i].second = i;
    }
    sort(A.begin(), A.end());
    int Q;
    cin >>Q;
    int k,p;
    vector<Query> q(Q);
    for(int i=0;i<Q;i++){
        cin >>q[i].k>>q[i].pos;
        q[i].idx = i;
    }
    sort(q.begin(),q.end());
    int cur = 0;
    vector<int> res(Q);
    Fenwick<int> ft(N);
    for(int i=0;i<Q;i++){
        int k = q[i].k;
        int pos = q[i].pos;
        while (cur < k){
          //  cerr <<i <<" " << "add " << A[cur].second<<endl;
            ft.add(A[cur].second, 1);
            cur++;
        }
        res[q[i].idx] = B[ft.sum_lower_bound(pos) - 1];
    }
    
    for(int i=0;i<Q;i++){
        cout << res[i]<<endl;
    }
}