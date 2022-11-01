#include <bits/stdc++.h>
using namespace std;;;;;;;;;;;;;;;;
using ll=long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n+1), ans(n+1), chkd(n+1);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) if(!ans[i]){
        int x=i;
        while(!chkd[x]){
            chkd[x]=true;
            x=a[x];
        }
        if(!ans[x]) ans[x]=x;
        int y=a[x];
        while(!ans[y]){
            ans[y]=y;
            y=a[y];
        }
        y=i;
        while(!ans[y]){
            ans[y]=ans[x];
            y=a[y];
        }
    }
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
}