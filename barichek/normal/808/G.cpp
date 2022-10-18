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

void maximize(int& a,int b)
{
    if (a<b) a=b;
}

bool can(char lhs,char rhs)
{
    return lhs==rhs||lhs=='?';
}

int z[arr];

void build_z(string s)
{
    for (int i=1,l=0,r=0;i<len(s);i++){
        if (i<=r){
            z[i]=min(r-i+1,z[i-l]);
        }
        while (i+z[i]<len(s)&&s[i+z[i]]==s[z[i]]){
            z[i]++;
        }
        if (i+z[i]-1>r){
            r=i+z[i]-1;
            l=i;
        }
    }
}

bool ok_val[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #else
        files("");
        files_ds("");
    #endif

    string s,t;
    cin>>s>>t;
    build_z(t);
    ok_val[0]=1;
    for (int i=0;i<len(t);i++){
        if (i+z[i]==len(t)){
            ok_val[z[i]]=1;
        }
    }
    //cout<<"val :: "<<val<<"\n";
    int ans=0;
    vector<vi> dp(len(s)+3,vi(len(t)+3,-1));
    dp[0][0]=0;
    for (int i=0;i<=len(s);i++){
        for (int j=0;j<=len(t);j++){
            if (ok_val[j]&&dp[i][len(t)]!=-1){
                maximize(dp[i][j],dp[i][len(t)]+1);
            }
            if (dp[i][j]==-1){
                continue;
            }
            maximize(ans,dp[i][j]);
            if (i<len(s)&&j<len(t)){
                if (can(s[i],t[j])){
                    maximize(dp[i+1][j+1],dp[i][j]);
                    maximize(ans,dp[i+1][j+1]);
                }
            }
            maximize(dp[i+1][0],dp[i][j]);
            maximize(ans,dp[i+1][0]);
        }
    }
    /*
    for (int i=0;i<=len(s);i++){
        for (int j=0;j<=len(t);j++){
            cout<<"dp["<<i<<"]["<<j<<"] :: "<<dp[i][j]<<"\n";
        }
    }
    */
    cout<<ans<<"\n";
}