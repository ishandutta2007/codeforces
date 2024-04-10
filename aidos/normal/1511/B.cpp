#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int x = a-c+1;
    int y = b-c+1;
    int A = 0;
    int B = 0;


    int d = 1;
    for(int i = 1; i < x; i++) {
        d *= 10;
    }
    A = d;
    d = 1;
    for(int i = 1; i < y; i++) {
        d *= 10;
    }
    B = d + 1;
    for(int i = 1; i < c; i++) {
        A *= 10;
        B *= 10;
    }
    cout << A << " " << B << "\n";
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