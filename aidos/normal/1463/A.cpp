#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];

void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    int x = (a + b + c);
    if(x % 9 != 0) {
        cout << "NO\n";
        return;
    }
    int d = x/9;
    if(d > a || d > b || d > c) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
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