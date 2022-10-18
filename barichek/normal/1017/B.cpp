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

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

//    0 1
//    0 1
//
//    0 1
//    0 0
//
//    0 1
//    1 1
//
//    0 1
//    1 0

    fast;

    string s,t;
    cin>>s>>s>>t;
    int ans=0;
    int cnt0=0;
    int cnt1=0;
    int cnt0A=0;
    int cnt1A=0;
    for (int i=0;i<len(s);i++){
        if (s[i]=='0'){
            cnt0++;
        }
        else{
            cnt1++;
        }
        if (t[i]=='1'){
            if (s[i]=='0'){
                cnt0A++;
            }
            else{
                cnt1A++;
            }
        }
    }
    cout<<cnt0*cnt1-cnt0A*cnt1A<<"\n";
}