#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
string s;
void solve(){
    cin >> n >> k;
    cin >> s;
    int cur = 0;
    ll cnt = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            cnt++;
        }
    }
    ll x = k * cnt;
    if(x % n != 0) {
        cout << -1 << "\n";
        return;
    }
    x /= n;
    if(x > k || x > cnt || k - x > n - cnt) {
        cout << -1 << "\n";
        return;
    }
    for(int i = 0; i < n; i++) {
        a[i + 1] = a[i] + s[i] - '0';
    }
    vector< pair<int, int> > d;
    for(int i = 1, r = 0; i <= n; i++) {
        while(r < n && r - i + 1 < k && a[r + 1] - a[i-1] <= x && (r + 1 - i + 1) - (a[r+1] - a[i-1]) <= k-x) {
            r++;
        }
        if(r - i + 1 == k) {
            cout << 1 << "\n";
            cout << i << " " << r << "\n";
            return;
        }
        //cout << r - i + 1 << " ";
        d.push_back({r - i + 1, i});
    }
    //return
        for(int i = 1; i <= k; i++) {
            if(a[i] + a[n] - a[n - (k - i)] == x) {
                cout << 2 << "\n";
                cout << 1 << " " << i << "\n";
                cout << n - (k - i) + 1 << " " << n << "\n";
                return;
            }
        }
    
    assert(false);
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