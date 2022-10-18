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

string dp1[arr];
string dp2[arr];

int from1[arr];
int from2[arr];

bool cmp1(const string& a,const string &b)
{
    return a<b;
}

bool cmp2(string a,string b)
{
    reverse(all(a));
    reverse(all(b));
    return a<b;
}

string reversed(string s)
{
    reverse(all(s));
    return s;
}

int ans[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    string s;
    cin>>s;
    int n=len(s);
    dp1[0]="";
    dp2[0]="";
    for (int i=0;i<len(s);i++){
        dp1[i+1]=dp1[i]+s[i];
        from1[i+1]=1;
        dp2[i+1]=dp2[i]+s[i];
        from2[i+1]=2;

        /// relax
        if (cmp1(dp1[i+1],reversed(dp1[i])+s[i])){
            dp1[i+1]=reversed(dp1[i])+s[i];
            from1[i+1]=100+1;
        }
        if (cmp1(dp1[i+1],reversed(dp2[i])+s[i])){
            dp1[i+1]=reversed(dp2[i])+s[i];
            from1[i+1]=100+2;
        }
        if (cmp2(dp2[i+1],reversed(dp1[i])+s[i])){
            dp2[i+1]=reversed(dp1[i])+s[i];
            from2[i+1]=100+1;
        }
        if (cmp2(dp2[i+1],reversed(dp2[i])+s[i])){
            dp2[i+1]=reversed(dp2[i])+s[i];
            from2[i+1]=100+2;
        }
    }
//    cout<<min(dp1[len(s)],dp2[len(s)])<<"\n";
    int cur=(dp1[len(s)]<dp2[len(s)]?1:2);
    vector<pair<string,pair<bool,int>>> vec(0);
    vec.pb(mp(dp1[len(s)],mp(0,1)));
    vec.pb(mp(dp2[len(s)],mp(0,2)));
    vec.pb(mp(reversed(dp1[len(s)]),mp(1,1)));
    vec.pb(mp(reversed(dp2[len(s)]),mp(1,2)));
    sort(all(vec));
    cur=vec[0].sec.sec;
    if (vec[0].sec.fir){
        ans[n]=1;
    }
    for (int i=len(s);i>=2;i--){
        if (cur==1){
            if (from1[i]<100){

            }
            else{
                cur=from1[i]-100;
                ans[i-1]=1;
            }
        }
        else{
            if (from2[i]<100){

            }
            else{
                cur=from2[i]-100;
                ans[i-1]=1;
            }
        }
    }
    for (int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}