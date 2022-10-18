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

ld k,d,t;
int cnt_d;
ld val1;

ld get(ld T)
{
    int lol=(int)(T/(d*cnt_d));
    ld res=0;
    res+=lol*val1;
    ld left=T-lol*(d*cnt_d);
    if (left<=k){
        res+=left*(ld(1)/t);
    }
    else{
        res+=k*(ld(1)/t);
        res+=(left-k)*(ld(1)/t)/2;
    }
    return res;
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int k_,d_;
    cin>>k_>>d_;
    cin>>t;
    k=k_;
    d=d_;
    cnt_d=k_/d_+(k_%d_!=0);
    val1=k*(ld(1)/t)+((d*cnt_d)-k)*(ld(1)/t)/2;
    ld l=0,r=1e40;
    for (int iter=0;iter<200;iter++){
        ld m=(l+r)/2;
        if (get(m)>=1){
            r=m;
        }
        else{
            l=m;
        }
    }
    cout<<fixed<<setprecision(10)<<l<<"\n";
}