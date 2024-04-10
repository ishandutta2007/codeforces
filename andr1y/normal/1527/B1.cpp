// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin>>q;
    while(q--){
        string s;ll n;
        cin >> n>>s;
        ll zc=0;
        for(auto i : s) if(i=='0')zc++;
        if(zc==0) cout<<"DRAW\n";
        else if(zc==1) cout<<"BOB\n";
        else if(zc&1) cout<<"ALICE\n";
        else cout<<"BOB\n";
    }
}