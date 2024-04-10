#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
int ask(ll l,ll r){
    cout << "? " << l << " " << r << endl;
    ll ans;
    cin >> ans;
    return ans;
}
ll what(ll x){
    ll l=0,r=1e9+100;
    while(r-l>1){
        ll mid=(r+l)/2;
        if (mid*(mid-1)/2<=x) l=mid;
        else r=mid;
    }
    if (l*(l-1)/2!=x) return -1;
    return l;
}
int Main(){
    ll n;
    cin >> n;
    ll l=1,r=n;
    ll kol=ask(1,n);
    ll mid;
    ll z=0;
    while(r-l>1){
        mid=(r+l)/2;
        z=ask(mid,r);
        if (z==0){
            r=mid;
            continue;
        }
        if (z==kol){
            l=mid;
            continue;
        }
        break;
    }
    ll L=-1,R=-1;
    ll tool=what(z);
    //cout << mid << " owijf " << " " << tool << " " << z << endl;
    if (tool!=-1 && ask(mid,mid+tool-1)==(tool-1)*tool/2) R=mid+tool-1;
    else{
        z=ask(1,mid);
        tool=what(z);
        if (tool==-1) cout << 1/0 << endl;
        L=mid-tool+1;
    }
    if (L!=-1){
        l=mid;
        //cout << L << "sd fekjgnwer " << l << " ernf " << r << endl;
        while(r-l>1){
            mid=(r+l)/2;

            if (ask(L,mid)==(mid-L+1)*(mid-L)/2) l=mid;
            else r=mid;
        }
        kol-=(l-L+1)*(l-L)/2;
        R=what(kol)+l;
        cout << '!' << " " << L << " " << l+1 << " " << R << endl;
        return 0;
    }
    if (R!=-1){
        r=mid;
        while(r-l>1){
            mid=(r+l)/2;
            if (ask(mid,R)==(R-mid+1)*(R-mid)/2) r=mid;
            else l=mid;
        }
        kol-=(R-r+1)*(R-r)/2;
        L=r-what(kol);
        cout << '!' << " " <<  L << " " << r << " " << R << endl;

        return 0;
    }

}
int32_t main(){
    sync;
    ll t;
    cin >> t;
    while(t--) Main();
}