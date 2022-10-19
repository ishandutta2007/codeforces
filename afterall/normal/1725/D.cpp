#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
//#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=1e6+100;
int getv[N];
int a[N];
int par[N];
int get(ll x,ll y){
	if (y>a[x]) return 1e9+10;
    ll ans=y-1;
    ll z=y*2-1;
    for (int i=x+1;i<x+21;i++){
        z=(y*2-1)/(1<<(i-x));
        if (z%2==0) z--;
        if (z>0)
            ans+=(z+1)/2;
		else break;
    }
    z=y;
    for (int i=x-1;i>=max((ll)0,x-22);i--){
        z=(ll)(2*y-1)*((ll)1<<(x-i));
        z/=2;
        ans+=min((ll)a[i],z);
        if (z==0) break;

    }
    if (x-23>=0) ans+=par[x-23];
    return ans+1;
}
int32_t main(){
    sync;
    getv[1]=1;
    for (int i=2;i<N;i++){
        getv[i]=i+getv[i-2];
    }
    ll n,q;
    cin >> n >> q;
    int ans=0;
    for (int i=1;i<N;i++){
        if (getv[i]>=n){
            ans=i;
            break;
        }
    }
    int cnt=0;
    ll jav=0;
    for (int i=1;i<=ans;i+=2){
        jav+=(ll)(ans-i+1)*i;
        jav+=(ll)(ans-i+1)*(ans-i)/2;
    }
    for (int i=ans-1;i>=0;i-=2){
        cnt++;
        a[i]=cnt;
        if (i>0) a[i-1]=cnt;
    }
    int z=getv[ans]-n;
    jav-=z*ans;
    int K=(ans-1)%2;
    for (int i=0;i<z;i+=1){
        a[K]--;
        K+=2;
    }
    cout << jav << "\n";
    par[0]=a[0];
    for (int i=1;i<N;i++){
        par[i]=par[i-1]+a[i];
    }

    while(q--){
        int x;
        cin >> x;
        int l=-1,r=ans-2;

        while(r-l>1){
            int mid=(r+l)/2;
            if (get(mid,a[mid])>=x) r=mid;
            else l=mid;
        }
        int z=a[r];
        for (int i=max((int)0,r);i<r+16;i++){
            int L=0,R=a[i];
			if (get(i,0)>x) break;
            while(R-L>1){
                ll mid=(R+L)/2;
                if (get(i,mid)>=x) R=mid;
                else L=mid;
            }


            if (get(i,R)==x){
                cout << i+R*2-1 << "\n";
                break;
            }
        }


    }

    //cout << get(0,2) << endl;
   //

}
/// 1 3 5 7
/// 0 1 2 3