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

int kek[arr];

int ask(int val)
{
    fflush(stdout);
    cout<<val<<"\n";
    fflush(stdout);
    int res;
    cin>>res;
    fflush(stdout);
    if (res==0){
        exit(0);
    }
    fflush(stdout);
    return res;
}

main()
{
//    #ifdef I_love_Maria_Ivanova
//        files("barik");
//        freopen("debug.txt","w",stderr);
//    #endif

    int m,n;
    cin>>m>>n;
    for (int i=0;i<n;i++){
        kek[i]=ask(1);
    }

    int num=0;

    int l=1,r=m;
    while (r-l>0){
        int m=(l+r)/2;
        int cur=ask(m);
        if (kek[num%n]==-1){
            cur*=-1;
        }
        if (cur==-1){
            r=m-1;
        }
        else{
            l=m+1;
        }
        num++;
    }
    ask(l);
}