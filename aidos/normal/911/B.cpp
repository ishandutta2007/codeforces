#pragma optimize("", on)
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int) 998244353;
const int inf = (1<<30) - 1;
int n, m;
int a, b;
void solve() {
    cin >> n >> a >> b;
    int ans = 0;
    for(int x = 1; x <= a && x <= b; x++) {
        int A = a;
        int B = b;
        for(int i = 1; i <= n; i++) {
            if(A > B) A -= x;
            else B -= x;
        }
        if(A >= 0 && B >= 0) {
            ans++;
        } else break;
    }
    cout << ans << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}