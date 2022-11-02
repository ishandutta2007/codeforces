#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
vector<int> a, b;
vector<int> c;
int n, m;
void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string s;
        int x;
        cin >> s >> x;
        if(s[0] == 'A') {
            a.push_back(x);
        } else {
            b.push_back(x);
        }
    }
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        c.push_back(x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    reverse(c.begin(), c.end());
    int ans = 0;
    int cur = 0;
    for(int i = 0; i < a.size() && i < c.size(); i++) {
        if(c[i] >= a[i]) {
            cur += c[i] - a[i];
            ans = max(ans, cur);
        } else {
            break;
        }
    }
    if(n > m) {
        cout << ans << "\n";
        return;
    }
    int bad = n > m;
    for(int i = 0; i < b.size(); i++) {
        int j = 0;
        while(j+1 < c.size() && c[j+1] > b[i]) j++;
        if(c[j] <= b[i]) {
            bad = 1;
        }
        c.erase(c.begin() + j);
    }
    cur = 0;
    for(int i = 0; i < c.size(); i++) {
        cur += c[i];
    }
    for(int i = 0; i < a.size(); i++) {
        if(c[a.size() - i - 1] >= a[i]) {
            cur -= a[i];
        } else {
            bad = 1;
        }
    }
    if(!bad) ans = max(ans, cur);
    cout << ans << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}