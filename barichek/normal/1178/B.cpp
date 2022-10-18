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

int cnt1[arr];
int cnt2[arr];

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    string s;
    cin>>s;
    for (int i=1;i<len(s);i++){
        cnt1[i]=cnt1[i-1]+(s[i]=='v'&&s[i-1]=='v');
    }
    for (int i=len(s)-2;i>=0;i--){
        cnt2[i]=cnt2[i+1]+(s[i]=='v'&&s[i+1]=='v');
    }
    int ans=0;
    for (int i=1;i+1<len(s);i++){
        if (s[i]=='o'){
            ans+=1ll*cnt1[i-1]*cnt2[i+1];
        }
    }
    cout<<ans<<"\n";
}