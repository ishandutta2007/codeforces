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

int a[arr];
int b[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=1;i<=m;i++){
        cin>>b[i];
    }
    int X;
    cin>>X;

    vector<pii> kek(0);
    for (int i=1;i<=n;i++){
        int cur=0;
        for (int j=i;j<=n;j++){
            cur+=a[j];
            kek.pb({cur,j-i+1});
        }
    }
    sort(all(kek));

    vi pref_max(len(kek));

    pref_max[0]=kek[0].sec;
    for (int i=1;i<len(pref_max);i++){
        pref_max[i]=max(pref_max[i-1],kek[i].sec);
    }
    int ans=0;
    for (int i=1;i<=m;i++){
        int cur=0;
        for (int j=i;j<=m;j++){
            cur+=b[j];
            int want=X/cur;
            if (kek[0].fir<=want){
                int pos=upper_bound(all(kek),mp(want,(int)md))-kek.begin();
                pos--;
//                cout<<"want :: "<<want<<" && pos :: "<<pos<<"\n";
                ans=max(ans,(j-i+1)*pref_max[pos]);
            }
        }
    }
    cout<<ans<<"\n";
}