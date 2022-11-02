#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];

void solve() {
    int x, y;
    cin >>x >> y;
    int d = x * x + y * y;
    int c=sqrt(d + 0.5);
    if(c * c == d) {
        if (x == 0 && y == 0) {
            cout << 0 << "\n";
        } else {
            cout << 1 << "\n";
        }
    } else {
        cout << 2 << "\n";
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