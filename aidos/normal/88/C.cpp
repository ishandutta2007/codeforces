#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
ll a, b;
void solve() {
    cin >>a >> b;
    ll en = a/__gcd(a, b) * b;
    ll cur = min(a, b);
    ll dif = 0;
    while(cur < en) {
        if(cur % a == 0) {
            dif++;
        } else {
            dif--;
        }
        cur = min(cur/a * a + a, cur/b * b + b);
    }
    if(abs(dif) <= 1) cout << "Equal\n";
    else if(dif < 0) cout << "Masha\n";
    else cout << "Dasha\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
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