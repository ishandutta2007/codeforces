#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;



#define int int64_t
#define double long double

typedef tree<pair<double, double>, null_type, less<pair<double, double>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const double eps = 1e-12;

int get_xy(vector<double> x, vector<double> y) {
    int n = x.size();
    int p[n];
    iota(p, p + n, 0);
    sort(p, p + n, [&](int a, int b) {
        if(abs(x[a] - x[b]) < eps) {
            return y[a] < y[b];
        } else {
            return x[a] < x[b];
        }
    });
    ordered_set me;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        //cout << x[p[i]] << ' ' << y[p[i]] << endl;
        ans += me.order_of_key({y[p[i]] + eps, 0});
        me.insert({y[p[i]], x[p[i]]});
    }
    return ans;
}



signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, w;
    cin >> n >> w;
    int x[n], v[n];
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> v[i];
    }
    vector<double> X(n), Y(n);
    
    for(int i = 0; i < n; i++) {
        X[i] = 1. * (v[i] - w) / x[i];
        Y[i] = -1. * (v[i] + w) / x[i];
    }
    if(w == 0) {
        int ans = 0;
        ordered_set me;
        for(int i = 0; i < n; i++) {
            double t = 1. * x[i] / v[i];
            //cout << t << endl;
            ans += me.order_of_key({t + eps, 0}) - me.order_of_key({t - eps, 0});
            me.insert({t, i});
        }
        cout << ans << endl;
        return 0;
    } else {
        cout << get_xy(X, Y) << endl;
    }
    return 0;
}