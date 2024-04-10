#include <bits/stdc++.h>

using namespace std;

#define int long long

string s;
long long p[400005];
long long INF = 1e9 + 7;

void build(int i, int l, int r){
    if (l == r - 1){
        if (s[l - 1] == '1')
            p[i] = 1;
    }
    else{
        int m = (r + l) / 2;
        build(2 * i + 1, l, m);
        build(2 * i + 2, m, r);
        p[i] = p[2 * i + 1] + p[2 * i + 2];
    }
}


int res(int i, int l, int r, int lq, int rq){
    //cout << l << " " << r << " " << lq << " " << rq << endl;
    if (lq >= r || rq <= l){
        return 0;
    }
    if (lq <= l && r <= rq)
        return p[i];
    int m = (l + r) / 2;
    return res(2 * i + 1, l, m, lq, rq) + res(2 * i + 2, m, r, lq, rq);
}

long long st(int a, int n){
    if (n == 0)
        return 1;
    if (n % 2 == 0){
        int u = st(a, n / 2);
        u = u % INF;
        return u * u % INF;
    }
    return ((a % INF) * (st(a, n - 1) % INF)) % INF;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    cin >> s;
    build(1, 1, n + 1);
    for (int i = 0; i < q; ++i){
        int lq, rq;
        cin >> lq >> rq;
        int prom = res(1, 1, n + 1, lq, rq + 1);
        int prom1 = rq - lq + 1 - prom;
        //cout << prom << " " << prom1 << endl;
        //cout << st(2, prom) << endl;
        //int pr = st(2, prom) - 1;
        //cout << (pr + (max(st(2, prom1) - 1, (int)0) % INF) * pr) % INF << endl;
        cout << (st(2, prom) - 1) * st(2, prom1) % INF << endl;
    }
    return 0;
}