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

int n;
int a[arr];
int cnt1[arr];
int cnt2[arr];

int get1(int l,int r)
{
    if (l>r||r<1||l>n){
        return 0;
    }
    return cnt1[r]-cnt1[l-1];
}

int get2(int l,int r)
{
    if (l>r||r<1||l>n){
        return 0;
    }
    return cnt2[r]-cnt2[l-1];
}

int max_val[ar][ar];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        cnt1[i]=cnt1[i-1]+(a[i]==1);
        cnt2[i]=cnt2[i-1]+(a[i]==2);
    }
    int ans=0;
    for (int i=0;i<=n;i++){
        ans=max(ans,get1(1,i)+get2(i+1,n));
    }

    for (int i=1;i<=n;i++){
        int val=-1e9;
        for (int j=i;j<=n;j++){
            val=max(val,cnt2[j]-cnt1[j-1]);
            max_val[i][j]=val;
        }
    }

    for (int i=1;i<=n;i++){
        for (int j=i;j<=n;j++){
            int cur=0;
            cur+=get1(1,i-1);
            cur+=get2(j+1,n);
            cur+=-cnt2[i-1]+cnt1[j];
            cur+=max_val[i][j];
//            cout<<i<<" "<<j<<" "<<cur<<"\n";
            ans=max(ans,cur);
        }
    }
    cout<<ans<<"\n";
}