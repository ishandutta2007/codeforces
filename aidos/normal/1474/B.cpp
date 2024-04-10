#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];
int prime(int x) {
    if(x == 2) return 1;
    if(x <= 2) return 0;
    if(x % 2 == 0) return 0;
    for(int j = 3; j * j <= x; j += 2) {
        if(x % j == 0) return 0;
    }
    return 1;
}
int next_prime(int x) {
    while(!prime(x))++x;
    return x;
}
void solve(){
    int d;
    cin >> d;
    int x =next_prime(d+1);
    int g = next_prime(x+d);
    cout << x * g << "\n";
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