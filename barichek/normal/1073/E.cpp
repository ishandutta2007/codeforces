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

#define md (ll)(998244353)

int sum(int a,int b)
{
    a+=b;
    while (a>=md){
        a-=md;
    }
    while (a<0){
        a+=md;
    }
    return a;
}

void add(int& a,int b)
{
    a=sum(a,b);
}

void add(pii& a,pii b)
{
    add(a.fir,b.fir);
    add(a.sec,b.sec);
}

pii dp[20][(1ll<<10)][2];

string to_str(int a)
{
    stringstream stt;
    stt<<a;
    string s;
    stt>>s;
    return s;
}

int pw10[20];

int get(int a,int k)
{
    for (int i=0;i<20;i++){
        for (int j=0;j<(1ll<<10);j++){
            for (int k=0;k<2;k++){
                dp[i][j][k]=mp(0,0);
            }
        }
    }

    string s=to_str(a);

    while (len(s)<19){
        s="0"+s;
    }

    bool any_not_0=0;
    for (int i=0;i<len(s);i++){
        for (int j=1;j<=(any_not_0?9:(s[i]-'0'));j++){
            add(dp[i][(1ll<<j)][(any_not_0==0)&&(j==s[i]-'0')],mp(1,pw10[len(s)-i-1]*j%md));
        }
        any_not_0|=(s[i]!='0');
    }
    for (int i=0;i+1<len(s);i++){
        for (int m=0;m<(1ll<<10);m++){
            for (int k=0;k<2;k++){
                for (int l=0;l<10;l++){
                    if ((k==0)||(l<=s[i+1]-'0')){
                        add(dp[i+1][m|(1ll<<l)][k&(l==s[i+1]-'0')],mp(dp[i][m][k].fir,dp[i][m][k].sec+dp[i][m][k].fir*l%md*pw10[len(s)-(i+1)-1]%md));
                    }
                }
            }
        }
    }

    int res=0;

    for (int m=0;m<(1ll<<10);m++){
        if (__builtin_popcountll(m)<=k){
            add(res,dp[len(s)-1][m][0].sec);
            add(res,dp[len(s)-1][m][1].sec);
        }
    }

    return res;
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    pw10[0]=1;
    for (int i=1;i<20;i++){
        pw10[i]=pw10[i-1]*10%md;
    }

    int l,r,k;
    cin>>l>>r>>k;
    int ans=0;
    add(ans,get(r,k));
    if (l!=1){
        add(ans,-get(l-1,k));
    }
    cout<<ans<<"\n";
}