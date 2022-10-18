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

#define arr (int)(3e5+10)

int n;
int a[2][arr];
int if_start[2][arr];
int sum[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    cin>>n;
    for (int i=0;i<2;i++){
        for (int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for (int i=n-1;i>=0;i--){
        sum[i]=sum[i+1]+a[0][i]+a[1][i];
    }
    for (int i=n-1;i>=0;i--){
        for (int j=0;j<2;j++){
            if_start[j][i]=if_start[j][i+1]+sum[i+1]+(2*(n-(i+1))+1)*a[j^1][i];
        }
    }

    int ans=0;
    int cur=0;
    int kek=0;
    for (int i=0;i<n;i++){
        /// if from here
        int cur_ans=0;
        cur_ans+=cur;
        cur_ans+=if_start[i%2][i]+kek*sum[i];
        ans=max(ans,cur_ans);

        cur+=a[i%2][i]*kek;
        cur+=a[(i%2)^1][i]*(kek+1);
        kek+=2;
    }
    cout<<ans<<"\n";
}