// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
const ll M = 1e9+7;
string s;
ll p10[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	p10[0] = 1;
	for(ll i = 1;i<N;i++) p10[i] = (p10[i-1]*10)%M;
    cin >> s;
    ll n = s.length();
    ll tsum=0;
    ll res=0;
    for(ll i = n-1;i>0;i--){
        tsum=(tsum + (s[i]-'0')*p10[n-i-1])%M;
        res=(res+tsum*i)%M;
    }
    tsum=0;
    ll ts2=0;
    for(ll i = 0;i<n;i++){
        res=(res + ts2*p10[n-i-1])%M;
        tsum=(tsum*10 + (s[i]-'0'))%M;
        ts2 = (ts2+tsum)%M;
    }
    cout<<res;
}