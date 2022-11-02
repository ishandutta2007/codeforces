#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];
void solve() {
    cin >> n;
    string s;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        a[i] = 0;
    }
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < n; j++) {
            if(s[j] == '1') {
                a[(i-j+n) % n]++;
                cnt++;
            }
        }
    }
    int cnta = 0, cntb = 0;
    for(int i = 0; i < n; i++) {
        cnta = max(a[i], cnta);
    }
    int x = cnt - cnta;
    cout << n - cnta + x << "\n";
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