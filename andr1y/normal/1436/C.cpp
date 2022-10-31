// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1228;
const ll M = 1e9+7;
ll bpm(ll a, ll b){
    a%=M;
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2==0) return bpm(a*a, b>>1);
    else return (a*bpm(a*a, b>>1))%M;
}
ll f[N], of[N];
ll ank(ll n, ll k){
    ll r = f[n];
    r=(r*of[n-k])%M;
    return r;
}
char a[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    f[0] = 1;for(ll i =1;i<N;i++) f[i]=(f[i-1]*i)%M;
    of[N-1] = bpm(f[N-1], M-2); for(ll i = N-2;i>=0;i--) of[i]=(of[i+1]*(i+1))%M; of[0]=1;
    ll n, x, pos;
    cin >> n >> x >> pos;
    ll l =0, r=n;
    ll c[3]={0, 0, 0};
    while(l<r){
        ll m = (l+r)>>1;
        if(pos>=m){
            a[m]=1; //leq x
            l=m+1;
        }else{
            a[m]=2; // gr x
            r=m;
        }
    }
    c[a[pos]]--;
    for(ll i = 0;i<n;i++) c[a[i]]++;
    ll res=1;
    if(c[1]>x-1) res=0;
    else res = ank(x-1, c[1]);
    if(c[2]>n-x) res=0;
    else res=(res*ank(n-x, c[2]))%M;
    res = (res*f[c[0]])%M;
    cout<<res;
}