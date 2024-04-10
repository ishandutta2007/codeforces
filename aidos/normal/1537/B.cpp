#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];

ll best(ll x, ll y, ll a, ll b, ll c, ll d) {
    return abs(x-a) + abs(c-a) + abs(x-c) + abs(y-b) + abs(b-d) +abs(d-y);
}

void solve(){
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    cout << 1 << " " << 1 << " " << n << " " << m << "\n";
}




int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    int t=1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}