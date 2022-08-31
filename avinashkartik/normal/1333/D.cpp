#include<bits/stdc++.h>

using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  f                     first                 
#define  s                     second                
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  3e6+5;
const ll   mod   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll t=1,n,k;
string s;
set <ll> L;
set <ll,greater<ll>> R;
vll ans[N],fans[N];

void solve(){
    cin>>n>>k;
    cin>>s;
    ll K = k;
    for(int i = 0; i < n; i++){
        if(s[i] == 'R') R.insert(i+1);
        else L.insert(i+1);
    }
    int f = 0;
    ll i = 1, j = n;
    while(L.find(i) != L.end()){
        L.erase(i);
        i++;
    }
    while(R.find(j) != R.end()){
        R.erase(j);
        j--;
    }
    int kk = 0;
    set<ll> del;
    for(; kk < k; kk++){
        if(R.size() == 0 || L.size() == 0) break;
        if(R.size() < L.size()){
            for(auto it = R.begin(); it != R.end(); it++){
                if(*it == j){
                    del.insert(*it);
                    j--;
                }
                else if(L.find((*it)+1) != L.end()){
                    //cout<<(*it);
                    ans[kk].push_back(*it);
                    L.insert(*it);
                    if(j != (*it)+1){
                        R.insert((*it)+1);
                    }
                    else{
                        i--;
                    }
                    L.erase((*it)+1);
                    del.insert(*it);
                }
            }
            for(auto it : del) R.erase(it);
        }
        else{
            for(auto it = L.begin(); it != L.end(); it++){
                if(*it == i){
                    del.insert(*it);
                    i++;
                }
                else if(R.find((*it)-1) != R.end()){
                    //cout<<(*it)<<endl;;
                    ans[kk].push_back((*it)-1);
                    R.insert(*it);
                    if(i != (*it)-1){
                        L.insert((*it)-1);
                    }
                    else{
                        i++;
                    }
                    R.erase((*it)-1);
                    del.insert(*it);
                }
            }
            for(auto it : del) L.erase(it);
        }
        //cout<<R.size()<<" "<<L.size()<<" "<<kk<<endl;
        if(R.size() == 0 || L.size() == 0){
            f = 1;
        }
    }
    ll j1 = 0, ff = 0;
    if(f == 1){
        for(int i = 0; i < kk; i++){
            ll sz = ans[i].size();
            for(int j = 0; j < sz; j++){
                if(k > kk-i){
                    fans[j1++].push_back(ans[i][j]);
                    k--;
                }
                else{
                    ff = 1;
                    fans[j1].push_back(ans[i][j]);
                }
            }
            if(ff == 1){
                j1++;
                k--;
            }
        }
        if(j1 < K){
            cout<<-1<<endl;
            return;
        }
        for(int i = 0; i < j1; i++){
            cout<<fans[i].size()<<" ";
            for(auto it : fans[i]){
                cout<<it<<" ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<-1<<endl;
    }
}

int main(){
    //fastio;
    //cin>>t;
    while(t--){
        solve();
    }
}