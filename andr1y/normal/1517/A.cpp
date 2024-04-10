// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll C = 2050000000000000000LL;
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll e = C, n;
        cin >> n;
        ll res=0;
        while(e>=2050){
            while(n>=e){
                n-=e;
                res++;
            }
            e/=10;
        }
        if(n==0) cout<<res<<'\n';
        else cout<<"-1\n";
    }
}