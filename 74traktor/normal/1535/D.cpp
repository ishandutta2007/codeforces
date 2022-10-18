#include<bits/stdc++.h>

using namespace std;

string s;
pair < int, int > game[(1 << 19)];
vector < vector < int > > t;
char type[(1 << 19)];
int cnt[(1 << 19)];

void build(int i, int l, int r) {
    if (r - l == 1) return;
    t.push_back({r - l, l, r, i});
    int m = (r + l) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m, r);
}

void go(int i, int l, int r) {
    if (r - l == 1) {
        cnt[i] = 1;
    }
    else {
        int m = (r + l) / 2;
        go(2 * i + 1, l, m);
        go(2 * i + 2, m, r);
        if (type[i] == '?') cnt[i] = cnt[2 * i + 1] + cnt[2 * i + 2];
        else if (type[i] == '0') cnt[i] = cnt[2 * i + 1];
        else cnt[i] = cnt[2 * i + 2];
    }
}

void upd(int i, int l, int r, int lq, int rq, char s) {
    if (l <= lq && rq <= r) {
        if (lq == l && rq == r) {
            type[i] = s;
            if (type[i] == '?') cnt[i] = cnt[2 * i + 1] + cnt[2 * i + 2];
            else if (type[i] == '0') cnt[i] = cnt[2 * i + 1];
            else cnt[i] = cnt[2 * i + 2];
            return;
        }
        int m = (r + l) / 2;
        upd(2 * i + 1, l, m, lq, rq, s);
        upd(2 * i + 2, m, r, lq, rq, s);
        if (type[i] == '?') cnt[i] = cnt[2 * i + 1] + cnt[2 * i + 2];
        else if (type[i] == '0') cnt[i] = cnt[2 * i + 1];
        else cnt[i] = cnt[2 * i + 2];
    }
}

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin >> k;
    cin >> s;
    build(0, 0, (1 << k));
    sort(t.begin(), t.end());
    for (int i = 0; i < (int)t.size(); ++i) {
        game[i] = {t[i][1], t[i][2]};
        type[t[i].back()] = s[i];
    }
    go(0, 0, (1 << k));
    int q;
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        int pos;
        cin >> pos;
        pos--;
        char nt;
        cin >> nt;
        upd(0, 0, (1 << k), game[pos].first, game[pos].second, nt);
        cout << cnt[0] << '\n';
    }
    return 0;
}