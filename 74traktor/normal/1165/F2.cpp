#include <bits/stdc++.h>

using namespace std;

int a[200005];
int d[400005];
int n, m;
vector < int > pos[200005];

bool check(int x){
    for (int i = 0; i <= 400000; ++i) d[i] = 0;
    int add = 0;
    for (int i = 1; i <= n; ++i){
        int it = upper_bound(pos[i].begin(), pos[i].end(), x) - pos[i].begin() - 1;
        if (it == -1) add += a[i];
        else d[pos[i][it]] += a[i];
    }
    int bal = 0;
    for (int i = 1; i <= x; ++i){
        bal++;
        int tmp = min(bal, d[i]);
        bal -= tmp;
        d[i] -= tmp;
        add += d[i];
    }
    if (bal >= 2 * add) return true;
    return false;
}

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, day, sum = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 1; i <= m; ++i){
        cin >> day >> t;
        pos[t].push_back(day);
    }
    for (int i = 1; i <= 200000; ++i) sort(pos[i].begin(), pos[i].end());
    int lef = 0, righ = 2 * sum;
    while (righ - lef > 1){
        int mid = (righ + lef) / 2;
        if (check(mid)) righ = mid;
        else lef = mid;
    }
    cout << righ << '\n';
    return 0;
}