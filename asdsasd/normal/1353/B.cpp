#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a_s(n);
    vector<int> b_s(n);
    for(int i = 0; i < n; i++) cin >> a_s[i];
    for(int i = 0; i < n; i++) cin >> b_s[i];
    sort(a_s.begin(), a_s.end());
    sort(b_s.begin(), b_s.end(), greater<int>());
    for(int i = 0; i < k; i++){
        if(b_s[i] > a_s[i]){
            swap(a_s[i], b_s[i]);
        }
    }
    int ans = accumulate(a_s.begin(), a_s.end(), 0);
    cout << ans << endl;
}
int main(void){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}