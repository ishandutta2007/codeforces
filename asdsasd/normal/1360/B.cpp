#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        int ans = 1e9;
        for(int i = 1; i < n; i++){
            ans = min(ans, a[i] - a[i - 1]);
        }
        cout << ans << endl;
    }
    return 0;
}