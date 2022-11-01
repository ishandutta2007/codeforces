#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,m;
    cin >> n >> m;
    vector<bool> chkd(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b >> a;
        chkd[b] = 1;
    }
    for(int i=1;i<=n;i++){
        if(!chkd[i]){
            for(int j=1;j<=n;j++) if(i!=j) cout << i << " " << j << "\n";
            return;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for(int i=0;i<T;i++) solve();
}