#pragma GCC optimize("Ofast,unroll-loops,fast-math,inline,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

//#define int ll
#ifndef LOCAL
//#define endl '\n'
#endif

#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())

const int B = 330;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int max_ans = 1;
    vector<ll> bb;
    bb.reserve(n);
    for (int a = -B; a <= B; a++) {
        bb.clear();
        for (int i = 0; i < n; i++) {
            bb.push_back(arr[i] - (ll) a * i);
        }
        sort(bb.begin(), bb.end());
        int l = 0;
        int mx = 0;
        while (l < (int) bb.size()) {
            int r = l;
            while (r < (int) bb.size() && bb[l] == bb[r]) {
                r++;
            }
            mx = max(mx, r - l);
            l = r;
        }
        max_ans = max(max_ans, mx);
    }
    for (int i = 0; i < n; i++) {
        bb.clear();
        for (int j = max(0, i - B); j <= min(n - 1, i + B); j++) {
            if (i == j)
                continue;
            int a = arr[i] - arr[j];
            int b = i - j;
            if (a % b == 0) {
                a /= b;
                bb.push_back(a);
            }
        }
        sort(bb.begin(), bb.end());
        int l = 0;
        int mx = 0;
        while (l < (int) bb.size()) {
            int r = l;
            while (r < (int) bb.size() && bb[l] == bb[r]) {
                r++;
            }
            mx = max(mx, r - l);
            l = r;
        }
        max_ans = max(max_ans, mx + 1);
    }
    cout << n - max_ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
}