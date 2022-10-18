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

int cnt[101][101][11];

int c;

int get(int k,int t)
{
    t%=c+1;
    int ans=k+t;
    if (ans>c){
        ans-=c+1;
    }
    return ans;
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
    int n,q;
    cin>>n>>q>>c;
    while (n--){
        int x,y,s;
        cin>>x>>y>>s;
        cnt[x][y][s]++;
    }
    for (int k=0;k<=10;k++){
        for (int i=1;i<=100;i++){
            for (int j=1;j<=100;j++){
                cnt[i][j][k]+=cnt[i-1][j][k]+cnt[i][j-1][k]-cnt[i-1][j-1][k];
            }
        }
    }
    while (q--){
        int x1,y1,x2,y2,t;
        cin>>t>>x1>>y1>>x2>>y2;
        x1--;
        y1--;
        int ans=0;
        for (int k=0;k<=c;k++){
            int cur=0;

            cur+=cnt[x2][y2][k];

            cur-=cnt[x1][y2][k];
            cur-=cnt[x2][y1][k];

            cur+=cnt[x1][y1][k];

//            cout<<"k :: "<<k<<" && cur :: "<<cur<<"\n";

            ans+=cur*get(k,t);
        }
        cout<<ans<<"\n";
    }
}