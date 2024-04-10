#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long;
const int maxn = 1e5, INF = 1e9;
const ll llINF = 1e18;
const long double eps = 1e-9;
const ll MOD = 14309439024977LL;

int same(vector<int> a, vector<int> b) {
    int ret = 0;
    for(int i = 0; i < 3; i++) ret += min(a[i], b[i]);
    return ret;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(all(a));
    if(a[0] + 2 > a.back()) {
        cout << n << '\n';
        for(int x : a) cout << x << ' ';
        return 0;
    }
    map<int, int> cnt;
    cnt[(a[0] + a.back()) / 2] = 0;
    for(int x : a) cnt[x]++;
    a.erase(unique(all(a)), a.end());
    vector<int> v;
    for(auto x : cnt) v.push_back(x.second);
    a.push_back((a[0] + a.back()) / 2);
    sort(all(a));
    a.erase(unique(all(a)), a.end());
    vector<int> v1 = v, v2 = v;
    int x = min(v1[0], v1[2]);
    v1[0] -= x; v1[2] -= x; v1[1] += 2 * x;
    x = v2[1] / 2;
    v2[1] -= 2 * x; v2[0] += x; v2[2] += x;
    if(same(v, v1) < same(v, v2)) {
        cout << same(v, v1) << '\n';
        for(int i = 0; i < 3; i++) for(int j = 0; j < v1[i]; j++) cout << a[i] << ' ';
    } else {
        cout << same(v, v2) << '\n';
        for(int i = 0; i < 3; i++) for(int j = 0; j < v2[i]; j++) cout << a[i] << ' ';
    }
}