#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

int arr[250005], rgtmin[250005], rgtmax[250005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, cnt = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> arr[i];
        vector<int> stkmin, stkmax;
        for (int i = 1; i <= n; ++i) {
            rgtmin[i] = n + 1, rgtmax[i] = n + 1;
            while (!stkmin.empty() && arr[stkmin.back()] > arr[i])
                rgtmin[stkmin.back()] = i, stkmin.pop_back();
            while (!stkmax.empty() && arr[stkmax.back()] < arr[i])
                rgtmax[stkmax.back()] = i, stkmax.pop_back();
            stkmin.pb(i);
            stkmax.pb(i);
        }
        int nw = 1;
        while (nw < n) {
            int nxt = nw + 1;
            if (arr[nxt] > arr[nw]) {
                while (rgtmax[nxt] < rgtmin[nw])
                    nxt = rgtmax[nxt];
                ++cnt, nw = nxt;
            }
            else {
                while (rgtmin[nxt] < rgtmax[nw])
                    nxt = rgtmin[nxt];
                ++cnt, nw = nxt;
            }
        }
        cout << cnt << "\n";
    }
}