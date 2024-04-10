#include <bits/stdc++.h>
using namespace std;;;;;;;;;;;;;;;;
void solve(){
    int n;
    cin >> n;
    vector<long long> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    int ans=n-1;
    for(int i=0;i<n;i++){
        int tmp=i;
        int cur = upper_bound(v.begin()+i,v.end(),v[i])-v.begin();
        while(cur<n){
            long long aaa = v[cur]*2-v[i];
            int ncur = lower_bound(v.begin()+i,v.end(),aaa)-v.begin();
            tmp+=(ncur-cur-1);
            cur=ncur;
        }
        ans=min(ans,tmp);
    }
    cout << ans << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for(int i=0;i<T;i++) solve();
}