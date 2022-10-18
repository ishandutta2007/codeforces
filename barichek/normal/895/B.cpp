#pragma GCC optimize("O3")
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

map<int,int> cnt;
int a[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;
    int n,x,k;
    cin>>n>>x>>k;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    if (k==0){
        sort(a,a+n);
        int ans=0;
        for (int i=0;i<n;i++){
            if (a[i]%x!=0){
                ans++;
            }
        }
        map<int,int> cnt1;
        for (int i=0;i<n;i++){
            cnt1[a[i]]++;
        }
        for (auto i:cnt1){
            if (i.fir%x!=0){
                ans+=i.sec*(i.sec-1)/2;
            }
        }
        int cur=0;
        for (int i=0;i<n;i++){
            if (i&&(a[i]/x!=a[i-1]/x||a[i]%x==0||a[i-1]%x==0)){
                cur=0;
            }
            ans+=cur;
            cur++;
        }
        cout<<ans<<"\n";
        return 0;
    }
    int ans=0;
    for (int i=0;i<n;i++){
        cnt[a[i]/x+(a[i]%x!=0)]++;
        ans+=cnt[a[i]/x-k+1];
    }
    cnt.clear();
    reverse(a,a+n);
    for (int i=0;i<n;i++){
        ans+=cnt[a[i]/x-k+1];
        cnt[a[i]/x+(a[i]%x!=0)]++;
    }
    cout<<ans<<"\n";
}