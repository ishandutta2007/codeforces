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

int a[arr];
int pref[arr];

ld cur_ans=-1e18;
int sz=0;
int val;

ld f(int prefix)
{
    int sum=0;
    sum+=pref[prefix];
    sum+=val;
    ld res=val-ld(sum)/(prefix+1);
    return res;
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int q;
    cin>>q;
    while (q--){
        int type;
        cin>>type;
        if (type==1){
            cin>>val;
            int l=0,r=sz;
            while (r-l>2){
                int m1=l+(r-l)/3;
                int m2=r-(r-l)/3;
                ld f_m1=f(m1);
                ld f_m2=f(m2);
                if (f_m1<f_m2){
                    l=m1;
                }
                else{
                    r=m2;
                }
            }
            ld res=0;
            for (int i=l;i<=r;i++){
                res=max(res,f(i));
            }
            cur_ans=res;
            a[++sz]=val;
            pref[sz]=pref[sz-1]+a[sz];
        }
        else{
            cout<<fixed<<setprecision(10)<<cur_ans<<"\n";
        }
    }
}