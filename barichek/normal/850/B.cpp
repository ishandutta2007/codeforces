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

#define arr (int)(2e6+10)

int cnt[arr];
pii cnt1[arr];

pii operator+(pii a,pii b)
{
    return mp(a.fir+b.fir,a.sec+b.sec);
}

pii operator-(pii a,pii b)
{
    return mp(a.fir-b.fir,a.sec-b.sec);
}

int get(int l,int r)
{
    return cnt[r]-(l==0?0:cnt[l-1]);
}

pii get1(int l,int r)
{
    return cnt1[r]-(l==0?mp(0ll,0ll):cnt1[l-1]);
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
    int n,x,y;
    cin>>n>>x>>y;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        cnt[a]++;
        cnt1[a]=cnt1[a]+mp(1ll,a);
    }
    for (int i=1;i<arr;i++){
        cnt[i]+=cnt[i-1];
        cnt1[i]=cnt1[i]+cnt1[i-1];
    }
    int ans=n*x;
    for (int i=2;i<arr;i++){
//        cerr<<"III :: "<<i<<"\n";
        int cur_ans=0;
        for (int j=i;j<arr;j+=i){
//            cerr<<j<<" :: "<<j<<"\n";
            int l=j-i+1,r=j;
            if (r-l>x/y){
                cur_ans+=get(l,r-x/y-1)*x;
                auto kek=get1(r-x/y,r);
//                cerr<<"kek1 :: "<<kek.fir<<" "<<kek.sec<<"\n";
                cur_ans+=(kek.fir*r-kek.sec)*y;
            }
            else{
                auto kek=get1(l,r);
//                cerr<<"2 :: "<<l<<" "<<r<<"\n";
//                cerr<<"kek2 :: "<<kek.fir<<" "<<kek.sec<<"\n";
                cur_ans+=(kek.fir*r-kek.sec)*y;
            }
        }
//        cerr<<"i :: "<<i<<" :::: "<<cur_ans<<"\n";
        ans=min(ans,cur_ans);
    }
    cout<<ans<<"\n";
}