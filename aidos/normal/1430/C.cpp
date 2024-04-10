#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];

void solve() {
    cin >> n;
    cout << 2 << "\n";
    int x = n;
    for(int i = n-1; i >= 1; i--) {
        cout << x << " " << i <<"\n";
        x = (x + i + 1)/2;
    }
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