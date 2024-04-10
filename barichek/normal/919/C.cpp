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

int a[ar][ar];
string s[arr];
int pref[ar][ar];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n,m,k;
    cin>>n>>m>>k;
    for (int i=0;i<n;i++){
        cin>>s[i];
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            a[i][j]=(s[i-1][j-1]=='*');
        }
    }
    if (k==1){
        int ans=0;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                ans+=(a[i][j]==0);
            }
        }
        return cout<<ans<<"\n", 0;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            pref[i][j]=0;
            pref[i][j]=pref[i-1][j]+a[i][j];
        }
    }
    int ans=0;
    for (int i=1;i+k-1<=n;i++){
        for (int j=1;j<=m;j++){
            int cur=0;
            cur=pref[i+k-1][j]-pref[i-1][j];
            if (cur==0){
                ans++;
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            pref[i][j]=0;
            pref[i][j]=pref[i][j-1]+a[i][j];
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j+k-1<=m;j++){
            int cur=0;
            cur=pref[i][j+k-1]-pref[i][j-1];
            if (cur==0){
                ans++;
            }
        }
    }
    cout<<ans<<"\n";
}