#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    vector<int> ans(m);
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++) if(v[j-1][i]=='X' && v[j][i-1]=='X') ans[i] = 1;
    }
    for(int i=1;i<m;i++) ans[i] += ans[i-1];
    int q;
    cin >> q;
    while(q--){
        int a,b;
        cin >> a >> b;
        if(a==b) cout << "YES\n";
        else{
            a--;b--;
            cout << (ans[b]-ans[a]>0?"NO":"YES") << "\n";
        }
    }
}