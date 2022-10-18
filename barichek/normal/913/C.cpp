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

int c[arr];

void build(int l,int r,vector<pii>& a)
{
    for (int mask=0;mask<(1ll<<(r-l+1));mask++){
        int cur_1=0;
        int cur_2=0;
        for (int i=l;i<=r;i++){
            int bit=i-l;
            if (mask&(1ll<<bit)){
                cur_1+=(1ll<<i);
                cur_2+=c[i];
            }
        }
        a.pb({cur_1,cur_2});
    }
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n,L;
    cin>>n>>L;
    for (int i=0;i<=31;i++){
        c[i]=3e18;
    }
    for (int i=0;i<n;i++){
        cin>>c[i];
    }
    for (int i=0;i<=31;i++){
        for (int j=0;j<i;j++){
            c[i]=min(c[i],c[j]*(1ll<<(i-j)));
        }
    }
    vector<pii> l(0);
    build(0,15,l);
    vector<pii> r(0);
    build(16,31,r);
    sort(all(l));
    sort(all(r));
    int ans=3e18;

    int p=len(r);
    int cost_r=3e18;
    for (int i=0;i<len(l);i++){
        while (p-1>=0&&r[p-1].fir+l[i].fir>=L){
            p--;
            cost_r=min(cost_r,r[p].sec);
        }
        if (p!=len(r)){
            ans=min(ans,l[i].sec+cost_r);
        }
    }
    cout<<ans<<"\n";
}