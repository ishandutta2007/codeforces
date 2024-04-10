// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    string s;
    cin >> s;
    ll p = 0, n=s.length();
    while(p<n&&s[p]!='h') p++;
    while(p<n&&s[p]!='e') p++;
    while(p<n&&s[p]!='l') p++; p++;
    while(p<n&&s[p]!='l') p++;
    while(p<n&&s[p]!='o') p++;
    if(p<n) cout<<"YES\n";
    else cout<<"NO\n";
}