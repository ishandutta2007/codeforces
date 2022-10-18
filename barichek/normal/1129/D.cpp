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

#define md (ll)(998244353)

void add(int& a,int b)
{
    a+=b;
    if (a>=md){
        a-=md;
    }
    if (a<0){
        a+=md;
    }
}

#define arr (int)(1e5+10)

int n,k;
int sum_block[(arr>>8)+2][arr];
int push_block[(arr>>8)+2];
int last_value[arr];
int dp[arr];

pii last_seg[arr];
int ans;

inline bool in(int a,int b,int c)
{
    return a<=b&&b<c;
}

//inline void rebuild(int bl)
//{
//    int L=bl*256;
//    int R=min(L+255,n);
//    int C=push_block[bl];
//    for (int i=L;i<=R;i++){
//        add(sum_block[bl][last_value[i]],-dp[i]);
//        last_value[i]+=C;
//        add(sum_block[bl][last_value[i]],+dp[i]);
//    }
//    push_block[bl]=0;
//}

inline void inc_pos(int pos)
{
    if (last_value[pos]+push_block[pos>>8]==k){
        add(ans,-dp[pos]);
    }
    add(sum_block[pos>>8][last_value[pos]],-dp[pos]);
    last_value[pos]++;
    add(sum_block[pos>>8][last_value[pos]],+dp[pos]);
}

inline void dec_pos(int pos)
{
    if (last_value[pos]+push_block[pos>>8]==k+1){
        add(ans,+dp[pos]);
    }
    add(sum_block[pos>>8][last_value[pos]],-dp[pos]);
    last_value[pos]--;
    add(sum_block[pos>>8][last_value[pos]],+dp[pos]);
}

void inc(int l,int r)
{
//    cout<<"inc :: "<<l<<" "<<r<<"\n";
    if ((r>>8)-(l>>8)+1<=2){
//        for (int i=(l>>8);i<=(r>>8);i++){
//            rebuild(i);
//        }
        for (int i=l;i<=r;i++){
            inc_pos(i);
        }
    }
    else{
//        rebuild(l>>8);
        while ((l&255)!=0){
            inc_pos(l);
            l++;
        }
//        rebuild(r>>8);
        while ((r&255)!=255){
            inc_pos(r);
            r--;
        }
        for (int i=(l>>8);i<=(r>>8);i++){
            if (in(0,k-push_block[i],arr)){
                add(ans,-sum_block[i][k-push_block[i]]);
            }
            push_block[i]++;
        }
    }
}

void dec(int l,int r)
{
//    cout<<"dec :: "<<l<<" "<<r<<"\n";
    if ((r>>8)-(l>>8)+1<=2){
//        for (int i=(l>>8);i<=(r>>8);i++){
//            rebuild(i);
//        }
        for (int i=l;i<=r;i++){
            dec_pos(i);
        }
    }
    else{
//        rebuild(l>>8);
        while ((l&255)!=0){
            dec_pos(l);
            l++;
        }
//        rebuild(r>>8);
        while ((r&255)!=255){
            dec_pos(r);
            r--;
        }
        for (int i=(l>>8);i<=(r>>8);i++){
            if (in(0,k+1-push_block[i],arr)){
                add(ans,+sum_block[i][k+1-push_block[i]]);
            }
            push_block[i]--;
        }
    }
}

int a[arr];

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    cin>>n>>k;

    for (int i=1;i<=n;i++){
        cin>>a[i];
    }

    sum_block[0][0]=1;
    last_value[0]=0;
    dp[0]=1;

    ans=1;

    map<int,int> last;

    for (int i=1;i<=n;i++){
        if (!last.count(a[i])){
            inc(0,i-1);
            last_seg[i]=mp(0,i-1);
        }
        else{
            auto L=last_seg[last[a[i]]];
            dec(L.fir,L.sec);
            inc(last[a[i]],i-1);
            last_seg[i]=mp(last[a[i]],i-1);
        }
        last[a[i]]=i;

        dp[i]=ans;

        add(ans,dp[i]);

//        cout<<"dp["<<i<<"] :: "<<dp[i]<<"\n";

        add(sum_block[i>>8][0],dp[i]);
    }
    cout<<dp[n]<<"\n";
}