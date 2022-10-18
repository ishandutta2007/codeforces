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

#define arr (int)(1e6+10)

multiset<int> kekus[arr];

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n;
    cin>>n;
    int cnt_0=0;
    for (int i=0;i<n;i++){
        string s;
        cin>>s;
        int bal=0;
        int min_bal=0;
        for (auto j:s){
            if (j=='('){
                bal++;
            }
            else{
                bal--;
            }
            min_bal=min(min_bal,bal);
        }
        if (bal==0){
            if (min_bal>=0){
                cnt_0++;
            }
        }
        else{
            if (bal>=0){
                if (min_bal<0){
                    continue;
                }
            }
            kekus[bal+arr/2].insert(min_bal);
        }
    }

    int ans=cnt_0/2;
    for (int i=1;i<arr/2;i++){
        int id1=i+arr/2;
        int id2=-i+arr/2;
        int cnt1=len(kekus[id1]);
        for (auto j:kekus[id2]){
            if (cnt1==0){
                break;
            }
            if (j>=-i){
                ans++;
                cnt1--;
            }
        }
    }
    cout<<ans<<"\n";
}