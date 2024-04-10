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

#define arr (int)(2e6+10)

bool ok[arr];

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    string s;
    cin>>s;
    int p1=0;
    int p2=len(s)-1;
    while (p2-p1+1>=4){
        if (s[p1]==s[p2]){
            ok[p1]=ok[p2]=1;
            p1++;
            p2--;
        }
        else if (s[p1]==s[p2-1]){
            p2--;

            ok[p1]=ok[p2]=1;
            p1++;
            p2--;
        }
        else if (s[p1+1]==s[p2]){
            p1++;

            ok[p1]=ok[p2]=1;
            p1++;
            p2--;
        }
        else{
            p1++;
            p2--;

            ok[p1]=ok[p2]=1;
            p1++;
            p2--;
        }
    }
    if (p2-p1+1>=1){
        ok[p1]=1;
    }
    string res="";
    for (int i=0;i<len(s);i++){
        if (ok[i]){
            res+=s[i];
        }
    }
    cout<<res<<"\n";
}