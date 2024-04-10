#include <bits/stdc++.h>
using namespace std;;;;;;;;;;;;;;;;
void solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++) cin >> v[i].first >> v[i].second;
    int s=1,e=n+1;
    while(e-s>1){
        int m=(s+e)/2;
        int tmp=0;
        for(int i=0;i<n;i++){
            if(v[i].first>=m-1-tmp && v[i].second>=tmp) tmp++;
        }
        if(tmp>=m) s=m;
        else e=m;
    }
    cout << s << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for(int i=0;i<T;i++) solve();
}