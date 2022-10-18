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

int pref[arr];
int best[arr];

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    string s;
    cin>>s;
    for (int i=0;i<len(s);i++){
        if (i){
            pref[i]=pref[i-1];
        }
        pref[i]+=(s[i]=='[');
    }
    pair<int,pii> ans=mp(0,mp(0,0));
    for (int i=0;i<len(s);i++){
        if (s[i]==')'||s[i]==']'){
            if (i){
                int pp=(i-1)-best[i-1]+1;
                if (pp){
                    if (s[pp-1]=='('&&s[i]==')'){
                        best[i]=best[i-1]+2+(pp-1==0?0:best[pp-2]);
                    }
                    if (s[pp-1]=='['&&s[i]==']'){
                        best[i]=best[i-1]+2+(pp-1==0?0:best[pp-2]);
                    }
                }
            }
        }
    }
    for (int i=0;i<len(s);i++){
        if (best[i]){
            int L=i-best[i]+1;
            int R=i;
            if (pref[R]-(L==0?0:pref[L-1])>ans.fir){
                ans=mp(pref[R]-(L==0?0:pref[L-1]),mp(L,R+1));
            }
        }
    }
    cout<<ans.fir<<"\n";
    cout<<s.substr(ans.sec.fir,ans.sec.sec-ans.sec.fir)<<"\n";
}