#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)3e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, k;
int a, b, c, d;
void solve() {
    cin >> a >> b >> c >> d;
    if(a <= b) {
        cout << b << "\n";
        return;
    }
    if(c <= d) {
        cout << -1 << "\n";
        return;
    }
    ll x = (a-b + c - d - 1)/(c-d);
    cout << b + c * x << "\n";
}


int main() {
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