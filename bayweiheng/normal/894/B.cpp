#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef long long ll;

const int mod=1000000007;
const int order=1000000006;

ll pow2(int pow) {
    if(pow==0) return 1;
    if(pow%2==0) {
        ll res=pow2(pow/2);
        ll ans=(res*res)%mod;
        return ans;
    }
    ll res=pow2(pow/2);
    ll ans=(res*res)%mod;
    return ((2*ans)%mod);
}

ll calculate(ll n,ll m) {
    n-=1;
    n%=order;
    m-=1;
    m%=order;
    ll pow=(n*m)%order;
    return pow2(pow);
}

int main() {
    ll n,m;
    int k;
    cin>>n>>m;
    cin>>k;
    int ans;
    if(k==-1 && n%2+m%2==1) ans=0;
    else ans=calculate(n,m);
    cout<<ans<<endl;
}