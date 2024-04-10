// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 128;
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q=1;
    cin >> q;
    while(q--){
        ll n, k;
        cin >> n >> k;
        if(n&1){
            k--;
            ll mid = n/2; //group by mid
            k%=mid*n;
            ll e = k/mid;
            ll st=0;
            if(e&1) st=mid+1+(e/2);
            else st=e/2;
            ll sp = e*mid;
            ll off = k-sp;
            st=(st+off)%n;
            cout<<st+1<<'\n';
        }else{
            k--;
            k%=n;
            cout<<k+1<<'\n';
        }
    }
}