#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int logn = 61;

int level(int x) {
    int ans = 0;
    while(x) {
        x /= 2;
        ans++;
    }
    return ans;
}

int sva[logn], sve[logn];

void shift_val(int lvl, int k) {
    sva[lvl - 1] += k;
    sva[lvl - 1] %= 1LL << logn;
}

void shift_ver(int lvl, int k) {
    sve[lvl - 1] += k;
    sve[lvl - 1] %= 1LL << logn;
}

void normalize(int &x, int t) {
    //cout << x << ' ' << t << endl;
    x %= (1LL << t);
    if(x < 0) {
        x += 1LL << t;
    }
    x += 1LL << t;
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while(q--) {
        int t, x;
        cin >> t >> x;
        if(t == 3) {
            vector<int> ans;
            for(int i = logn - 1; i >= 0; i--) {
                if(level(x) > i) {
                    ans.push_back(x);
                    x += sva[i];
                    x += sve[i];
                    normalize(x, i);
                    //cout << i << ' ' << x << ' ' << sva[i] << ' ' << sve[i] << endl;
                    x /= 2;
                    if(i) {
                        x -= sva[i - 1];
                        normalize(x, i - 1);
                    }
                    //cout << "! " << x << ' ' << i << endl;
                }
            }
            for(auto it: ans) {
                cout << it << ' ';
            }
            cout << endl;
        } else {
            int k;
            cin >> k;
            if(t == 1) {
                shift_val(level(x), k);
                //cout << "!! " << level(x) - 1 << endl;
            } else {
                shift_ver(level(x), k);
                //cout << "!! " << level(x) - 1 << endl;
            }
        }
    }
    return 0;
}