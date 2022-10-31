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
        string s;
        cin >> s;
        if(s.length() == 1){
            cout << s<<"\n";
            continue;
        }
        bool a1 = 1;
        for(ll i = 1;i<s.length();i++) a1=a1&&s[i]==s[i-1];
        if(a1) cout << s << '\n';
        else{
            for(ll i  =0;i<s.length();i++){
                cout << "10";
            }
            cout << '\n';
        }
    }
}