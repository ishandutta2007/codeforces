#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define pb push_back
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()

void check1(int i, int w, int l, vector<int> &ans) {
    if ((l - 2) % i == 0)
        ans.pb(i);
}

void check2(int i, int w, int l, vector<int> &ans) {
    if ((l - 1) % i == 0)
        ans.pb(i);
}

void gen(int w, int l, vector<int> &ans) {
    for (int i = 1; i * i <= w; ++i)
        if (w % i == 0) {
            check1(i, w, l, ans);
            if (i * i != w)
                check1(w / i, w, l, ans);
        }
    for (int i = 1; i * i <= w - 1; ++i)
        if ((w - 1) % i == 0) {
            check2(i, w, l, ans);
            if (i * i != w - 1)
                check2((w - 1) / i, w, l, ans);
        }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        vector<int> ans(1, 2);
        int w, l;
        cin >> w >> l;
        gen(w, l, ans);
        gen(l, w, ans);
        sort(ALL(ans)), ans.resize(unique(ALL(ans)) - ans.begin());
        cout << SZ(ans);
        for (int i : ans)
            cout << " " << i;
        cout << "\n";
    }
}