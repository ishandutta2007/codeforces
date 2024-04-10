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

#define arr (int)(1e6+10)

int inv(int a,int m=md)
{
    return a==1?1:(1-inv(m%a,a)*m)/a+m;
}

int f[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    f[0]=1;
    for (int i=1;i<arr;i++){
        f[i]=f[i-1]*i%md;
    }

    fast;

    int n;
    cin>>n;
    map<int,int> cnt;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        cnt[a]++;
    }
    cnt.erase((--cnt.end()));
    int ans=0;
    int cur=n;
    for (auto i:cnt){
        cur--;
        /// cur! * left(n-1-cur) posons
        /// let we have (1+cur) posons
        /// where another? (2+cur)*(3+cur)*...*n
        int current=i.fir*i.sec%md*f[n]%md*inv(cur+1)%md;
//        cout<<i.fir<<" "<<i.sec<<" :: "<<current<<"\n";
        cur++;

        cur-=i.sec;

        ans+=current;
        if (ans>=md){
            ans-=md;

        }
    }
    cout<<ans<<"\n";
}