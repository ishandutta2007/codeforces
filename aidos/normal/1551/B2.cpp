#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int cnt[maxn];
int c[maxn];
void solve(){
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cnt[i] = k;
        c[i] = 0;
    }
    vector<pair<int, int>> pos;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        if(cnt[a[i]] > 0) {
            pos.push_back({a[i], i});
            cnt[a[i]]--;
        }
    }
    sort(pos.begin(), pos.end());
    int d = pos.size()/k;
    d *= k;
    for(int i = 0; i < d; i++) {
        c[pos[i].second] = i % k + 1;
    }
    for(int i = 0; i < n; i++) {
        cout << c[i] << " ";
    }
    cout << "\n";
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