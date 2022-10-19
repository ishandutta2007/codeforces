 #include <bits/stdc++.h>
/// 500 485 462 A4
using namespace std;
typedef long long int ll;
typedef complex<long double> point;
typedef long double ld;
#define pb push_back
#define pii pair < ll , ll >
#define F first
#define S second
//#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
const int N=2e5+100;
ll Main(){
    ll n,m;
    cin >> n >> m;
    while(n<m){
        ll p1=0;
        for (int i=31;i>-1;i--){
            if ((n & ((ll)1<<i))){
                if (n+(ll)(1<<i)<=m){
                    p1=1;
                    n+=(ll)(1<<i);
                    break;
                }
            }
        }
        if (p1==0) break;
    }
    if (n==m) kill("YES");
    kill("NO");

    return 0;
}
int32_t main(){
    sync;
    ll t;
    t=1;
    cin >> t;
    while(t--) Main();
}
//719 896
//1 956 979