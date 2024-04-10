
#include <bits/stdc++.h>
using namespace std;

#define ll long long

#ifdef BALBITe
#define bug(...) cerr<<"#"<<#__VA_ARGS__<<": ", _do(__VA_ARGS__)
template<typename T> void _do(T &&x){cerr<<x<<endl;}
template<typename T, typename ...S> void _do(T &&x, S&&...y){cerr<<x<<", "; _do(y...);}
#define IOS()

#else
#define IOS() ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
#define bug(...)
#endif


signed main(){
    IOS();
    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        array<int, 2> a = {{0,0}};
        while (n--) {
            int x; cin>>x; a[x]++;
        }
        cout<<max(a[0], a[1]-a[1]%2)<<endl;
        if(a[0] < a[1]) {
            if (a[1] & 1) -- a[1];
            while(a[1]--) cout<<1<<' ';
        }else{
            while(a[0]--) cout<<0<<' ';
        }
        cout<<endl;
    }
}