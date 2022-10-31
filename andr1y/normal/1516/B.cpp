// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll a[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        cin >> n;
        ll tk=0;
        for(ll i = 0;i<n;i++){
            cin >> a[i];
            tk^=a[i];
        }
        bool ok = (tk==0);
        if(!ok){
            ll j=0;
            ll v1=-1;
            for(ll i = 0;i<n&&v1==-1;i++){
                j^=a[i];
                if(j==tk){
                    v1=i;
                    break;
                }
            }
            j=0;
            ll v2=-1;
            for(ll i = n-1;i>=0&&v2==-1;i--){
                j^=a[i];
                if(j==tk){
                    v2=i;
                    break;
                }
            }
            if(v1!=-1&&v2!=-1&&v1<v2&&v2-v1-1>0) ok=1;
        }
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
    }
}