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

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif
    
    string s;
    cin>>s;
    int l=0,r=len(s);
    vector<int> ans(0);
    while (r-l>=2){
        if (s[l]==')'){
            l++;
        }
        else if (s[r-1]=='('){
            r--;
        }
        else{
            ans.pb(l);
            ans.pb(r-1);
            l++;
            r--;
        }
    }
    if (ans.empty()){
        cout<<0<<"\n";
    }
    else{
        cout<<1<<"\n";
        cout<<len(ans)<<"\n";
        sort(all(ans));
        for (auto i:ans){
            cout<<i+1<<" ";
        }
    }
}