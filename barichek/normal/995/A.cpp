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

int n,k;
int a[5][arr];
vector<pair<int,pii>> ans;

bool ok()
{
    for (int i=2;i<=3;i++){
        for (int j=1;j<=n;j++){
            if (a[i][j]!=0){
                return 0;
            }
        }
    }
    return 1;
}

void push()
{
    for (int i=1;i<=n;i++){
        if (a[2][i]&&a[2][i]==a[1][i]){
            ans.pb({a[2][i],{1,i}});
            a[2][i]=0;
            a[1][i]=-1;
        }
    }
    for (int i=1;i<=n;i++){
        if (a[3][i]&&a[3][i]==a[4][i]){
            ans.pb({a[3][i],{4,i}});
            a[3][i]=0;
            a[4][i]=-1;
        }
    }
}

pii prev(int x,int y)
{
    if (x==2){
        if (y==1){
            return {3,1};
        }
        else{
            return {x,y-1};
        }
    }
    else{
        if (y==n){
            return {2,n};
        }
        else{
            return {3,y+1};
        }
    }
}

pii next(int x,int y)
{
    if (x==2){
        if (y==n){
            return {3,n};
        }
        else{
            return {x,y+1};
        }
    }
    else{
        if (y==1){
            return {2,1};
        }
        else{
            return {3,y-1};
        }
    }
}

void cyclic()
{
    int x=-1;
    int y=-1;
    for (int i=2;i<=3;i++){
        for (int j=1;j<=n;j++){
            if (a[i][j]==0){
                x=i;
                y=j;
            }
        }
    }
    if (x==-1){
        return;
    }

    int xx=x;
    int yy=y;
    pii lol1=prev(xx,yy);
    vector<pair<int,pii>> cur;
    for (int i=0;i<2*n;i++){
//        cout<<" ::: "<<lol1.fir<<" "<<lol1.sec<<" :: "<<xx<<" "<<yy<<" !!\n";
        if (a[lol1.fir][lol1.sec]){
//            cout<<lol1.fir<<" "<<lol1.sec<<" :: "<<xx<<" "<<yy<<" !!\n";
            ans.pb({a[lol1.fir][lol1.sec],{xx,yy}});
            cur.pb(ans.back());
        }
        xx=lol1.fir;
        yy=lol1.sec;
//        cout<<" kek :: "<<xx<<" "<<yy<<"\n";
        lol1=prev(xx,yy);
    }

    for (int i=2;i<=3;i++){
        for (int j=1;j<=n;j++){
            a[i][j]=0;
        }
    }
    for (auto i:cur){
        a[i.sec.fir][i.sec.sec]=i.fir;
    }
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    cin>>n>>k;
    for (int i=1;i<=4;i++){
        for (int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    if (k==2*n){
        bool any=0;
        for (int j=1;j<=n;j++){
            if (a[1][j]==a[2][j]){
                any=1;
            }
            if (a[3][j]==a[4][j]){
                any=1;
            }
        }
        if (!any){
            return cout<<-1<<"\n", 0;
        }
    }
    while (!ok()){
//        cout<<"not ok"<<"\n";
        push();
        cyclic();
    }
    cout<<len(ans)<<"\n";
    for (auto i:ans){
        cout<<i.fir<<" "<<i.sec.fir<<" "<<i.sec.sec<<"\n";
    }
}