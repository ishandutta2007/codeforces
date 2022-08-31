#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an lleratcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<string,ll>  um;
typedef  vector<pll>           vpll;
#define  x                     first                 
#define  y                     second                
 
const ll   N     =  1e+5+7;
const ll   MAXN  =  1e+9;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
 
ll k,n;
string a[N],ch;
um m;

int main(){
    fastio;
    cin>>n>>k;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        m[a[i]]++;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            ch = "";
            for(int x = 0; x < k; x++){
                if(a[i][x] == a[j][x]) ch += a[i][x];
                else if(a[i][x] == 'S'){
                    if(a[j][x] == 'E') ch += 'T';
                    else ch += 'E';
                }
                else if(a[i][x] == 'E'){
                    if(a[j][x] == 'S') ch += 'T';
                    else ch += 'S';
                }
                else if(a[i][x] == 'T'){
                    if(a[j][x] == 'E') ch += 'S';
                    else ch += 'E';
                }
            }
            //cout<<ch<<endl;
            ans += m[ch];
        }
    }
    cout<<ans/3<<endl;
}