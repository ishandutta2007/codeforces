#include <bits/stdc++.h>
 
using namespace std;

#define int int64_t

vector<int> lol = {2, 3, 5, 7, 11, 13, 17, 19};
const int maxn = int(1e18) + 42;

int cnt = 0;
vector<int> tmp;
void dfs(int x, int p, int br) {
    if(p == br) {
        tmp.push_back(x);
        return;
    }
    for(; x < maxn; x *= lol[p]) {
        dfs(x, p + 1, br);
        if(log(x) + log(lol[p]) > log(maxn) + log(2)) {
            break;
        }
    }
}

int check(vector<int> &a, vector<int> &b, int m) {
    int ans = 0;
    for(auto it: a) {
        ans += lower_bound(begin(b), end(b), (m + it - 1) / it) - begin(b);
    }
    return ans;
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    lol.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> lol[i];
    }
    random_shuffle(begin(lol), end(lol));
    dfs(1, 0, n / 2);
    vector<int> A = tmp;
    tmp.clear();
    dfs(1, n / 2, n);
    vector<int> B = tmp;
    int k;
    cin >> k;
    if(A.size() > B.size()) {
        swap(A, B);
    }
    sort(begin(A), end(A));
    sort(begin(B), end(B));
    int l = 0, r = maxn;
    while(r - l > 1) {
        int m = (l + r) / 2;
        if(check(A, B, m) < k) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << l << endl;
    return 0;
}