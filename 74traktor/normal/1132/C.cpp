#include <bits/stdc++.h>

using namespace std;

int a[5005];
int PP[5005];
int p[30005];
int p1[30005];
int g[5005][2];
int T[5005];

int pref_one[5005];
int pref_two[5005];

int answ(int i, int l, int r, int lq, int rq){
    rq--;
    if (lq > rq) return 0;
    return pref_one[rq] - pref_one[lq - 1];
}

int answ1(int i, int l, int r, int lq, int rq){
    rq--;
    if (lq > rq) return 0;
    return pref_two[rq] - pref_two[lq - 1];
}

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= q; ++i){
        cin >> g[i][0] >> g[i][1];
        PP[g[i][0]]++;
        PP[g[i][1] + 1]--;
    }
    int x = 0, tt = 0;
    for (int i = 1; i <= n; ++i){
        x += PP[i];
        T[i] = x;
        if (T[i] != 0) tt++;
    }
    for (int i = 1; i <= n; ++i){
        if (T[i] == 1) pref_one[i] = 1;
        pref_one[i] += pref_one[i - 1];
        if (T[i] == 2) pref_two[i] = 1;
        pref_two[i] += pref_two[i - 1];
    }
    int ans = 0;
    for (int i = 1; i <= q; ++i){
        for (int j = i + 1; j <= q; ++j){
            int l = g[i][0], r = g[i][1], l1 = g[j][0], r1 = g[j][1];
            if (max(l, l1) <= min(r, r1)){
                ans = max(ans, tt - answ1(0, 1, n + 1, max(l, l1), min(r, r1) + 1) - answ(0, 1, n + 1, min(l, l1), max(l, l1)) - answ(0, 1, n + 1, min(r, r1) + 1, max(r, r1) + 1));
            }
            else{
                //cout << i << " " << j << " " << l << " " << r << " " << l1 << " " << r1 << " " << answ(0, 1, n + 1, l, r + 1) << " " << answ(0, 1, n + 1, l1, r1 + 1) << endl;
                ans = max(ans, tt - answ(0, 1, n + 1, l, r + 1) - answ(0, 1, n + 1, l1, r1 + 1));
            }
            //cout << i << " " << j << " " << ans << endl;
        }
    }
    cout << ans << '\n';
    return 0;
}