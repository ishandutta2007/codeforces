#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define all(a) a.begin(),a.end()
#define len(a) (int)(a.size())
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;
#define int long long

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;

///---program start---///

bool in_b[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n,a,b;
    cin>>n>>a>>b;
    vector<pii> v(n);
    for (auto& i:v){
        cin>>i.fir>>i.sec;
    }

    int base=0;
    for (auto i:v){
        base+=i.sec;
    }

    set<pii> best;
    best.clear();
    int sum_best=0;

    int num=0;
    for (auto i:v){
        num++;
        if (i.fir>i.sec){
            in_b[num]=1;
            sum_best+=i.fir-i.sec;
            best.insert({i.fir-i.sec,num});
            if (len(best)>b){
                pii val=*best.begin();
                best.erase(best.begin());
                in_b[val.sec]=0;
                sum_best-=val.fir;
            }
        }
    }
    int ans=base+sum_best;
    num=0;
    for (auto i:v){
        num++;
        int kek=i.fir*(1ll<<a);
        if (i.fir>i.sec){
            if (in_b[num]){
                ans=max(ans,base+sum_best+kek-i.fir);
            }
            else{
                if (b&&!best.empty()&&len(best)<b){
                    ans=max(ans,base+sum_best+kek-i.sec);
                }
                if (b&&!best.empty()&&len(best)==b&&(*best.begin()).fir<kek-i.sec){
                    ans=max(ans,base+sum_best-(*best.begin()).fir+kek-i.sec);
                }
                if (b&&best.empty()){
                    ans=max(ans,base+sum_best+kek-i.sec);
                }
            }
        }
        else{
            if (b&&!best.empty()&&len(best)<b){
                ans=max(ans,base+sum_best+kek-i.sec);
            }
            if (b&&!best.empty()&&len(best)==b&&(*best.begin()).fir<kek-i.sec){
                ans=max(ans,base+sum_best-(*best.begin()).fir+kek-i.sec);
            }
            if (b&&best.empty()){
                ans=max(ans,base+sum_best+kek-i.sec);
            }
        }
    }
    cout<<ans<<"\n";
}