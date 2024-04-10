#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
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

#define md (int)(998244353)

int pw(int a,int n)
{
    int res=1;
    while (n--){
        res*=a;
    }
    return res;
}

int my_sqrt(int a,int b)
{
    int l=1,r;
    if (b==2){
        r=1.5e9;
    }
    if (b==3){
        r=1.5e6;
    }
    if (b==4){
        r=4e4;
    }
    while (r-l>0){
        int m=(l+r+1)/2;
        if (pw(m,b)>a){
            r=m-1;
        }
        else{
            l=m;
        }
    }
    if (pw(l,b)==a){
        return l;
    }
    else{
        return -1;
    }
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    map<int,int> cnt;
    map<int,int> lol1;

    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        int res2=my_sqrt(a,2);
        int res3=my_sqrt(a,3);
        int res4=my_sqrt(a,4);
        if (res4!=-1){
            cnt[res4]+=4;
            lol1[res4];
        }
        elif (res3!=-1){
            cnt[res3]+=3;
            lol1[res3];
        }
        elif (res2!=-1){
            cnt[res2]+=2;
            lol1[res2];
        }
        else{
            lol1[a]++;
        }
    }
    vector<pii> lol(all(lol1));
    for (int i=0;i<len(lol);i++){
        for (int j=i+1;j<len(lol);j++){
            if (__gcd(lol[i].fir,lol[j].fir)!=1){
                int g=__gcd(lol[i].fir,lol[j].fir);
                cnt[g]+=lol[i].sec;
                cnt[g]+=lol[j].sec;
                cnt[lol[i].fir/g]+=lol[i].sec;
                cnt[lol[j].fir/g]+=lol[j].sec;

                lol[i].sec=0;
                lol[j].sec=0;
            }
        }
    }
    int ans=1;
    for (auto i:lol){
        ans=ans*(i.sec+1)%md;
        ans=ans*(i.sec+1)%md;
    }
    for (auto i:cnt){
        ans=ans*(i.sec+1)%md;
//        cout<<i.fir<<" "<<i.sec<<"\n";
    }
    cout<<ans<<"\n";
}