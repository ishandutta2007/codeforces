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

#define arr (int)(1e6+10)

int f(int a)
{
    int res=1;
    while (a){
        int cur=a%10;
        if (cur){
            res*=cur;
        }
        a/=10;
    }
    return res;
}

int g[arr];
int cnt[10][arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    for (int i=1;i<=arr;i++){
        g[i]=(i<10?i:g[f(i)]);
    }
    for (int i=0;i<10;i++){
        for (int j=1;j<arr;j++){
            cnt[i][j]=cnt[i][j-1]+(g[j]==i);
        }
    }
    int q;
    cin>>q;
    while (q--){
        int l,r,k;
        cin>>l>>r>>k;
        cout<<cnt[k][r]-cnt[k][l-1]<<"\n";
    }
}