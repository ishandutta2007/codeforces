#include <bits/stdc++.h>

using namespace std;

#define int long long

int a[300005];
int pref[300005];
int dp[300005];
int dp1[300005];
int p[1200005];
int x;
int psh[1200005];
int inf = -1e17;

void build(int i, int l, int r){
    if (r - l == 1){
        p[i] = dp1[l + 1] + pref[l] * x;
    }
    else{
        int m = (r + l) / 2;
        build(2 * i + 1, l, m);
        build(2 * i + 2, m, r);
        p[i] = max(p[2 * i + 1], p[2 * i + 2]);
    }
}

void push(int i, int len){
    p[i] += psh[i];
    if (len > 1){
        psh[2 * i + 1] += psh[i];
        psh[2 * i + 2] += psh[i];
    }
    psh[i] = 0;
}

void upd(int i, int l, int r, int lq, int rq, int dx){
    push(i, r - l);
    if (lq >= r || l >= rq) return;
    if (lq <= l && r <= rq){
        psh[i] += dx;
        push(i, r - l);
        return;
    }
    int m = (r + l) / 2;
    upd(2 * i + 1, l, m, lq, rq, dx);
    upd(2 * i + 2, m, r, lq, rq, dx);
    p[i] = max(p[2 * i + 1], p[2 * i + 2]);
}

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    int ans2 = 0;
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) pref[i] = pref[i - 1] + a[i];
    int max_sum = 0;
    int tec = 0;
    for (int i = 1; i <= n; ++i){
        max_sum = max(max_sum, tec);
        if (tec + a[i] >= 0) tec += a[i];
        else tec = 0;
    }
    max_sum = max(max_sum, tec);
    ans2 = max(ans2, max_sum);
    tec = 0;
    for (int i = 1; i <= n; ++i){
        dp[i] = max(dp[i], tec + a[i]);
        if (tec + a[i] >= 0) tec += a[i];
        else tec = 0;
    }
    tec = 0;
    for (int i = n; i >= 1; --i){
        dp1[i] = max(dp1[i], tec + a[i]);
        if (tec + a[i] >= 0) tec += a[i];
        else tec = 0;
    }
    build(0, 1, n + 1);
    max_sum = max(max_sum, p[0]);
    for (int i = 2; i <= n; ++i){
        upd(0, 1, n + 1, i - 1, i, inf);
        upd(0, 1, n + 1, i, n + 1, -1 * a[i - 1] * x);
        max_sum = max(max_sum, p[0] + dp[i - 1]);
    }
    /*for (int i = 1; i <= n; ++i){
        for (int j = i; j <= n; ++j){
            ans2 = max(ans2, dp[i - 1] + dp1[j + 1] + (pref[j] - pref[i - 1]) * x);
            if (ans2 == 55){
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }*/
    cout << max_sum << '\n';
    //cout << ans2 << '\n';
    return 0;
}