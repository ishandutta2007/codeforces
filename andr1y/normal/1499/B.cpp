// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        string s;
        cin >> s;
        ll n = s.length();
        ll f = -1;
        for(ll i = 1;i<n;i++){
            if(s[i]=='1'&&s[i-1]=='1'){
                f=i;
                break;
            }
        }
        if(f==-1) cout<<"yes\n";
        else{
            for(ll i = f;i<n;i++){
                if(s[i]=='0'&&s[i-1]=='0') {
                    f=-1;
                    break;
                }
            }
            if(f==-1) cout<<"no\n";
            else cout<<"yes\n";
        }
    }
}