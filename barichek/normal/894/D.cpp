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

#define arr (int)(1e6+10)

int n;
int l[arr];
int r[arr];
vector<ll> v[arr];
vector<ll> pref[arr];
vector<ll> v1;
vector<ll> v2;

ostream& operator<<(ostream& os,vector<ll> a)
{
    os<<"{";
    for (int i=0;i<len(a);i++){
        if (i){
            os<<",";
        }
        os<<a[i];
    }
    os<<"}";
    return os;
}

void dfs(int now)
{
    if (now*2<=n){
        dfs(now*2);
    }
    if (now*2+1<=n){
        dfs(now*2+1);
    }
    v1.clear();
    v2.clear();
    v1.pb(0);
    if (now*2<=n){
        for (auto q:v[now*2]){
            v1.pb(q+l[now]);
        }
    }
    if (now*2+1<=n){
        for (auto q:v[now*2+1]){
            v2.pb(q+r[now]);
        }
    }
    v[now].resize(len(v1)+len(v2));
    merge(all(v1),all(v2),v[now].begin());
    for (int i=0;i<len(v[now]);i++){
        pref[now].pb((i==0?0:pref[now][i-1])+v[now][i]);
    }
//    cout<<"v["<<now<<"] :: "<<v[now]<<"\n";
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int m;
    cin>>n>>m;
    for (int i=1;i<=n-1;i++){
        int from=(i+1)/2;
        int to=i+1;
        int value;
        scanf("%d",&value);
//        cout<<from<<" -> "<<to<<" :: "<<value<<"\n";
        if (2*from==to){
            l[from]=value;
        }
        else{
            r[from]=value;
        }
    }
    dfs(1);
    while (m--){
        int A;
        ll h;
        scanf("%d%lld",&A,&h);
        ll ans=0;
        /// down
        int cnt=lower_bound(all(v[A]),h)-v[A].begin();
        if (cnt!=0){
            ans+=h*cnt-pref[A][cnt-1];
        }
//        cout<<"start ans :: "<<ans<<"\n";
        /// up
        ll lol=0;
        while (A!=1){
            int to=A/2;
            if (2*to==A){
                lol+=l[to];
                ans+=max(0ll,h-lol);
                if (2*to+1<=n){
                    int cnt=lower_bound(all(v[2*to+1]),h-lol-r[to])-v[2*to+1].begin();
                    if (cnt!=0){
                        ans+=h*cnt-lol*cnt-1ll*r[to]*cnt-pref[2*to+1][cnt-1];
                    }
                }
            }
            else{
                lol+=r[to];
                ans+=max(0ll,h-lol);
                if (2*to<=n){
                    int cnt=lower_bound(all(v[2*to]),h-lol-l[to])-v[2*to].begin();
                    if (cnt!=0){
                        ans+=h*cnt-lol*cnt-1ll*l[to]*cnt-pref[2*to][cnt-1];
                    }
                }
            }
            A/=2;
        }
        cout<<ans<<"\n";
    }
}