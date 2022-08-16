#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an interatcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>

using namespace std;

#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);

typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;

const ll   N  =  2e+5+5;
const ll   MOD   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n,k,a[N],ct,s,t;
vll ans;

int main(){
    fastio;
    cin>>t;
    while(t--){
        ans.clear();
        cin>>n>>k;
        for(int i = 0; i < n; i++) cin>>a[i];
        s = 0;
        ct = 0;
        for(int i = 0; i < n; i++){
            if(ct == k-1){
                ans.push_back(n);
                break;
            }
            s += a[i];
            if(s%2 == 1){
                s = 0;
                ct += 1;
                ans.push_back(i+1);
            }
        }
        if(ans.size() != k)
            cout<<"NO"<<endl;
        else if(k == 1){
            ll sum = 0;
            for(int i = 0; i < n; i++)sum += a[i];
            if(sum%2 == 1){
                cout<<"YES"<<endl;
                for(auto i : ans)
                    cout<<i<<" ";
                cout<<endl;
            }
            else
                cout<<"NO"<<endl;
        }
        else{
            ll sum = 0;
            for(int i = ans[k-2]; i < n; i++)sum += a[i];
            if(sum%2 == 1){
                cout<<"YES"<<endl;
                for(auto i : ans)
                    cout<<i<<" ";
                cout<<endl;
            }
            else
                cout<<"NO"<<endl;
        }
    }
}