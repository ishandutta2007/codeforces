// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 3e5+228;
const ll M = 1e9+7;
ll f[N], of[N], a[N];
ll bpm(ll a, ll b){
    a%=M;
    if(b==0) return 1;
    if(b==1) return a;
    if(b&1) return (a*bpm(a*a, b>>1))%M;
    else return bpm(a*a, b>>1);
}
inline ll c(ll n, ll k){
    return ((f[n]*of[n-k])%M)*of[k]%M;
}
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    f[1]=1;
    for(ll i = 2;i<N;i++){
        f[i]=(f[i-1]*i)%M;
    }
    of[N-1] = bpm(f[N-1], M-2);
    for(ll i = N-2;i>=0;i--){
        of[i]=(of[i+1]*(i+1))%M;
    }
    while(q--){
        ll n, m, k;
        cin >> n >> m >> k;
        for(ll i = 0;i<n;i++) cin >> a[i];
        if(m==1){
            cout<<n<<'\n';
            continue;
        }
        sort(a, a+n);
        ll l =0;
        ll res=0;
        for(ll r=0;r<n;r++){
            while(a[r]-a[l]>k) l++;
            if(r-l+1>=m){
                res+=c(r-l, m-1);
                if(res>=M) res-=M;
            }
        }
        cout<<res<<'\n';
    }
}