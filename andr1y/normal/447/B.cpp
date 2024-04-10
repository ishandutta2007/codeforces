// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll n, k;
    string s;cin >> s>>k;
    ll cnt[26]={0};
    for(ll i =0;i<26;i++) cin >> cnt[i];
    ll e=0;
    ll u = *max_element(cnt, cnt+26);
    for(ll i = 0;i<s.length();i++) e+=(i+1)*cnt[s[i]-'a'];
    for(ll i = 0;i<k;i++) e+=(s.length()+i+1)*u;
    cout<<e;
}