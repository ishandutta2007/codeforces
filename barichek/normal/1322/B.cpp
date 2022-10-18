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
const ll inf=1e18+10;
 
///---program start---///

const int M=25;
const int N=1e7+10;

int a[10*arr];
int pref_cnt[N];
int b[10*arr];

int get_pref_cnt(int pos)
{
    if (pos>=N){
        return pref_cnt[N-1];
    }
    else{
        return pref_cnt[pos];
    }
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif
    
    fast;
    
    int n;
    cin>>n;
    // n=1000;
    for (int i=0;i<n;i++){
        cin>>a[i];
        // a[i]=rand()%10000;
        // cout<<"a[i]::"<<a[i]<<"\n";
    }
    
    // int brute=0;
    // for (int i=0;i<n;i++){
    //     for (int j=i+1;j<n;j++){
    //         brute^=(a[i]+a[j]);
    //     }
    // }
    // cout<<"brute :: "<<brute<<"\n";
    
    int ans=0;
    for (int j=0;j<M;j++){
        for (int i=0;i<N;i++){
            pref_cnt[i]=0;
        }
        for (int i=0;i<n;i++){
            b[i]=a[i]&((1ll<<(j+1))-1);
            pref_cnt[b[i]]++;
        }
        for (int i=1;i<N;i++){
            pref_cnt[i]+=pref_cnt[i-1];
        }
        int ways=0;
        for (int i=0;i<n;i++){
            int left_ways=0;
            left_ways+=get_pref_cnt((1ll<<(j+1))-1-b[i])-(b[i]>=(1ll<<j)?0:get_pref_cnt((1ll<<(j))-b[i]-1));
            left_ways+=get_pref_cnt((1ll<<(j+2))-1-b[i])-get_pref_cnt((1ll<<(j+1))+(1ll<<j)-b[i]-1);
            
            if (b[i]+b[i]>=(1ll<<j)&&b[i]+b[i]<(1ll<<(j+1))){
                left_ways--;
            }
            if (b[i]+b[i]>=(1ll<<(j+1))+(1ll<<j)&&b[i]+b[i]<(1ll<<(j+2))){
                left_ways--;
            }
            ways+=left_ways;
        }
        ways/=2;
        // cout<<j<<" "<<ways<<"\n";
        if (ways%2==1){
            ans^=(1ll<<j);
        }
    }
    cout<<ans<<"\n";
}