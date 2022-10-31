// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 505;
bool emp[N][N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin>>q;
    while(q--){
        ll n, m;
        cin >> n >> m;
        for(ll i =0;i<n;i++){
            for(ll j = 0;j<m;j++){
                char c;
                cin >> c;
                if(c=='X') emp[i][j]=1;
                else emp[i][j]=0;
            }
        }
        if(m%3==0){
            for(ll i = 1;i<m;i+=3){
                for(ll j = 0;j<n;j++) emp[j][i]=1;
            }
            for(ll i = 2;i<m-1;i+=3){
                bool f=0;
                for(ll j = 0;j<n&&!f;j++){
                    if(emp[j][i]) f=1, emp[j][i+1]=1;
                }
                if(f) continue;
                for(ll j = 0;j<n&&!f;j++){
                    if(emp[j][i+1]) f=1, emp[j][i]=1;
                }
                if(f) continue;
                emp[0][i]=emp[0][i+1]=1;
            }
        }else{
            for(ll i = 0;i<m;i+=3){
                for(ll j = 0;j<n;j++) emp[j][i]=1;
            }
            for(ll i = 1;i<m-1;i+=3){
                bool f=0;
                for(ll j = 0;j<n&&!f;j++){
                    if(emp[j][i]) f=1, emp[j][i+1]=1;
                }
                if(f) continue;
                for(ll j = 0;j<n&&!f;j++){
                    if(emp[j][i+1]) f=1, emp[j][i]=1;
                }
                if(f) continue;
                emp[0][i]=emp[0][i+1]=1;
            }
        }
        for(ll i = 0;i<n;i++){
            for(ll j = 0;j<m;j++){
                if(emp[i][j]) cout<<'X';
                else cout<<'.';
            }
            cout<<'\n';
        }
    }
}