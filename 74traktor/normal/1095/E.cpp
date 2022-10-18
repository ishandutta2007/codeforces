#include <bits/stdc++.h>

using namespace std;

int a[1000005];
int p[4000005];
int d[4000005];

void push(int i){
    if (2 * i + 2 < 4000005){
        d[2 * i + 1] += d[i];
        d[2 * i + 2] += d[i];
    }
    d[i] = 0;
}

void build(int i, int l, int r){
    if (r == l + 1) p[i] = a[l];
    else{
        int m = (r + l) / 2;
        build(2 * i + 1, l, m);
        build(2 * i + 2, m, r);
        p[i] = min(p[2 * i + 1], p[2 * i + 2]);
    }
}

void upd(int i, int l, int r, int lq, int rq, int dx){
    if (l >= rq || r <= lq) return;
    if (lq <= l && r <= rq){
        d[i] += dx;
        p[i] = p[i] + d[i];
        push(i);
    }
    else{
        int m = (r + l) / 2;
        upd(2 * i + 1, l, m, lq, rq, dx);
        upd(2 * i + 2, m, r, lq, rq, dx);
        p[i] = min(p[2 * i + 1] + d[2 * i + 1], p[2 * i + 2] + d[2 * i + 2]);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    if (n % 2 == 1){
        cout << 0 << endl;
        return 0;
    }
    string s;
    cin >> s;
    for (int i = 1; i <= n; ++i){
        if (s[i - 1] == '(') a[i] = a[i - 1] + 1;
        else a[i] = a[i - 1] - 1;
    }
    build(0, 1, n + 1);
    int ans = 0;
    for (int i = 0; i < n; ++i){
        if (s[i] == '('){
            upd(0, 1, n + 1, i + 1, n + 1, -2);
            //cout << i << " " << p[0] << endl;
            if (p[0] >= 0 && a[n] == 2) ans++;
            upd(0, 1, n + 1, i + 1, n + 1, 2);
        }
        else{
            upd(0, 1, n + 1, i + 1, n + 1, 2);
            if (p[0] >= 0 && a[n] == -2) ans++;
            upd(0, 1, n + 1, i + 1, n + 1, -2);
        }
    }
    cout << ans << endl;
    return 0;
}