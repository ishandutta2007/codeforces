#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int maxn = 2e5 + 42;

void get_bounds(vector<int> x, vector<int> y, vector<int> &L, vector<int> &R, int mod) {
    vector<int> nx, ny;
    vector<int> pts[maxn];
    for(int i = 0; i < (int)x.size(); i++) {
        if((x[i] + y[i]) % 2 == 0) {
            int cx = (x[i] + y[i]) / 2;
            int cy = (x[i] - y[i]) / 2;
            cx += maxn / 2;
            cy += maxn / 2;
            pts[cx].push_back(nx.size());
            nx.push_back(cx);
            ny.push_back(cy);
        }
    }
    int mn = maxn, mx = 0;
    if(mod == 0) {
        for(int i = 0; i < maxn; i++) {
            for(auto it: pts[i]) {
                mn = min(ny[it], mn);
                mx = max(ny[it], mx);
            }
            L[i] = mn;
            R[i] = mx;
        }
    } else {
        for(int i = maxn - 1; i >= 0; i--) {
            L[i] = mn;
            R[i] = mx;
            for(auto it: pts[i]) {
                mn = min(ny[it], mn);
                mx = max(ny[it], mx);
            }
        }
    }
}

int get_ans(vector<int> x, vector<int> y) {
    vector<int> L1(maxn), R1(maxn), L2(maxn), R2(maxn);
    get_bounds(x, y, L1, R1, 0);
    get_bounds(x, y, L2, R2, 1);
    int res = 0;
    for(int i = 0; i < maxn; i++) {
        res += max((int)0, min(R1[i], R2[i]) - max(L1[i], L2[i]));
    }
    return res;
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    int ans = get_ans(x, y);
    for(auto &it: x) {
        it++;
    }
    cout << ans + get_ans(x, y) << endl;
    return 0;
}