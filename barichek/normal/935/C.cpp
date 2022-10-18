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

ld sqr(ld a)
{
    return a*a;
}

ld dist_2(ld x1,ld y1,ld x2,ld y2)
{
    return sqr(x1-x2)+sqr(y1-y2);
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    ld r,x1,y1,x2,y2;
    cin>>r>>x1>>y1>>x2>>y2;
    if (dist_2(x1,y1,x2,y2)>=r*r){
        cout<<fixed<<setprecision(10)<<x1<<" ";
        cout<<fixed<<setprecision(10)<<y1<<" ";
        cout<<fixed<<setprecision(10)<<r<<"\n";
    }
    else{
        if (x1==x2&&y1==y2){
            cout<<fixed<<setprecision(10)<<x1<<" ";
            cout<<fixed<<setprecision(10)<<y1+r/2.0<<" ";
            cout<<fixed<<setprecision(10)<<r/2.0<<"\n";
        }
        else{
            ld kek=sqrt(dist_2(x1,y1,x2,y2));
            ld kf=r/kek;
            ld xx=x1-(x2-x1)*kf;
            ld yy=y1-(y2-y1)*kf;
//            cout<<xx<<" "<<yy<<" !!\n";
            ld xxx=(xx+x2)/2.0;
            ld yyy=(yy+y2)/2.0;
            cout<<fixed<<setprecision(10)<<xxx<<" ";
            cout<<fixed<<setprecision(10)<<yyy<<" ";
            cout<<fixed<<setprecision(10)<<sqrt(dist_2(xxx,yyy,x2,y2))<<"\n";
        }
    }
}