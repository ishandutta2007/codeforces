#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
ll n, p, w, d;
void solve() {
    cin >> n >> p >> w >> d;
    for(ll y = 0; y < maxn; y++) {
        ll A = p - y * d;
        if(A >= 0 && A % w == 0 && A/w + y <= n) {
            cout << A/w << " "<<y << " " << n - A/w - y << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
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