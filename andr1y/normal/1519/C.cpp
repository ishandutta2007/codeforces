// -- //
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+228;
const ll C = 447;
ll luni[N], au[N], as[N];
vector<ll> inuni[N];
vector<ll> unip[N];
ll rs[N];
signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll q;
    cin >> q;
    for(ll QQ=1;QQ<=q;QQ++){
        vector<ll> uni, biguni, smuni;
        ll n;cin>>n;
        for(ll i = 0;i<n;i++){
            rs[i+1]=0;
            cin >> au[i];
            if(luni[au[i]]<QQ){
                luni[au[i]]=QQ;
                uni.push_back(au[i]);
                inuni[au[i]].clear();
            }
        }
        for(ll i = 0;i<n;i++){
            cin >> as[i];
            inuni[au[i]].push_back(as[i]);
        }
        for(auto i : uni){
            sort(inuni[i].begin(), inuni[i].end(), greater<ll>());
            unip[i].resize(inuni[i].size());
            ll tk=0;
            for(ll j = 0;j<inuni[i].size();j++){
                tk+=inuni[i][j];
                unip[i][j]=tk;
            }
            if(inuni[i].size()>C){
                biguni.push_back(i);
            }
            else smuni.push_back(i);
        }
        for(ll i = 1;i<=n;i++){
            ll res=0;
            if(i<=C){
                for(auto j : uni){
                    if(inuni[j].size()<i) continue;
                    ll ls = inuni[j].size()-(inuni[j].size()%i)-1;
                    res+=unip[j][ls];
                }
            }else{
                for(auto j : biguni){
                    if(inuni[j].size()<i) continue;
                    ll ls = inuni[j].size()-(inuni[j].size()%i)-1;
                    res+=unip[j][ls];
                }
            }
            cout<<res<<' ';
        }
        cout<<'\n';
    }
}