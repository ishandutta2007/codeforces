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

template<typename type> type sqr(type a)
{
    return a*a;
}

void minimize(int& a,int b)
{
    if (a>b){
        a=b;
    }
}

int mem[100][100][100];

int dp(int n,int m,int k)
{
    if (k==0){
        return 0;
    }
    if (n*m<k){
        return 1e9;
    }
    if (n*m==k){
        return 0;
    }
    if (mem[n][m][k]){
        return mem[n][m][k];
    }
    #define res mem[n][m][k]
    res=1e9;
    for (int i=1;i<n;i++){
        for (int j=1;j<=k;j++){
            minimize(res,sqr(m)+dp(i,m,j)+dp(n-i,m,k-j));
        }
    }
    for (int i=1;i<m;i++){
        for (int j=1;j<=k;j++){
            minimize(res,sqr(n)+dp(n,i,j)+dp(n,m-i,k-j));
        }
    }
    return res;
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

    int test;
    cin>>test;
    while (test--){
        int n,m,k;
        cin>>n>>m>>k;
        cout<<dp(n,m,k)<<"\n";
    }
}