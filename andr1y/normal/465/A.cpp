// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n;
    string s;
    cin >> n >> s;
    ll r=1;
    for(ll i =0;i<n;i++){
        if(s[i]=='0'){
            break;
        }else r++;
    }
    if(r==n+1) r=n;
    cout<<r;
}