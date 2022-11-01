#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<long long> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(),v.end());
    long long s = 0;
    for(int i=0;i<n;i++) s += v[i];
    if((s*2)%n){
        cout << "0\n";
        return;
    }
    s=(s*2)/n;
    long long ans = 0;
    for(int i=0;i<n-1;i++) ans += (upper_bound(v.begin()+i+1,v.end(),s-v[i]) - lower_bound(v.begin()+i+1,v.end(),s-v[i]));
    cout << ans << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for(int i=0;i<T;i++) solve();
}