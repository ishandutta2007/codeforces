#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<ll> > mat;

const ld PI = acos(-1);
const int INF = 1e9;
const int N = 26;

vector<int> a[N];
ll pw[N];

map<pair<int, int>, pair<int, int> > v[2];

void gen(int l, int r, int vi) {
    int n = r - l + 1;
    for (int i = 0; i < pw[n]; i++) {
        int curi = i;
        vector<int> sum(3, 0);
        for (int j = 0; j < n; j++) {
            int r = curi % 3;
            curi /= 3;
            for (int k = 0; k < 3; k++)
                sum[k] += a[l + j][k];
            sum[r] -= a[l + j][r];
        }
        sum[1] -= sum[0];
        sum[2] -= sum[0];
        if (v[vi].count({sum[1], sum[2]}))
            v[vi][{sum[1], sum[2]}] = max(v[vi][{sum[1], sum[2]}], {sum[0], i});
        else
            v[vi][{sum[1], sum[2]}] = {sum[0], i};
    }
}

void solve() {
    int n;
    cin >> n;

    pw[0] = 1;
    for (int i = 1; i <= n; i++)
        pw[i] = pw[i - 1] * 3;

    for (int i = 0; i < n; i++) {
        a[i].resize(3);
        for (int j = 0; j < 3; j++)
            cin >> a[i][j];
    }

    gen(0, n / 2 - 1, 0);

//    for (auto x: v[0])
//        cout << x.first.first << " " << x.first.second << " " <<
//        x.second.first << " " << x.second.second << endl;
//    cout << endl;

    gen(n / 2, n - 1, 1);

//    for (auto x: v[1])
//        cout << x.first.first << " " << x.first.second << " " <<
//        x.second.first << " " << x.second.second << endl;

    int mask1 = -1, mask2 = -1;
    int maxSum = -INF;

    for (auto t: v[0]) {
        auto pr = t.first;
        pair<int, int> req = {-pr.first, -pr.second};
        if (v[1].count(req)) {
            if (maxSum < v[1][req].first + t.second.first) {
                maxSum = v[1][req].first + t.second.first;
                mask1 = t.second.second;
                mask2 = v[1][req].second;
            }
        }
    }

    if (mask1 == -1) {
        cout << "Impossible\n";
        return;
    }

    vector<int> ans;
    for (int i = 0; i < n / 2; i++) {
        ans.pb(mask1 % 3);
        mask1 /= 3;
    }
    for (int i = n / 2; i < n; i++) {
        ans.pb(mask2 % 3);
        mask2 /= 3;
    }

    for (int i = 0; i < (int)ans.size(); i++) {
        if (ans[i] == 0) {
            cout << "MW\n";
        } else if (ans[i] == 1) {
            cout << "LW\n";
        } else {
            cout << "LM\n";
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("a.in", "r", stdin);
    solve();

}