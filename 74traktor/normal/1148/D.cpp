#include <bits/stdc++.h>

using namespace std;

int const maxn = 4 * 1e6;
int tree[maxn];
int mas1[maxn];
int mas2[maxn];
int rev[maxn];
int w[maxn];
int inf;

void build(int i, int l, int r){
    if (r - l == 1) tree[i] = mas1[l];
    else{
        int m = (r + l) / 2;
        build(2 * i + 1, l, m);
        build(2 * i + 2, m, r);
        tree[i] = max(tree[2 * i + 1], tree[2 * i + 2]);
    }
}

void update(int i, int l, int r, int lq){
    if (r - l == 1) tree[i] = 0;
    else{
        int m = (r + l) / 2;
        if (lq < m) update(2 * i + 1, l, m, lq);
        else update(2 * i + 2, m, r, lq);
        tree[i] = max(tree[2 * i + 1], tree[2 * i + 2]);
    }
}

int get_ans(int i, int l, int r, int lq, int rq){
    if (l >= rq || lq >= r) return 0;
    if (lq <= l && r <= rq) return tree[i];
    int m = (r + l) / 2;
    return max(get_ans(2 * i + 1, l, m, lq, rq), get_ans(2 * i + 2, m, r, lq, rq));
}

void build1(int i, int l, int r){
    if (r - l == 1) tree[i] = mas2[l];
    else{
        int m = (r + l) / 2;
        build1(2 * i + 1, l, m);
        build1(2 * i + 2, m, r);
        tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]);
    }
}

void update1(int i, int l, int r, int lq){
    if (r - l == 1) tree[i] = inf;
    else{
        int m = (r + l) / 2;
        if (lq < m) update1(2 * i + 1, l, m, lq);
        else update1(2 * i + 2, m, r, lq);
        tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]);
    }
}

int get_ans1(int i, int l, int r, int lq, int rq){
    if (l >= rq || lq >= r) return inf;
    if (lq <= l && r <= rq) return tree[i];
    int m = (r + l) / 2;
    return min(get_ans1(2 * i + 1, l, m, lq, rq), get_ans1(2 * i + 2, m, r, lq, rq));
}

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x, y;
    cin >> n;
    vector < vector < int > > a;
    vector < vector < int > > b;
    for (int i = 0; i < maxn; ++i) mas2[i] = 2 * n + 1;
    for (int i = 1; i <= n; ++i){
        cin >> x >> y;
        rev[x] = y;
        rev[y] = x;
        w[x] = i;
        w[y] = i;
        if (x < y) a.push_back({x, y, i}), mas1[x] = y;
        else b.push_back({x, y, i}), mas2[x] = y;
    }
    vector < int > ans1, ans2;
    int last = 2 * n;
    int r = 2 * n + 1;
    build(0, 1, r);
    while (1){
        int imax = get_ans(0, 1, r, 1, last + 1);
        if (imax == 0) break;
        ans1.push_back(w[imax]);
        update(0, 1, r, rev[imax]);
        last = imax;
    }
    //cout << ans1.size() << endl;
    inf = 2 * n + 1;
    for (int i = 0; i < maxn; ++i) tree[i] = inf;
    last = 1;
    build1(0, 1, r);
    while (1){
        int imin = get_ans1(0, 1, r, last, r);
        if (imin == inf) break;
        ans2.push_back(w[imin]);
        update1(0, 1, r, rev[imin]);
        last = imin;
    }
    if ((int)ans1.size() >= (int)ans2.size()){
        cout << ans1.size() << '\n';
        for (auto key : ans1) cout << key << " ";
    }
    else{
        cout << ans2.size() << '\n';
        for (auto key : ans2) cout << key << " ";
    }
    return 0;
}