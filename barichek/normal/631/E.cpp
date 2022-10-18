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

struct line
{
    ld k,b;

    line() {}
    line(ld k,ld b)
    {
        this->k=k;
        this->b=b;
    }

    ld eval(ld x)
    {
        return k*x+b;
    }
};

inline ld intersect(line l1,line l2)
{
    return (l1.b-l2.b)/(l2.k-l1.k);
}

inline bool to_erase(line l1,line l2,line l3)
{
    ld x=intersect(l1,l3);
    return l2.eval(x)>=l3.eval(x);
}

struct convex_hull_trick1
{
    vector<line> lines;
    int sz;

    convex_hull_trick1()
    {
        lines.resize(arr);
        sz=0;
    }

    void add_line(line l)
    {
        l.k*=-1;
        l.b*=-1;

        lines[sz++]=l;

        while (sz>=3&&to_erase(lines[sz-3],lines[sz-2],lines[sz-1])){
            swap(lines[sz-2],lines[sz-1]);
            sz--;
        }
    }

    ld get(ld x)
    {
        if (sz==0){
            return 5e18;
        }
        int l=0;
        for (int i=20;i>=0;i--){
            if (l+(1ll<<i)<sz-1&&lines[l+(1ll<<i)+1].eval(x)<=lines[l+(1ll<<i)].eval(x)){
                l+=(1ll<<i);
            }
        }
        return min({lines[l].eval(x),l==sz-1?5e18:lines[l+1].eval(x),lines[sz-1].eval(x)});
    }
};

struct convex_hull_trick2
{
    vector<line> lines;
    int sz;

    convex_hull_trick2()
    {
        lines.resize(arr);
        sz=0;
    }

    void add_line(line l)
    {
        l.k*=-1;
        l.b*=-1;

        lines[sz++]=l;

        while (sz>=3&&to_erase(lines[sz-3],lines[sz-2],lines[sz-1])){
            swap(lines[sz-2],lines[sz-1]);
            sz--;
        }
    }

    ld get(ld x)
    {
        if (sz==0){
            return 5e18;
        }
        int l=0;
        for (int i=20;i>=0;i--){
            if (l+(1ll<<i)<sz-1&&lines[l+(1ll<<i)+1].eval(x)<=lines[l+(1ll<<i)].eval(x)){
                l+=(1ll<<i);
            }
        }
        return min({lines[l].eval(x),l==sz-1?5e18:lines[l+1].eval(x),lines[sz-1].eval(x)});
    }
};

int a[arr];
ll pref[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        pref[i]=pref[i-1]+a[i];
    }
    ll ans0=0;
    for (int i=1;i<=n;i++){
        ans0+=1ll*a[i]*i;
    }

    ll ans=ans0;

    /**

    push i on place j

    -(i-j)*a[i]+pref[i-1]-pref[j-1]

    -i*a[i]+j*a[i]+pref[i-1]-pref[j-1]

    */

    {
        convex_hull_trick1 kek;

        for (int i=1;i<=n;i++){
            ans=max(ans,ans0-(ll)kek.get(a[i])-1ll*i*a[i]+pref[i-1]);
            kek.add_line(line(i,-pref[i-1]));
        }
    }

    /**

    push i on place j

    (j-i)*a[i]-(pref[j]-pref[i])

    j*a[i]-i*a[i]-pref[j]+pref[i]

    */

    {
        convex_hull_trick2 kek;

        for (int i=n;i>=1;i--){
            ans=max(ans,ans0-(ll)kek.get(a[i])-1ll*i*a[i]+pref[i]);
            kek.add_line(line(i,-pref[i]));
        }
    }

    cout<<ans<<"\n";
}