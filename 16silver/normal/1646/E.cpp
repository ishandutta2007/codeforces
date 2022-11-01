#include <bits/stdc++.h>
using namespace std;;;;;;;;;;;;;;;;
using ll=long long;
int n,m;
ll a[21];
bitset<20'000'001> chkd;
bool no[1'000'001];
void init(){
    for(int i=1;i<21;i++){
        a[i]=a[i-1];
        for(int j=1;j<=m;j++) if(!chkd[i*j]){
            chkd[i*j]=1;
            a[i]++;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    init();
    ll ans=1;
    for(int i=2;i<=n;i++) if(!no[i]){
        int x=0;
        ll tmp=i;
        while(tmp<=n){
            no[tmp]=1;
            tmp*=i;
            x++;
        }
        ans+=a[x];
    }
    cout << ans;
}