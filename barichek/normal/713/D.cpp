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
///#define int long long

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

int pref[ar][ar];
int dp[ar][ar];
int st[ar/2][ar/2][10][10];
int lg[ar];

int get(int x1,int y1,int x2,int y2)
{
    x1--;
    y1--;

    int res=0;

    res+=pref[x2][y2];

    res-=pref[x1][y2];
    res-=pref[x2][y1];

    res+=pref[x1][y1];

    return res;
}

int get1(int x1,int y1,int x2,int y2)
{
//    cout<<"get1 :: "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<"\n";
    int len1=x2-x1+1;
    len1=lg[len1];
    int len2=y2-y1+1;
    len2=lg[len2];

//    cout<<"lens :: "<<len1<<" "<<len2<<"\n";

    int res=-1e9;

    res=max(res,st[x1][y1][len1][len2]);
    res=max(res,st[x1][y2-(1ll<<len2)+1][len1][len2]);
    res=max(res,st[x2-(1ll<<len1)+1][y1][len1][len2]);
    res=max(res,st[x2-(1ll<<len1)+1][y2-(1ll<<len2)+1][len1][len2]);

//    cout<<"res :: "<<res<<"\n";
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

    for (int i=2;i<ar;i++){
        lg[i]=lg[i/2]+1;
    }

    fast;

    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin>>pref[i][j];
            pref[i][j]+=pref[i][j-1]+pref[i-1][j]-pref[i-1][j-1];
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            for (int k=9;k>=0;k--){
                int x1=i+dp[i][j]+(1ll<<k)-1;
                int y1=j+dp[i][j]+(1ll<<k)-1;
                if (x1<=n&&y1<=m){
                    if (get(i,j,x1,y1)==(x1-i+1)*(x1-i+1)){
                        dp[i][j]+=(1ll<<k);
                    }
                }
            }
//            cout<<"dp["<<i<<"]["<<j<<"] :: "<<dp[i][j]<<"\n";
        }
    }
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            for (int x=1;x+(1ll<<i)-1<=n;x++){
                for (int y=1;y+(1ll<<j)-1<=m;y++){
                    if (i==0&&j==0){
                        st[x][y][0][0]=dp[x][y];
                    }
                    else{
                        if (i){
                            st[x][y][i][j]=max(st[x][y][i-1][j],st[x+(1ll<<(i-1))][y][i-1][j]);
                        }
                        else{
                            st[x][y][i][j]=max(st[x][y][i][j-1],st[x][y+(1ll<<(j-1))][i][j-1]);
                        }
                    }
                }
            }
        }
    }
    int q;
    cin>>q;
    while (q--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
//        cout<<"new :: "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<"\n";
        int l=0,r=min(x2-x1+1,y2-y1+1);
        while (r-l>1){
            int m=(l+r)/2;
//            cout<<"m :: "<<m<<"\n";
            if (get1(x1,y1,x2-m+1,y2-m+1)>=m){
                l=m;
            }
            else{
                r=m-1;
            }
        }
        int res=l;
        if (get1(x1,y1,x2-r+1,y2-r+1)>=r){
            res=r;
        }
        cout<<res<<"\n";
    }
}