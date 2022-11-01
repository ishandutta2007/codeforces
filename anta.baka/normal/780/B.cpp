#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

int n;
ld x[60000];
ld v[60000];

bool solve(ld t) {
    bool flag = true;
    ld lf, rg;
    for(int i = 0; i < n && lf <= rg; i++)
        if(flag) {
            lf = x[i] - t * v[i];
            rg = x[i] + t * v[i];
            flag = false;
        } else {
            lf = max(lf, x[i] - t * v[i]);
            rg = min(rg, x[i] + t * v[i]);
        }
    return (lf <= rg);
}

int main() {
    ios::sync_with_stdio(0);
    //freopen("in.txt", "r", stdin);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> x[i];
    for(int i = 0; i < n; i++) cin >> v[i];
    ld bl = 0, br = 1e9;
    for(int iter=0; iter<100; iter++) {
        ld bm = (bl + br) / 2;
        if(solve(bm)) br = bm;
        else bl = bm;
    }
    cout.precision(6);
    cout << fixed << bl;
}