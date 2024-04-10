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

ll bs[arr];
int last;

void reverse1(int l,int r)
{
    while (l%60!=0&&l<=r){
        bs[l/60]^=(1ll<<(l%60));
        l++;
    }
    while (l+60<=r){
        bs[l/60]^=((1ll<<61)-1);
        l+=60;
    }
    while (l<=r){
        bs[l/60]^=(1ll<<(l%60));
        l++;
    }
}

void set1(int l,int r)
{
    while (l%60!=0&&l<=r){
        bs[l/60]|=(1ll<<(l%60));
        l++;
    }
    while (l+60<=r){
        bs[l/60]|=((1ll<<61)-1);
        l+=60;
    }
    while (l<=r){
        bs[l/60]|=(1ll<<(l%60));
        l++;
    }
}

ll del_bit(ll mask,int bit)
{
    if (mask&(1ll<<bit)){
        mask^=(1ll<<bit);
    }
    return mask;
}

void delete1(int l,int r)
{
    while (l%60!=0&&l<=r){
        bs[l/60]=del_bit(bs[l/60],l%60);
        l++;
    }
    while (l+60<=r){
        bs[l/60]=0;
        l+=60;
    }
    while (l<=r){
        bs[l/60]=del_bit(bs[l/60],l%60);
        l++;
    }
}

map<ll,int> vh;
ll rvh[3*arr];

ll mex()
{
    int l=0;
    while (bs[l/60]==((1ll<<61)-1)){
        l+=60;
    }
    while (bs[l/60]&(1ll<<(l%60))){
        l++;
    }
    return rvh[l];
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

    int n;
    scanf("%d",&n);
    vector<pair<int,pair<ll,ll>>> q(n);
    for (auto& i:q){
        scanf("%d%lld%lld",&i.fir,&i.sec.fir,&i.sec.sec);
        vh[i.sec.fir];
        vh[i.sec.sec];
        vh[i.sec.sec+1];
    }
    vh[1];
    int cnt=0;
    for (auto& i:vh){
        i.sec=cnt++;
        rvh[i.sec]=i.fir;
    }
    for (auto i:q){
        int type=i.fir;
        ll l=i.sec.fir;
        ll r=i.sec.sec;
        l=vh[l];
        r=vh[r];
        if (type==1){
            set1(l,r);
        }
        if (type==2){
            delete1(l,r);
        }
        if (type==3){
            reverse1(l,r);
        }
        cout<<mex()<<"\n";
    }
}