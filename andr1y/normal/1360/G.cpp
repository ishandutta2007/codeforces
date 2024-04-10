//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 51;
ll aa[N];
ll res[N][N];
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, m, a, b;
        cin>>n>>m>>a>>b;
        for(ll i = 0;i<m;i++) aa[i]=0;
        for(ll i = 0;i<n;i++){
            for(ll j =0;j<m;j++) res[i][j]=0;
        }
        for(ll i =0 ;i<n;i++){
            pair<ll, ll> sk[m];
            for(ll j =0;j<m;j++) sk[j]={aa[j], j};
            sort(sk, sk+m);
            for(ll j=0;j<a;j++){
                aa[sk[j].second]++;
                res[i][sk[j].second]=1;
            }
        }
        bool ok=1;
        for(ll i = 0;i<m;i++) ok=ok&&aa[i]==b;
        if(ok){
            cout<<"YES\n";
            for(ll i = 0;i<n;i++){
                for(ll j =0;j<m;j++) cout<<res[i][j];
                cout<<'\n';
            }
        }else{
            cout<<"NO\n";
        }
    }
}