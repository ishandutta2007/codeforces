#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 3e6 + 123;
const int mod = 1e9 + 9;
int n;
int a[1010];
string s;
unordered_map<int, int> cnt;
unordered_map<int, int> cp;

int calc(int x, int y) {
    cp.clear();
    int res = 2;
    cp[x]++;
    cp[y]++;
    if(cp[y] > cnt[y]) return 0;
    if(cp[x] > cnt[x]) return 0;
    for(int i = 0; i < 1010; i++) {
        int z = x + y;
        if(cnt.count(z) == 0) return res;
        if(cp[z] + 1 > cnt[z]) return res;
        cp[z]++;
        res++;
        x = y;
        y = z;
    }
    return res;
}
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int fi = 1;
    int ans = 1;
    sort(a, a + n);
    n = unique(a, a + n) - a;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            ans = max(ans, calc(a[i], a[j]));
            if(i!=j)ans = max(ans, calc(a[j], a[i]));
        }
    }
    cout << ans << "\n";
}
int main() {
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }

    return 0;
}