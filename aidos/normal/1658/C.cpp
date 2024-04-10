#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
string s;
const  int mod = 998244353;
int b[maxn];
void solve(){
    cin>>n;
    int pos = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == 1) {
            pos = i;
            cnt++;
        }
    }
    if(cnt != 1) {
        cout << "NO\n";
        return;
    }
    for(int i = 0; i < n; i++) {
        b[i] = a[(i + pos) % n];
    }
    for(int i = 1; i < n; i++) {
        if(b[i] > b[i-1] + 1) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}