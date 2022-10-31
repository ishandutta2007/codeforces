// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    string s;cin >> s;
    ll bb=0, bs=0, u=0, l=0, a=0, ss=0, r=0;
    for(auto i : s){
        if(i=='B') bb++;
        if(i=='b') bs++;
        if(i=='u') u++;
        if(i=='l') l++;
        if(i=='a') a++;
        if(i=='s') ss++;
        if(i=='r') r++;
    }
    cout<<min({bb, bs, u/2, l, a/2, ss, r});
}