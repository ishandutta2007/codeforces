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

#define next next_____

int dp[60][arr];
int a[arr];
int next[arr];
int last[arr];

//int m(int l,int r)
//{
//    return (l+r)/2;
//}

void solve(int p,int l,int r,int L,int R)
{
//    cout<<"solve :: "<<p<<" || "<<l<<" "<<r<<" || "<<L<<" "<<R<<"\n";
    if (l>r){
        return;
    }
    int mid=l+rand()%(r-l+1);
    int pos=-1;
    int cur=0;
    for (int i=min(mid-1,R)+2;i<=mid;i++){
        if (next[i]>mid){
            cur++;
        }
    }
    for (int i=min(mid-1,R);i>=L;i--){
//        cout<<"i :: "<<i<<"\n";
//        cout<<"s :: ";
//        for (auto i:s){
//            cout<<i<<" ";
//        }
//        cout<<"\n";
        if (next[i+1]>mid){
            cur++;
        }
//        cur+=(next[i+1]>mid);
        if (dp[p][mid]<dp[p-1][i]+cur){
            dp[p][mid]=dp[p-1][i]+cur;
            pos=i;
        }
    }
//    cout<<"dp["<<p<<"]["<<mid<<"]="<<dp[p][mid]<<" && pos="<<pos<<"\n";
//    cout<<"because :: "<<dp[p-1][pos]<<"\n";
//    if (l!=r){
        /// left
        solve(p,l,mid-1,L,pos);
        /// right
        solve(p,mid+1,r,pos,R);
//    }
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

    fast;
    int n,k;
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        next[i]=1e9;
    }
    for (int i=n;i>=1;i--){
        if (last[a[i]]){
            next[i]=last[a[i]];
        }
        last[a[i]]=i;
    }
    for (int i=1;i<=k;i++){
        solve(i,1,n,0,n);
    }
    cout<<dp[k][n]<<"\n";
}