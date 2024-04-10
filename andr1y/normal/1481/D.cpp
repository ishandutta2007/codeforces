// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1005;
string s[N];
ll as[N], bs[N], ac[N], bc[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, m;
        cin >> n >> m;
        for(ll i=0;i<n;i++){
            as[i]=0, bs[i]=0;
            cin >> s[i];
            for(ll jp=0;jp<n;jp++){
                char j = s[i][jp];
                if(j=='a') as[i]++, ac[i]=jp;
                if(j=='b') bs[i]++, bc[i]=jp;
            }
        }
        ll f0=-1, f1=-1;
        for(ll i = 0;i<n;i++){
            for(ll j = 0;j<n;j++){
                if(i==j) continue;
                if(s[i][j]==s[j][i]) f0=i, f1=j;
            }
        }
        if(f0>=0){
            cout<<"YES\n";
            for(ll i = 0;i<m+1;i++){
                if(i&1) cout<<f1+1<<' ';
                else cout<<f0+1<<' ';
            }
            cout<<'\n';
            continue;
        }
        if(m&1){
            cout<<"YES\n";
            for(ll i = 0;i<m+1;i++){
                cout<<(i&1)+1<<' ';
            }
            cout<<'\n';
            continue;
        }
        f0=-1, f1=-1;
        ll f2=-1;
        for(ll i = 0;i<n;i++){
            for(ll j = 0;j<n;j++){
                if(i==j) continue;
                char e = s[i][j];
                if(e=='a'&&as[j]) f0=i, f1=j, f2=ac[j];
                else if(e=='b'&&bs[j]) f0=i, f1=j, f2=bc[j];
            }
        }
        if(f0==-1){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        if(m%4==0){
            cout<<f1+1<<' ';
            for(ll i = 0;i<m;i+=4){
                cout<<f2+1<<' '<<f1+1<<' '<<f0+1<<' '<<f1+1<<' ';
            }
        }else{
            cout<<f0+1<<' '<<f1+1<<' ';
            for(ll i = 0;i<m/4;i++){
                cout<<f2+1<<' '<<f1+1<<' '<<f0+1<<' '<<f1+1<<' ';
            }
            cout<<f2+1<<' ';
        }
        cout<<'\n';
    }
}