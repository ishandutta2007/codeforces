#pragma gcc optimize("OFast")
#pragma gcc target("sse,sse2,sse3,sse4,tune=native")
//#pragma gcc optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
const int maxn = 1e5, INF = 1e9;
const ll llINF = 1e18;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    int n, a, b; cin >> n >> a >> b;
    a += n - 1, b += n - 1;
    int ans = 0;
    while(a != b) {
        a /= 2; b /= 2; ans++;
    }
    if((1 << ans) == n) cout << "Final!";
    else cout << ans;
}