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

#define arr (int)(1e6+10)

int sum(int a,int b)
{
    a+=b;
    a%=md;
    if (a<0){
        a+=md;
    }
    return a;
}

void add(int& a,int b)
{
    a=sum(a,b);
}

int mult(int a,int b)
{
    a*=b;
    a%=md;
    if (a<0){
        a+=md;
    }
    return a;
}

int get(const vi& a,int l,int r)
{
    return a[r]-(l==0?0:a[l-1]);
}

int n,k;
int dp[arr][2][2]; /// [pref][is_last_B][have_Bk]
int pref[arr][2][2];

void build_dp_have_Bk(string s)
{
    memset(dp,0,sizeof(dp));
    memset(pref,0,sizeof(pref));
//    if (s[0]=='B'){
//        add(dp[0][1][(k==1)],1);
//    }
//    elif (s[0]=='W'){
//        add(dp[0][0][0],1);
//    }
//    else{
//        add(dp[0][1][(k==1)],1);
//        add(dp[0][0][0],1);
//    }

    for (int i=0;i<len(s);i++){
        if (s[i]=='W'){
            break;
        }
        add(dp[i][1][(i+1>=k)],1);
    }
    for (int i=0;i<len(s);i++){
        if (s[i]=='B'){
            break;
        }
        add(dp[i][0][0],1);
    }

    pref[0][0][0]=dp[0][0][0];
    pref[0][0][1]=dp[0][0][1];
    pref[0][1][0]=dp[0][1][0];
    pref[0][1][1]=dp[0][1][1];

    int last_B=0;
    int last_W=0;

    for (int i=1;i<len(s);i++){
        /// easy (last=='W')
            /// calc dp[i][0][0]
            if (s[i]!='B'){
                int L=last_B;
                int R=i-1;

                if (L<=R){
                    add(dp[i][0][0],pref[R][1][0]-(L==0?0:pref[L-1][1][0]));
                }
            }
            /// calc dp[i][0][1]
            if (s[i]!='B'){
                int L=last_B;
                int R=i-1;

                if (L<=R){
                    add(dp[i][0][1],pref[R][1][1]-(L==0?0:pref[L-1][1][1]));
                }
            }
        /// not so easy (last=='B')
            /// calc dp[i][1][0]
            if (s[i]!='W'){
                int L=last_W;
                int R=i-1;
                L=max(L,i-k+1);

                if (L<=R){
                    add(dp[i][1][0],pref[R][0][0]-(L==0?0:pref[L-1][0][0]));
                }
            }
            /// calc dp[i][1][1]
            if (s[i]!='W'){
                int L=last_W;
                int R=i-1;
                R=min(R,i-k);

                if (L<=R){
                    add(dp[i][1][1],pref[R][0][0]-(L==0?0:pref[L-1][0][0]));
                    add(dp[i][1][1],pref[R][0][1]-(L==0?0:pref[L-1][0][1]));
                }
            }
            if (s[i]!='W'){
                int L=last_W;
                int R=i-1;
                L=max(L,i-k+1);

                if (L<=R){
                    add(dp[i][1][1],pref[R][0][1]-(L==0?0:pref[L-1][0][1]));
                }
            }
        pref[i][0][0]=sum(pref[i-1][0][0],dp[i][0][0]);
        pref[i][0][1]=sum(pref[i-1][0][1],dp[i][0][1]);
        pref[i][1][0]=sum(pref[i-1][1][0],dp[i][1][0]);
        pref[i][1][1]=sum(pref[i-1][1][1],dp[i][1][1]);

        if (s[i]=='B'){
            last_B=i;
        }
        if (s[i]=='W'){
            last_W=i;
        }
    }

//    cout<<"s :: "<<s<<"\n";
//    for (int i=0;i<len(s);i++){
//        cout<<"dp["<<i<<"][0][0] :: "<<dp[i][0][0]<<"\n";
//        cout<<"dp["<<i<<"][0][1] :: "<<dp[i][0][1]<<"\n";
//        cout<<"dp["<<i<<"][1][0] :: "<<dp[i][1][0]<<"\n";
//        cout<<"dp["<<i<<"][1][1] :: "<<dp[i][1][1]<<"\n";
//        cout<<"\n";
//    }
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    cin>>n>>k;
    string s;
    cin>>s;

    build_dp_have_Bk(s);
    vi pref_have_Bk(len(s));
    for (int i=0;i<len(s);i++){
        pref_have_Bk[i]=sum(dp[i][0][1],dp[i][1][1]);
    }

    reverse(all(s));
    for (auto& i:s){
        if (i!='X'){
            i^='B'^'W';
        }
    }

    build_dp_have_Bk(s);
    vi suf_not_have_Wk(len(s));
    for (int i=0;i<len(s);i++){
        suf_not_have_Wk[len(s)-i-1]=dp[i][0][0];
    }

    reverse(all(s));
    for (auto& i:s){
        if (i!='X'){
            i^='B'^'W';
        }
    }

    vi pref_cnt_B(0);
    for (int i=0;i<len(s);i++){
        pref_cnt_B.pb((pref_cnt_B.empty()?0:pref_cnt_B.back())+(s[i]=='B'));
    }

    int ans=0;
    for (int i=k;i<len(s);i++){
        int L=i-k+1;
        int R=i;
        if (get(pref_cnt_B,L,R)==0){
            int cur=1;
            cur=mult(cur,pref_have_Bk[L-1]);
            cur=mult(cur,(R==len(s)-1?1:suf_not_have_Wk[R+1]));
//            cout<<"i cur :: "<<i<<" "<<cur<<"\n";
//            cout<<" because of :: "<<"\n";
//            cout<<"  "<<pref_have_Bk[L-1]<<"\n";
//            cout<<"  "<<(R==len(s)-1?1:suf_not_have_Wk[R+1])<<"\n";
            add(ans,cur);
        }
    }
    cout<<ans<<"\n";
}