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

int dil[arr];
vi pp[arr];

int get(int p,int x) /// count y, y<=x && gcd(y,p)==1
{
    int res=0;
    for (int m=0;m<(1ll<<len(pp[p]));m++){
        int kek=1;
        for (int j=0;j<len(pp[p]);j++){
            if (m&(1ll<<j)){
                kek*=pp[p][j];
            }
        }
        if (__builtin_popcountll(m)%2==0){
            res+=x/kek;
        }
        else{
            res-=x/kek;
        }
    }
    return res;
}

int get(int x,int p,int k)
{
    int l=x,r=1e9;

    int rem=get(p,x);

    while (r-l>0){
        int m=(l+r+1)/2;
        if (get(p,m)-rem<k){
            l=m;
        }
        else{
            r=m-1;
        }
    }

    return l+1;
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif


    for (int i=2;i<arr;i++){
        if (!dil[i]){
            dil[i]=i;
            for (int j=2*i;j<arr;j+=i){
                if (!dil[j]){
                    dil[j]=i;
                }
            }
        }
    }

    for (int i=2;i<arr;i++){
        int cur=i;
        while (cur!=1){
            int cur_dil=dil[cur];
            while (cur%cur_dil==0){
                cur/=cur_dil;
            }
            pp[i].pb(cur_dil);
        }
        sort(all(pp[i]));
    }

    int test;
    cin>>test;
    while (test--){
        int x,p,k;
        cin>>x>>p>>k;
        if (p==1){
            cout<<x+k<<"\n";
        }
        else{
            cout<<get(x,p,k)<<"\n";
        }
    }
}