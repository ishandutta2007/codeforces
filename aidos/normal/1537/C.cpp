#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];
int last[maxn];
int pos[maxn];

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int pos = 1;
    for(int i = 1; i < n; i++) {
        if(a[i] - a[i-1] < a[pos] - a[pos-1]) pos = i;
    }
    if(n == 2) pos = 0;
    for(int i = pos; i < n; i++) cout << a[i] << " ";
    for(int i = 0; i < pos; i++) cout << a[i] << " ";
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