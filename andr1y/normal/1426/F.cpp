// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
const ll M = 1e9+7;
ll dpa[N], dpc[N];
ll p3[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	p3[0]=1;
	for(ll i = 1;i<N;i++) p3[i]=(p3[i-1]*3)%M;
    ll n;
    string s;
    cin >> n >> s;
    ll ac=0, qc=0;
    for(ll i = 0;i<n;i++){
        if(s[i]=='a') ac++;
        if(s[i]=='?') qc++;
        ll r = (ac*p3[qc])%M;
        if(qc) r += (qc*p3[qc-1])%M;
        r%=M;
        dpa[i]=r;
    }
    ll cc=0;
    qc=0;
    for(ll i = n-1;i>=0;i--){
        if(s[i]=='c') cc++;
        if(s[i]=='?') qc++;
        ll r = (cc*p3[qc])%M;
        if(qc) r += (qc*p3[qc-1])%M;
        r%=M;
        dpc[i]=r;
    }
    ll r=0;
    for(ll i = 1;i+1<n;i++){
        if(s[i]=='b'||s[i]=='?') r=(r+(dpa[i-1]*dpc[i+1])%M)%M;
    }
    cout<<r;
}