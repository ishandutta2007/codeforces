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

ld get_atan2(int y,int x)
{
    ld res=atan2(y,x);
    if (res<0){
        res+=2.*pi;
    }
    return res;
}

struct poson
{
    ld x,y;
    int id;
    ld alpha;

    poson()
    {
        x=y=0;
        id=0;
    }

    ld get_alpha()
    {
        if (x==0){
            if (y>0){
                return pi/2.;
            }
            if (y<0){
                return 3.*pi/2.;
            }
        }
        if (x>=0&&y>=0){
            return atan(abs(y)/abs(x));
        }
        if (x<=0&&y>=0){
            return pi-atan(abs(y)/abs(x));
        }
        if (x<=0&&y<=0){
            return pi+atan(abs(y)/abs(x));
        }
        if (x>=0&&y<=0){
            return 2.*pi-atan(abs(y)/abs(x));
        }
    }
    void set_alpha()
    {
        alpha=get_alpha();
        assert(fabs(alpha-get_atan2(y,x))<=eps);
    }
};

const bool operator<(const poson& lhs,const poson& rhs)
{
    return lhs.alpha<rhs.alpha;
}

ld delta(const poson& lhs,const poson& rhs)
{
    if (rhs.alpha<lhs.alpha){
        return 2*pi-lhs.alpha+rhs.alpha;
    }
    return rhs.alpha-lhs.alpha;
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #else
        files("");
        files_ds("");
    #endif

    fast;
    int n;
    cin>>n;
    vector<poson> a(n);
    int num=0;
    for (auto& i:a){
        cin>>i.x>>i.y;
        i.id=++num;
        i.set_alpha();
    }
    sort(all(a));
    ld ans=1e9;
    int ans1=-1;
    int ans2=-1;
    for (int i=0;i<len(a);i++){
        if (ans>delta(a[i],a[(i+1)%len(a)])){
            ans=delta(a[i],a[(i+1)%len(a)]);
            ans1=a[i].id;
            ans2=a[(i+1)%len(a)].id;
        }
    }
    cout<<ans1<<" "<<ans2<<"\n";
}