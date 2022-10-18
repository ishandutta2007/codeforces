#include <bits/stdc++.h>

using namespace std;

#define int long long
int cnt[500005];
vector < int > add[500005];
unordered_map < int, int > get_ans;
int tree[1100005];
int n, m, q, x, imax = 0;
int go[500005];

void build(int i, int l, int r){
    if (r - l == 1) go[l] = i;
    else{
        int m = (r + l) / 2;
        build(2 * i + 1, l, m);
        build(2 * i + 2, m, r);
    }
}

void modify(int i){
    int pos = go[i];
    while (pos > 0){
        tree[pos] += 1;
        if (pos % 2 == 0) pos = pos / 2 - 1;
        else pos = pos / 2;
    }
    tree[0] += x;
}

int answ(int i, int l, int r, int k){
    if (r - l == 1) return l;
    int m = (r + l) / 2;
    if (tree[2 * i + 1] < k){
        k -= tree[2 * i + 1];
        return answ(2 * i + 2, m, r, k);
    }
    else return answ(2 * i + 1, l, m, k);
}

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i){
        cin >> x;
        cnt[x]++;
        imax = max(imax, cnt[x]);
    }
    for (int i = 1; i <= m; ++i) add[cnt[i]].push_back(i);
    vector < int > input, s;
    for (int i = 1; i <= q; ++i){
        cin >> x;
        x -= n;
        input.push_back(x);
    }
    s = input;
    sort(s.begin(), s.end());
    int it = 0, cur = 0, l = 1;
    build(0, 1, m + 1);
    for (int i = 0; i < imax; ++i){
        cur += (int)add[i].size();
        for (auto key : add[i]) modify(key);
        if (cur == 0) continue;
        while (it < (int)s.size() && l <= s[it] && s[it] <= l + cur - 1){
            get_ans[s[it]] = answ(0, 1, m + 1, s[it] - l + 1);
            it++;
        }
        l += cur;
    }
    while (it < (int)s.size()){
        if ((s[it] - l + 1) % m == 0) get_ans[s[it]] = m;
        else get_ans[s[it]] = (s[it] - l + 1) % m;
        it++;
    }
    for (auto key : input) cout << get_ans[key] << '\n';
    return 0;
}