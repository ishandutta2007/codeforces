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

bool maximize(int& a,int b)
{
    if (a<b){
        a=b;
        return 1;
    }
    return 0;
}

int n;

int dp[ar][ar];
int new_dp[ar][ar];
int buf_dp[ar][ar];

int a[ar][ar];
int pref[ar][ar];

int best_value[ar];

void print_new_dp()
{
    cout<<"current new_dp :: "<<"\n";
    for (int i=1;i<=n;i++){
        for (int j=i;j<=n;j++){
            cout<<"new_dp["<<i<<"]["<<j<<"] :: "<<new_dp[i][j]<<"\n";
        }
    }
}

void print_dp()
{
    cout<<"current dp :: "<<"\n";
    for (int i=1;i<=n;i++){
        for (int j=i;j<=n;j++){
            cout<<"dp["<<i<<"]["<<j<<"] :: "<<dp[i][j]<<"\n";
        }
    }
}

void go_dp(int id)
{
//    cout<<"go_dp :: "<<id<<"\n";

    for (int i=1;i<=n;i++){
        for (int j=i;j<=n;j++){
            buf_dp[i][j]=dp[i][j];
        }
    }

    /// go easy dp
        /// first step
        for (int k=1;k<=n;k++){
            for (int j=k;j<=n;j++){
                if (k+1<=j){
                    maximize(buf_dp[k+1][j],buf_dp[k][j]+a[k][id]);
                }
            }
        }
//        print_new_dp();
        /// second step
        for (int k=1;k<=n;k++){
            for (int j=k;j<=n;j++){
                if (j+1<=n){
                    maximize(buf_dp[k][j+1],buf_dp[k][j]+(k!=j?a[j][id]:0));
                }
            }
        }
//        print_new_dp();

    for (int i=1;i<=n;i++){
        for (int j=i;j<=n;j++){
            new_dp[i][j]=buf_dp[i][j]+a[i][id]+(i!=j?a[j][id]:0);
        }
    }

//    print_new_dp();

    /// go hard dp
        for (int i=0;i<=n;i++){
            best_value[i]=-1e18;
        }
        /// calc best value
        for (int k=1;k<=n;k++){
            for (int j=k;j<=n;j++){
//                cout<<"maximizing best_value :: "<<j<<" "<<dp[j][k]-pref[k-1][id]<<"\n";
                maximize(best_value[j],dp[k][j]-pref[k-1][id]);
            }
        }
        for (int i=1;i<=n;i++){
            maximize(best_value[i],best_value[i-1]);
//            cout<<"best_value["<<i<<"] :: "<<best_value[i]<<"\n";
        }
        /// easy :)
//        cout<<"kek :: "<<pref[2][2]<<"\n";
        for (int k_=1;k_<=n;k_++){
            for (int j_=k_;j_<=n;j_++){
                maximize(new_dp[k_][j_],best_value[k_]+pref[j_][id]);
            }
        }
//        print_new_dp();

    for (int k=1;k<=n;k++){
        for (int j=k;j<=n;j++){
            dp[k][j]=new_dp[k][j];
        }
    }

//    print_dp();
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    cin>>n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin>>a[i][j];
            pref[i][j]=pref[i-1][j]+a[i][j];
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=i;j<=n;j++){
            dp[i][j]=-1e18;
        }
    }
    dp[1][1]=0;
    for (int i=1;i<=n;i++){
        go_dp(i);
    }
    cout<<dp[n][n]<<"\n";
}