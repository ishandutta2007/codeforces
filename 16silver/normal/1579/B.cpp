#include <bits/stdc++.h>
using namespace std;
void solve(){
    vector<array<int,3>> ans;
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    for(int i=0;i<n-1;i++){
        int mv = v[i], mi = i;
        for(int j=i;j<n;j++){
            if(mv>v[j]){
                mv=v[j];
                mi=j;
            }
        }
        if(mi!=i){
            ans.push_back({i, mi, mi-i});
            for(int j=mi;j>i;j--) v[j] = v[j-1];
        }
    }
    cout << ans.size() << "\n";
    for(auto x : ans) cout << x[0]+1 << " " << x[1]+1 << " " << x[2] << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for(int i=0;i<T;i++) solve();
}