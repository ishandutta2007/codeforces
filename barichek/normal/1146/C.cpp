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

int n;
int ans;
bool is[10][arr];

void rec(int l,int r,int deep,bool kek)
{
    if (l!=r){
        int m=(l+r)/2;
        rec(l,m,deep+1,kek);
        rec(m+1,r,deep+1,kek^1);
    }
    if (deep){
        ans=max(ans,deep);
        for (int i=l;i<=r;i++){
            is[deep-1][i]=kek;
        }
    }
}

void solve()
{
    ans=0;
    for (int i=0;i<9;i++){
        for (int j=1;j<=n;j++){
            is[i][j]=0;
        }
    }
    cin>>n;
    rec(1,n,0,0);
    int res=-1e9;
    for (int i=0;i<ans;i++){
        set<int> here;
        set<int> here1;
        for (int j=1;j<=n;j++){
            if (is[i][j]){
                here.insert(j);
            }
            else{
                here1.insert(j);
            }
        }
        if (here.empty()||here1.empty()){
            continue;
        }
        else{
            fflush(stdout);
            cout<<len(here)<<" "<<len(here1);
            for (auto i:here){
                cout<<" "<<i;
            }
            for (auto i:here1){
                cout<<" "<<i;
            }
            cout<<"\n";
            fflush(stdout);
            int cur_res;
            cin>>cur_res;
            res=max(res,cur_res);
            fflush(stdout);
        }
    }
    cout<<-1<<" "<<res<<"\n";
}

main()
{
//    #ifdef Barik
//        files("barik");
//        freopen("debug.txt","w",stderr);
//    #endif

    int test;
    cin>>test;
    while (test--){
        solve();
    }
}