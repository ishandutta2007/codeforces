#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n;
int a[maxn];
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> ans;
    for(int i = 0; i < n; ) {
        ans.push_back(a[i]);
        if(i == n-1) break;
        if(a[i+1] > a[i]) {
            i++;
            while(i < n && a[i] > a[i-1]) i++;
            i--;
        } else {
            i++;
            while(i < n && a[i] < a[i-1]) i++;
            i--;
        }
    }
    cout << ans.size() << "\n";
    for(int x: ans) cout << x << " ";
    cout << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int t = 1;
    //scanf("%d", &t);
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}