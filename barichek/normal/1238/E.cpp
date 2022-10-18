//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC optimize("unroll-loops")
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
///#define int long long

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

const int M=20;

void minimize(int& a,int b)
{
    if (a>b){
        a=b;
    }
}

int cnt[M][M];
int dp[1ll<<M];

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    string s;
    cin>>s>>s>>s;
    for (int i=1;i<len(s);i++){
        cnt[s[i-1]-'a'][s[i]-'a']++;
        cnt[s[i]-'a'][s[i-1]-'a']++;
    }
    fill_n(dp,(1ll<<M),1e9);
    dp[0]=0;
    for (int m=0;m<(1ll<<M);m++){
//        cout<<"dp :: "<<bitset<M>(m)<<" "<<dp[m]<<"\n";
        int cur_cost=0;
        for (int i=0;i<M;i++){
            if ((m&(1ll<<i))!=0){
                for (int j=0;j<M;j++){
                    if (i!=j){
                        if ((m&(1ll<<j))==0){
                            cur_cost+=cnt[i][j];
                        }
                    }
                }
            }
        }
//        cout<<bitset<M>(m)<<" :: "<<cur_cost<<"\n";
        for (int j=0;j<M;j++){
            if ((m&(1ll<<j))==0){
                minimize(dp[m|(1ll<<j)],dp[m]+cur_cost);
            }
        }
    }
    cout<<dp[(1ll<<M)-1]<<"\n";
}