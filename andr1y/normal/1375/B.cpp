// -- telegram @rentixous --
// -- keep calm and slava ukraini --
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 303;
ll a[N][N];
signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, m, ok=1;
        cin >> n >> m;
        for(ll i = 0;i<n;i++){
            for(ll j = 0;j<m;j++){
                cin >> a[i][j];
                ll mv=4;
                if(i==0||j==0||i==n-1||j==m-1) mv=3;
                if(
                        (i==0&&j==0) ||
                        (i==n-1&&j==0) ||
                        (i==n-1&&j==m-1) ||
                        (i==0&&j==m-1)
                ) mv=2;
                if(a[i][j]>mv) ok=0;
                else a[i][j]=mv;
            }
        }
        if(ok){
            cout<<"YES\n";
            for(ll i = 0;i<n;i++){
                for(ll j = 0;j<m;j++) cout<<a[i][j]<<' ';
                cout<<'\n';
            }
        }else{
            cout<<"NO\n";
        }
    }
}