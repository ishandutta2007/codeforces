#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];

void solve(){
    cin >> n;
    if(n == 3) {
        cout << "3 2 1\n";
        cout << "1 3 2\n";
        cout << "3 1 2\n";
        return;
    }
    for(int j = n; j >= 1; j--) {
        cout << j << " ";
    }
    cout << "\n";
    int ok = 1;
    for(int i = 1; i < n; i++) {
        if(i + 1 + i == n) {
            ok = 0;
            continue;
        }
        for(int j = n-1; j >= 1; j--) {
            cout << j << " ";
            if(i == j) cout << n << " ";
        }
        cout << "\n";
    }
    if(!ok) {
        for(int i = n; i > 3; i--) {
            cout << i << " " ;
        }
        cout << "1 3 2\n";
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