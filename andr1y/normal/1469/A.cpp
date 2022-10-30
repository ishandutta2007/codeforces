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
        ll po, pc;
        ll n = s.length();
        if((n&1)||s[0]==')'||s[n-1]=='('){
            cout<<"no\n";
            continue;
        }
        cout<<"yes\n";
    }
}