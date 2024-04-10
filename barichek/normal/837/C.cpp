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

vector<pii> v;

bool ok(int a,int b,int c,int d)
{
    return a>=c&&b>=d;
}

int get(pii a)
{
    return a.fir*a.sec;
}

pii s(pii a)
{
//    if (a.fir>a.sec){
//        swap(a.fir,a.sec);
//    }
    return a;
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

    int n,a,b;
    cin>>n>>a>>b;
    while (n--){
        int x,y;
        cin>>x>>y;
        v.pb(mp(x,y));
    }
    int ans=0;
    for (int i=0;i<len(v);i++){
        for (int j=0;j<len(v);j++){
            if (i!=j/*&&v[i]!=v[j]*/){
                if (ok(a,b,v[i].fir,v[i].sec)){
                    if (ok(a-v[i].fir,b,v[j].fir,v[j].sec)){
                        ans=max(ans,get(v[i])+get(v[j]));
                    }
                    if (ok(a,b-v[i].sec,v[j].fir,v[j].sec)){
                        ans=max(ans,get(v[i])+get(v[j]));
                    }
                    swap(v[j].fir,v[j].sec);
                    if (ok(a-v[i].fir,b,v[j].fir,v[j].sec)){
                        ans=max(ans,get(v[i])+get(v[j]));
                    }
                    if (ok(a,b-v[i].sec,v[j].fir,v[j].sec)){
                        ans=max(ans,get(v[i])+get(v[j]));
                    }
                    swap(v[j].fir,v[j].sec);
                }
                swap(v[i].fir,v[i].sec);
                if (ok(a,b,v[i].fir,v[i].sec)){
                    if (ok(a-v[i].fir,b,v[j].fir,v[j].sec)){
                        ans=max(ans,get(v[i])+get(v[j]));
                    }
                    if (ok(a,b-v[i].sec,v[j].fir,v[j].sec)){
                        ans=max(ans,get(v[i])+get(v[j]));
                    }
                    swap(v[j].fir,v[j].sec);
                    if (ok(a-v[i].fir,b,v[j].fir,v[j].sec)){
                        ans=max(ans,get(v[i])+get(v[j]));
                    }
                    if (ok(a,b-v[i].sec,v[j].fir,v[j].sec)){
                        ans=max(ans,get(v[i])+get(v[j]));
                    }
                    swap(v[j].fir,v[j].sec);
                }
                swap(v[i].fir,v[i].sec);
            }
        }
    }
    cout<<ans<<"\n";
}