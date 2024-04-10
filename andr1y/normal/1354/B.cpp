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
        ll mv = LLONG_MAX;
        ll last_1 = LLONG_MIN/6;
        ll last_2 = LLONG_MIN/6;
        ll last_3 = LLONG_MIN/6;
        for(ll i = 0;i<s.length();i++){
            if(s[i]=='1') last_1=i;
            if(s[i]=='2') last_2=i;
            if(s[i]=='3') last_3=i;
            mv=min(mv, max(max(i-last_1, i-last_2), i-last_3)+1);
        }
        if(mv > s.length()) cout << 0 << '\n';
        else cout << mv << '\n';
    }
}