// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+228;
ll a[N];
//ll nx[4][N];
stack<ll> s1, s2, s3;
ll from[N];
bool set1[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    for(ll i =0;i<n;i++){
        cin >> a[i];
    }
    //nx[1][n] = nx[2][n] = nx[3][n] = n;
    memset(from, 0xff, sizeof(from));
    //ll s1=0, s2=0, s3=0, ok=1;
    ll ok=1;
    for(ll i =n-1;i>=0;i--){
        if(a[i]==1) s1.push(i);
        if(a[i]==2){
            s2.push(i);
            if(!s1.empty()){
                from[i]=s1.top();
                s1.pop();
            }
            else ok=0;
        }
        if(a[i]==3){
            if(!s3.empty()){
                from[i]=s3.top();s3.pop();
            }
            else if(!s2.empty()){
                from[i]=s2.top();s2.pop();
            }
            else if(!s1.empty()){
                from[i]=s1.top();s1.pop();
            }
            else ok=0;
            s3.push(i);
        }
    }
    if(!ok){
        return cout<<-1, 0;
    }
    /*for(ll j = 1;j<4;j++){
        for(ll i = n-1;i>=0;i--)
            nx[j][i] = (a[i+1]==j?i+1:nx[j][i+1]);
    }*/
    set<pair<ll, ll>> dots;
    for(ll i = 0;i<n;i++){
        if(a[i]==0) continue;
        if(a[i]==1){
            if(set1[i]) continue;
            else dots.insert({i+1, i+1});
        }
        if(a[i]==2){
            set1[from[i]] = 1;
            dots.insert({i+1, i+1});
            dots.insert({i+1, from[i]+1});
        }
        if(a[i]==3){
            dots.insert({i+1, i+1});
            dots.insert({i+1, from[i]+1});
            dots.insert({from[i]+1, from[i]+1});
            set1[from[i]] = 1;
        }
    }
    cout<<dots.size()<<'\n';
    for(auto i : dots) cout<<i.first<<' '<<i.second<<'\n';
}