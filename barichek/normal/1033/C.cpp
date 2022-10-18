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

vi reb[arr];

bool is_win[arr];
bool calc[arr];

bool get(int now)
{
    if (calc[now]){
        return is_win[now];
    }
    calc[now]=1;
    for (auto wh:reb[now]){
        if (!get(wh)){
            is_win[now]=1;
        }
    }
    return is_win[now];
}

int a[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=1;i<=n;i++){
        for (int j=a[i];j<=n;j+=a[i]){
            if (i-j>=1&&a[i-j]>a[i]){
                reb[i].pb(i-j);
//                cout<<i<<" -> "<<i-j<<"\n";
            }
            if (i+j<=n&&a[i+j]>a[i]){
                reb[i].pb(i+j);
//                cout<<i<<" -> "<<i+j<<"\n";
            }
        }
    }
    for (int i=1;i<=n;i++){
        bool res=get(i);
        if (res){
            cout<<"A";
        }
        else{
            cout<<"B";
        }
    }
    cout<<"\n";
}