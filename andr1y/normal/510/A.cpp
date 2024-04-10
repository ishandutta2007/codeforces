// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
char a[55][55];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n, m;
    cin >> n >> m;
    for(ll i = 0;i<n;i++){
        for(ll j = 0;j<m;j++) a[i][j]='.';
    }
    for(ll i = 0;i<n;i+=2){
        for(ll j = 0;j<m;j++) a[i][j]='#';
    }
    for(ll i = 1;i<n;i+=4) a[i][m-1]='#';
    for(ll i = 3;i<n;i+=4) a[i][0]='#';
    for(ll i = 0;i<n;i++){
        for(ll j = 0;j<m;j++) cout<<a[i][j];
        cout<<'\n';
    }
}