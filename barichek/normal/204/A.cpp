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

int dp[10][20][2][10];

string to_String(int a)
{
    stringstream stt;
    stt<<a;
    string res;
    stt>>res;
    return res;
}

int get(int a)
{
    memset(dp,0,sizeof(dp));
    if (a==0){
        return 0;
    }
    string s=to_String(a);
    while (len(s)<19){
        s="0"+s;
    }
    bool any=0;
    for (int i=0;i<len(s);i++){
        if (any||s[i]!='0'){
            for (int j=1;j<=(any?9:s[i]-'0');j++){
                dp[j][i][(!any&&(j==s[i]-'0'))][j]++;
//                cout<<"start :: "<<j<<" "<<i<<" "<<(!any&&(j==s[i]-'0'))<<" "<<j<<"\n";
            }
        }
        if (s[i]!='0'){
            any=1;
        }
    }
    for (int j=1;j<=9;j++){
        for (int i=0;i+1<len(s);i++){
            for (int k=0;k<2;k++){
                for (int last=0;last<=9;last++){
                    for (int l=0;l<=(k==1?s[i+1]-'0':9);l++){
                        dp[j][i+1][k&&(l==s[i+1]-'0')][l]+=dp[j][i][k][last];
                    }
                }
            }
        }
    }
    int res=0;
    for (int j=1;j<=9;j++){
//        cout<<j<<" :: "<<dp[j][len(s)-1][0][j]<<"\n";
//        cout<<j<<" :: "<<dp[j][len(s)-1][1][j]<<"\n";
        res+=dp[j][len(s)-1][0][j];
        res+=dp[j][len(s)-1][1][j];
    }
//    cout<<"res :: "<<res<<"\n";
    return res;
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int l,r;
    cin>>l>>r;
    cout<<get(r)-get(l-1)<<"\n";
}