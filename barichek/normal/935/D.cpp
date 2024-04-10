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

int bpow(int a,int n)
{
    int res=1;
    while (n){
        if (n&1){
            res=res*a%md;
        }
        n/=2;
        a=a*a%md;
    }
    return res;
}

int inv(int a)
{
    return bpow(a,md-2);
}

int equal_pref[arr];
int a[arr];
int b[arr];

int sum(int n)
{
    return n*(n+1)%md*inv(2)%md;
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=1;i<=n;i++){
        cin>>b[i];
    }
    equal_pref[0]=1;
    for (int i=1;i<=n;i++){
        if (a[i]==0&&b[i]==0){
            equal_pref[i]=equal_pref[i-1]*inv(m)%md;
        }
        elif (a[i]==0&&b[i]!=0){
            equal_pref[i]=equal_pref[i-1]*inv(m)%md;
        }
        elif (a[i]!=0&&b[i]==0){
            equal_pref[i]=equal_pref[i-1]*inv(m)%md;
        }
        elif (a[i]==b[i]){
            equal_pref[i]=equal_pref[i-1];
        }
        else{
            equal_pref[i]=0;
        }
    }
    int ans=0;
    for (int i=1;i<=n;i++){
        /// equal on pref [1;i)
        /// in i a[i]>b[i]
        int kf=0;
        if (a[i]==0&&b[i]==0){
            kf=sum(m-1)*inv(m*m%md)%md;
        }
        elif (a[i]==0&&b[i]!=0){
            int kek=m-b[i];
            kf=kek*inv(m)%md;
        }
        elif (a[i]!=0&&b[i]==0){
            int kek=a[i]-1;
            kf=kek*inv(m)%md;
        }
        else{
            if (a[i]>b[i]){
                kf=1;
            }
            else{
                kf=0;
            }
        }
        int cur=0;
        cur=equal_pref[i-1]*kf%md;
        ans+=cur;
        ans%=md;
    }
    cout<<ans<<"\n";
}