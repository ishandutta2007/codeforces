//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
using namespace __gnu_pbds;
template<class T>using ordered_set=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
//#define int ll
#define endl '\n'
#define double long double
const int N=1000010;
const ll mod=1000000007;
ll C(ll n,ll k){
    ll res=1ll;
    for (ll i=n-k+1;i<=n;i++){
        res*=i;
    }
    for (ll i=1;i<=k;i++) res/=i;
    return res;
}
void solve(){
//    ll s,n,k;cin>>s>>n>>k;
//    if (k>s){
//        cout<<"NO\n";
//        return;
//    }
//    if (s==k){
//        cout<<"YES\n";
//        return;
//    }
//    ll cnt=(s%k+1)*((1+s/k+1)/2)+(k-s%k-1)*((1+(s/k-1)+1)/2);
////    cout<<cnt<<endl;
//    if (cnt>=n+1){
//        cout<<"NO\n";
//    } else {
//        cout<<"YES\n";
//    }
    ll n;cin>>n;
    double p;cin>>p;
    for (ll k=0;k<=n;k++){
        double good=0.0;
        for (int i=0;i<=3;i++){
            double cur=(double)C(k,i)*C(n-k,3-i)/(double)C(n,3);
            if (i==0) good+=cur*0.0;
            else if (i==1) good+=cur/2.0;
            else if (i==2) good+=cur;
            else good+=cur;
        }
        if (good>=p){
            cout<<k<<endl;
            return;
        }
    }
//    (C(k,2)*(n-k))C(N,3)
//    4 2
//    0 1 4

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }

    return 0;
}