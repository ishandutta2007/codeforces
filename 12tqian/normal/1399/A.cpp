#include<bits/stdc++.h>
using namespace std;

void solve_case(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    bool ok = true;
    for(int i = 0; i < n - 1; i++){
        if(a[i + 1] - a[i] > 1){
            ok = false;
            break;
        }
    }
    if(ok) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}
int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int tt; cin >> tt;
    while(tt--) solve_case();
    return 0;
}