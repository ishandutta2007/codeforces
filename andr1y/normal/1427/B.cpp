// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pll pair<ll, ll>
#define x first
#define y second
const ll N = 1e5+228;
string s;
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    while(q--){
        ll n, k;
        cin >> n >> k >> s;
        vector<pll> e;
        ll fr=0;
        ll w=0;
        ll ff=-1, ls=-1;
        for(ll i = 0;i<n;i++){
            if(i&&s[i-1]=='L'&&s[i]=='W'){
                if(w) e.push_back({fr, i});
            }
            if(s[i]=='L'){
                fr++;
            }else{
                if(!w) ff=i;
                fr=0, w=1;
                ls=i;
            }
        }
        sort(begin(e), end(e));
        for(auto i : e){
            if(!k) continue;
            for(ll j = i.y-1;s[j]!='W'&&k;--j){
                s[j]='W';
                --k;
            }
        }
        for(ll i = ff-1;i>=0&&k;i--) s[i]='W', --k;
        for(ll i = ls+1;i<n&&k;i++) s[i]='W', --k;
        ll res=0, tb=0;
        for(ll i = 0;i<n;i++){
            if(s[i]=='W'){
                if(tb) res+=2;
                else res+=1;
                tb=1;
            }else{
                tb=0;
            }
        }
        cout<<res<<'\n';
    }
}