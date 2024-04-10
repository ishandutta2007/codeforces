// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
void out(__int128 a){
    string s;
    if(a==0){
        cout<<"0\n";
        return;
    }
    while(a){
        s+=(a%10)+'0';
        a/=10;
    }
    reverse(begin(s), end(s));
    cout<<s<<'\n';
}
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll ldmg, lheal, lht, ldmgcd;
        cin >> ldmg >> lheal >> lht >> ldmgcd;
        __int128 dmg = ldmg, heal = lheal, ht = lht, dmgcd = ldmgcd;
        __int128 a = dmg, b = heal, c = ht, d = dmgcd;
        if(dmg>heal*ht) cout<<"-1\n";
        else{
            __int128 mxd = c/d+1;
            __int128 v = min(mxd, (a+d*b)/(d*b));
            v=max<__int128>(v, 1);
            __int128 hlt = v*a - (v*(v-1)*b*d)/2;
            out(hlt);
        }
    }
}