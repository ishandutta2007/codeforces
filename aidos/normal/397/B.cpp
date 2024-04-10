#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)4e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
ll n, l, r;

void solve(){
    cin >> n >> l >> r;
    if(n < l) {
        cout << "No\n";
        return;
    }
    if(n % l == 0 || n % r == 0 || l * 2 - 1<= r) {
        cout << "Yes\n";
        return;
    }
    if(l == r) {
        cout << "No\n";
        return;
    }
    int d = r - l;
    int g = n % l;
    ll k = (g + d - 1)/d;
    if(k * l > n) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}