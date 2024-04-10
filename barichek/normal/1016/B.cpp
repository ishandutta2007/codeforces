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

string s;
string t;
bool is[arr];
int dp[ar][ar];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n,m,q;
    cin>>n>>m>>q;
    cin>>s;
    cin>>t;
    for (int i=0;i+len(t)-1<len(s);i++){
        is[i]=1;
        for (int j=0;j<len(t);j++){
            if (s[i+j]!=t[j]){
                is[i]=0;
                break;
            }
        }
    }
    for (int i=0;i<len(s);i++){
        for (int j=i;j<len(s);j++){
            dp[i][j]=dp[i][j-1]+(j-i+1>=len(t)&&is[j-len(t)+1]);
        }
    }
    while (q--){
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        cout<<dp[l][r]<<"\n";
    }
}