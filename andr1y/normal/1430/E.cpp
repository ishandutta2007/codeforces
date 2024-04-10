// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
ll n;
string s;
ll last[26];
bool ban[N];
void fixlast(ll k){
    for(ll j = 0;j<26;j++){
        while(last[j]>=0&&(ban[last[j]]||last[j]>k||s[last[j]]-'a'!=j)) last[j]--;
    }
}
ll fwt[N];
void fwinc(ll p, ll d=0){
    ++p;
    for(;p<N;p+=p&-p) fwt[p]+=d;
}
ll fwsum(ll r, ll s=0){
    ++r;
    for(;r;r-=r&-r) s+=fwt[r];
    return s;
}
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    cin >> n >> s;
    string s2 = s;
    memset(last, 255, sizeof(last));
    for(ll i = 0;i<n;i++){
        last[s[i]-'a']=i;
    }
    ll p = n-1, res=0;
    for(ll ii =n-1;ii>=0;ii--){
        while(p>=0&&ban[p]) --p;
        if(p<0) break;
        ll j = n-ii-1;
        if(s[p]==s[j]){
            --p;
            continue;
        }else{
            fixlast(p);
            ll e = last[s[j]-'a'];
            ban[e]=1;
            res+=ii-(e-fwsum(e));
            fwinc(e, 1);
        }
    }
    cout<<res;
}