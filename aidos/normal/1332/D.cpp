#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)998244353 ;
const int inf = (1<<30) - 1;

int n, m, k;
void solve() {
    cin >> k;
    cout << 3 << " " << 2 << "\n";
    cout << (1<<17) + k << " " << (1<<17) << "\n";
    cout << k << " " << (1<<17) + k << "\n";
    cout << 0 << " " << k << "\n";
}


int main() {
    int t = 1;
    //scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}