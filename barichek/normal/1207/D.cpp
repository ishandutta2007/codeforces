//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC optimize("unroll-loops")
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

#define md (ll)(998244353ll)

#define arr (int)(3e5+10)

pii a[arr];
int f[arr];

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    f[0]=1;
    for (int i=1;i<arr;i++){
        f[i]=f[i-1]*i%md;
    }

    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i].fir>>a[i].sec;
    }

    int cnt1=1;
    sort(a,a+n);
    for (int i=0;i<n;){
        int j=i;
        while (j<n&&a[j].fir==a[i].fir){
            j++;
        }
        cnt1=cnt1*f[j-i]%md;
        i=j;
    }

    int cnt2=1;
    for (int i=0;i<n;i++){
        swap(a[i].fir,a[i].sec);
    }
    sort(a,a+n);
    for (int i=0;i<n;){
        int j=i;
        while (j<n&&a[j].fir==a[i].fir){
            j++;
        }
        cnt2=cnt2*f[j-i]%md;
        i=j;
    }
    for (int i=0;i<n;i++){
        swap(a[i].fir,a[i].sec);
    }

    int cnt12=1;
    sort(a,a+n);
    for (int i=1;i<n;i++){
        if (a[i].sec<a[i-1].sec){
            cnt12=0;
        }
    }
    map<pii,int> cnt;
    for (int i=0;i<n;i++){
        cnt[a[i]]++;
    }
    for (auto i:cnt){
        cnt12=cnt12*f[i.sec]%md;
    }

//    cout<<cnt1<<"\n";
//    cout<<cnt2<<"\n";
//    cout<<cnt12<<"\n";

    cout<<((f[n]-cnt1-cnt2+cnt12)%md+md)%md<<"\n";
}