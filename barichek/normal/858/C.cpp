#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) name!=""?freopen(name".in","r",stdin),freopen(name".out","w",stdout):0
#define files_ds(name) name!=""?freopen(name".dat","r",stdin),freopen(name".sol","w",stdout):0
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

const set<char> good={'a','e','i','o','u'};

bool bad(char c)
{
    return !good.count(c);
}

bool bad(char c1,char c2,char c3)
{
    return bad(c1)&&bad(c2)&&bad(c3)&&(c1!=c2||c1!=c3||c2!=c3);
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #else
        files("");
        files_ds("");
    #endif

    string s;
    cin>>s;
    string ans="";
    bool last=0;
    for (int i=0;i<len(s);i++){
        ans+=s[i];
        if (!last&&i>=1&&bad(s[i-1],s[i],s[i+1])){
            ans+=" ";
            last=1;
        }
        else{
            last=0;
        }
    }
    cout<<ans<<"\n";
}