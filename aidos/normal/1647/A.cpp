#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];

void solve() {
    cin >>n;
    if(n % 3 == 1) {
        cout << 1;
        n--;
    }
    int d = 2;
    while(n > 0) {
        cout << d;
        n -= d;
        d=3-d;
    }
    cout << "\n";
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