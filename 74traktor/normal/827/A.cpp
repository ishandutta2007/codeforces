#include <bits/stdc++.h>

using namespace std;

int const maxn = 2 * 1e6 + 1;
pair < int, int > tree[4 * maxn + 1];
pair < int, int > psh[4 * maxn + 1];
string input[1000005];

void push(int i, int len){
    if (psh[i].first == 0) return;
    if (len == 1) tree[i] = psh[i];
    else{
        psh[2 * i + 1] = psh[i];
        psh[2 * i + 2] = psh[i];
    }
}

void upd(int i, int l, int r, int lq, int rq, pair < int, int > dx){
    push(i, r - l);
    if (lq >= r || l >= rq) return;
    if (lq <= l && r <= rq){
        psh[i] = dx;
        push(i, r - l);
        return;
    }
    int m = (r + l) / 2;
    upd(2 * i + 1, l, m, lq, rq, dx);
    upd(2 * i + 2, m, r, lq, rq, dx);
}

char get_ans(int i, int l, int r, int lq){
    push(i, r - l);
    if (r - l == 1){
        if (tree[i].first == 0) return 'a';
        return input[tree[i].first][lq - tree[i].second];
    }
    int m = (r + l) / 2;
    if (lq < m) return get_ans(2 * i + 1, l, m, lq);
    else return get_ans(2 * i + 2, m, r, lq);
}

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, t, x;
    string ans = "", s;
    cin >> n;
    int imin = 1e9 + 7, imax = 0;
    for (int i = 1; i <= n; ++i){
        cin >> input[i] >> t;
        for (int j = 1; j <= t; ++j){
            cin >> x;
            imin = min(imin, x);
            imax = max(imax, x + (int)input[i].size() - 1);
            int l = x, r = x + (int)input[i].size();
            upd(0, 1, maxn + 1, l, r, {i, l});
        }
    }
    for (int i = 1; i < imin; ++i) ans += "a";
    for (int i = imin; i <= imax; ++i) ans += get_ans(0, 1, maxn + 1, i);
    cout << ans << '\n';
    return 0;
}