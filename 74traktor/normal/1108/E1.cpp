#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int go[305][2];
int a[100005];
int p[800005];
int dex[800005];

void push(int i){
    dex[2 * i + 1] += dex[i];
    dex[2 * i + 2] += dex[i];
    dex[i] = 0;
}

void build(int i, int l, int r){
    if (l == r - 1){
        p[i] = a[l];
    }
    else{
        int m = (r + l) / 2;
        build(2 * i + 1, l, m);
        build(2 * i + 2, m, r);
        p[i] = max(p[2 * i + 1], p[2 * i + 2]);
    }
}

void upd(int i, int l, int r, int lq, int rq, int dx){
    if (lq >= r || l >= rq) return;
    if (lq <= l && r <= rq){
        dex[i] += dx;
        p[i] += dex[i];
        push(i);
        return;
    }
    int m = (r + l) / 2;
    upd(2 * i + 1, l, m, lq, rq, dx);
    upd(2 * i + 2, m, r, lq, rq, dx);
    p[i] = max(p[2 * i + 1] + dex[2 * i + 1], p[2 * i + 2] + dex[2 * i + 2]);
}

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector < pair < int, int > > sorted;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i){
        cin >> go[i][0] >> go[i][1];
        sorted.push_back({go[i][0], go[i][1]});
    }
    sort(sorted.begin(), sorted.end());
    build(0, 1, n + 1);
    int ans = -1, pos = 1;
    int j = 0;
    multiset < pair < int, int > > QQ;
    int kol = 0;
    for (int i = 1; i <= n; ++i){
        while ((int)QQ.size() != 0 && (*QQ.begin()).X < i){
            upd(0, 1, n + 1, (*QQ.begin()).Y, (*QQ.begin()).X + 1, 1);
            QQ.erase(QQ.begin());
            kol--;
        }
        for (; j < m; ++j){
            if (sorted[j].X <= i && i <= sorted[j].Y){
                QQ.insert({sorted[j].Y, sorted[j].X});
                upd(0, 1, n + 1, sorted[j].X, sorted[j].Y + 1, -1);
                kol++;
            }
            else if (sorted[j].X > i) break;
        }
        if (p[0] - (a[i] - kol) > ans) pos = i;
        ans = max(ans, p[0] - (a[i] - kol));
    }
    cout << ans << endl;
    vector < int > out;
    for (int i = 1; i <= m; ++i){
        if (go[i][0] <= pos && pos <= go[i][1]) out.push_back(i);
    }
    cout << out.size() << endl;
    for (auto key : out) cout << key << " ";
    return 0;
}