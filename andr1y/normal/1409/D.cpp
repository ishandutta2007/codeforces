#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        string s;
        ll c;
        cin >> s >> c;
        ll n = s.length();
        ll v = atoll(s.c_str());
        ll r=LLONG_MAX;
        ll KK=0;
        for(auto j : s)KK+=j-'0';
        if(KK<=c){
            cout<<"0\n";
            continue;
        }
        for(ll i = 0;i<n;i++){
            if(s[i]=='9') continue;
            string s2=s;
            for(ll j = i+1;j<n;j++) s2[j]='0';
            s2[i]++;
            ll k = 0;
            for(auto j : s2) k+=j-'0';
            if(k>c) continue;
            r=min(r, atoll(s2.c_str())-v);
        }
        string s2="1";
        for(auto j : s) s2+='0';
        r=min(r, atoll(s2.c_str())-v);
        cout<<r<<'\n';
    }
}