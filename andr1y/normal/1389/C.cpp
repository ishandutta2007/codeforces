// -- telegram @rentixous --
// -- keep calm and slava ukraini --
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+1488;
string s;
ll get(char a, char b){
    ll ma=0, mb=0;
    for(auto i : s){
        if(i==a) ma=max(ma, mb+1);
        if(i==b) mb=max(mb, ma+1);
    }
    return max(mb-(mb&1), ma-(ma&1));
}
ll cnt[11];
signed main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--) {
        cin >> s;
        for(ll i = 0;i<10;i++) cnt[i]=0;
        for(auto i : s) cnt[i-'0']++;
        ll r=0;
        for(ll i = 0;i<10;i++) r=max(r, cnt[i]);
        for(char a = '0';a<='9';a++){
            for(char b='0';b<='9';b++){
                if(a==b) continue;
                r=max(r, get(a, b));
            }
        }
        cout<<s.length()-r<<'\n';
    }
}