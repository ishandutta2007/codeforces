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

#define time time_____

#define arr (int)(1e6+10)

int n,m,k,q;

int x[arr];
int y[arr];
int t[arr];
int pref[501][501];

int get(int x1,int y1,int x2,int y2)
{
    x1--;
    y1--;
    int res=pref[x2][y2];

    res-=pref[x1][y2];
    res-=pref[x2][y1];

    res+=pref[x1][y1];
    return res;
}

bool check(int time)
{
    for (int i=0;i<=n;i++){
        for (int j=0;j<=m;j++){
            pref[i][j]=0;
        }
    }
    for (int i=0;i<q;i++){
        if (t[i]<=time){
            pref[x[i]][y[i]]=1;
        }
    }
    for (int i=0;i<=n;i++){
        for (int j=0;j<=m;j++){
            pref[i][j]+=pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1];
        }
    }
    for (int i=0;i+k-1<=n;i++){
        for (int j=0;j+k-1<=m;j++){
            if (get(i,j,i+k-1,j+k-1)==k*k){
                return 1;
            }
        }
    }
    return 0;
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
    cin>>n>>m>>k>>q;
    for (int i=0;i<q;i++){
        cin>>x[i]>>y[i]>>t[i];
    }
    int l=0,r=1e10;
    while (r-l>1){
        int m=(l+r)/2;
        if (check(m)){
            r=m;
        }
        else{
            l=m;
        }
    }
    int res=r;
    if (!check(r)){
        res=-1;
    }
    elif (check(l)){
        res=l;
    }
    cout<<res<<"\n";
}