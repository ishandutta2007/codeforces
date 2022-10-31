// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
bool check(string s){
    ll bal=0;
    for(auto i : s){
        if(i=='(') bal++;
        else bal--;
        if(bal<0) return 0;
    }
    if(bal==0) return 1;
    else return 0;
}
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n;
        string s;
        cin >> n >> s;
        string s1="", s2="";
        ll oc=0;
        for(auto i : s) if(i=='1') oc++;
        if(oc&1){
            cout<<"NO\n";
            continue;
        }
        ll ec=0, uc=0;
        for(ll i = 0;i<n;i++){
            if(s[i]=='1'){
                ec++;
                if(ec*2<=oc) s1.push_back('('), s2.push_back('(');
                else s1.push_back(')'), s2.push_back(')');
            }else{
                uc++;
                if(uc&1){
                    s1.push_back('('), s2.push_back(')');
                }else s1.push_back(')'), s2.push_back('(');
            }
        }
        if(check(s1)&&check(s2)) cout<<"YES\n"<<s1<<'\n'<<s2<<'\n';
        else cout<<"NO\n";
    }
}