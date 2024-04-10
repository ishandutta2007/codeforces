//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC optimize("unroll-loops")
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
const ll inf=1e18+10;
 
///---program start---///

void minimize(int& a,int b)
{
    if (a>b){
        a=b;
    }
}

#define arr (int)(1e6+10)

int dp_bal[2*arr];
int bal[arr];

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif
    
    for (int i=0;i<2*arr;i++){
        dp_bal[i]=inf;
    }
    
    string s;
    cin>>s>>s;
    set<pii> dps1;
    for (int i=0;i<len(s);i++){
        if (i){
            bal[i]=bal[i-1];
        }
        if (s[i]=='('){
            bal[i]++;
        }
        else{
            bal[i]--;
        }
    }
    if (bal[len(s)-1]!=0){
        cout<<-1<<"\n";
        return 0;
    }
    auto add_dp = [&](int pos,int bal,int value)
    {
        minimize(dp_bal[arr+bal],value-pos);
        int value_to_set=value;
        auto it=dps1.lower_bound(mp(bal,-1));
        if (it!=dps1.end()&&it->fir==bal){
            minimize(value_to_set,it->sec);
            dps1.erase(it);
        }
        dps1.insert(mp(bal,value_to_set));
    };
    add_dp(0,0,0);
    for (int i=0;i<len(s);i++){
        int cur_dp=inf;
        minimize(cur_dp,dp_bal[arr+bal[i]]+(i+1));
        auto it=dps1.lower_bound(mp(bal[i],-1));
        if (it!=dps1.end()&&it->fir==bal[i]){
            minimize(cur_dp,it->sec);
        }
        while (!dps1.empty()&&bal[i]<(*dps1.rbegin()).fir){
            dps1.erase((--dps1.end()));
        }
        if (i==len(s)-1){
            cout<<cur_dp<<"\n";
            return 0;
        }
        add_dp(i+1,bal[i],cur_dp);
    }
}