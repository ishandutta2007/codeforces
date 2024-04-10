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

#ifdef I_love_Maria_Ivanova
    #define debug if (1)
#else
    #define debug if (0)
#endif

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

pii operator+(pii lhs,pii rhs)
{
    lhs.fir+=rhs.fir;
    lhs.sec+=rhs.sec;
    return lhs;
}

template<typename type> void minimize(type& lhs,type rhs)
{
    if (lhs>rhs) lhs=rhs;
}

pii dp[arr][3];

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
    fill(dp[0],dp[0]+3*arr,mp(1e9,-2));
    dp[0][0]=mp(0,-1);
    for (int i=0;i<len(s);i++){
        for (int j=0;j<3;j++){
            if (i==0||dp[i][j].fir!=i||s[i]!='0')
                minimize(dp[i+1][(j+s[i]-'0')%3],mp(dp[i][j].fir,1ll));
            minimize(dp[i+1][j],mp(dp[i][j].fir,2ll)+mp(1ll,0ll));
        }
    }
    if (dp[len(s)][0].sec==-2||dp[len(s)][0].fir==len(s)){
        for (auto i:s){
            if (i=='0'){
                return cout<<0, 0;
            }
        }
        return cout<<-1, 0;
    }
    string ans="";
    int cur=0;
    for (int i=len(s);i>=1;i--){
        if (dp[i][cur].sec==1){
            ans+=s[i-1];
            cur-=s[i-1]-'0';
            cur%=3;
            cur+=3;
            cur%=3;
        }
    }
    reverse(all(ans));
    cout<<ans<<"\n";
}