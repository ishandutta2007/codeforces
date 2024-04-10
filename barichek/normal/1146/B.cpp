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
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    string t;
    cin>>t;
    int cnta=0;
    for (auto i:t){
        if (i=='a'){
            cnta++;
        }
    }
    if ((len(t)-cnta)%2==1){
        cout<<":("<<"\n";
        return 0;
    }
    int lens=cnta+(len(t)-cnta)/2;
    string s=t.substr(0,lens);

    auto lol=[&](string s)
    {
        string res="";
        for (auto i:s){
            if (i!='a'){
                res+=i;
            }
        }
        return res;
    };

    if (s+lol(s)==t){
        cout<<s<<"\n";
    }
    else{
        cout<<":("<<"\n";
    }
}