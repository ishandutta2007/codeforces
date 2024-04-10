#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];

void solve() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int last;
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < n; j++) {
            if(j == n-1) {
                cout << -1 << "\n";
                return;
            }
            if(a[j] < a[j+1]) {
                last = j+1;
                a[j]++;
                break;
            }
        }
    }
    cout << last << "\n";
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