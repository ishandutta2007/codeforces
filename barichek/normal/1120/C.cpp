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
//#define int long long

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

#define ar (int)(5000+10)

pair<string,int> a[ar];
bool good[ar][ar];

int l[ar];

int lcp(const string& s,const string& t)
{
    int res=0;
    while (res<len(s)&&res<len(t)){
        if (s[res]==t[res]){
            res++;
        }
        else{
            break;
        }
    }
    return res;
}

int m[ar][ar];
int pos[ar];
bool is_good[ar];

int dp[ar];

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n,A,B;
    cin>>n>>A>>B;
    string s;
    cin>>s;

    for (int i=0;i<n;i++){
        a[i]=mp(s.substr(i),i);
    }

    /// suf array
    sort(a,a+n);

    for (int i=0;i+1<n;i++){
        l[i]=lcp(a[i].fir,a[i+1].fir);
//        cout<<a[i].fir<<" "<<l[i]<<"\n";
    }
    for (int i=0;i<n;i++){
        m[i][i]=n;
        pos[a[i].sec]=i;
    }
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            m[i][j]=min(m[i][j-1],l[j-1]);
        }
    }

    /// good

    for (int i=0;i<n;i++){
        int P=pos[i];
        int L=0,R=n-1;
        for (int j=0;j<n;j++){
            is_good[j]=1;
        }
        int res=0;
        for (int j=i;j<n;j++){
            int w=j-i+1;
            while (m[L][P]<w){
                is_good[a[L].sec]=0;
                L++;
            }
            while (m[P][R]<w){
                is_good[a[R].sec]=0;
                R--;
            }
            while (res<n&&!is_good[res]){
                res++;
            }
            if (res+w-1<i){
                good[i][j]=1;
            }
        }
    }

    dp[0]=0;
    for (int i=0;i<n;i++){
        dp[i+1]=dp[i]+A;
        for (int j=0;j<=i;j++){
            if (good[j][i]){
//                cout<<"good :: "<<j<<" "<<i<<"\n";
                dp[i+1]=min(dp[i+1],dp[j]+B);
            }
        }
    }
    cout<<dp[n]<<"\n";
}