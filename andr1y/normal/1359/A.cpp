//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;

signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, m, k;
        cin >> n >> m >> k;
        ll p1 = n/k;
        if(p1>=m){
            cout<<m<<'\n';
        }else{
            if(m>(p1-1)*k+1) cout<<"0\n";
            else cout<<p1-((m-p1)/(k-1))-((m-p1)%(k-1)?1:0)<<'\n';
        }
    }
}