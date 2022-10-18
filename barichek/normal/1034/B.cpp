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

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n,m;
    cin>>n>>m;
    if (n>m){
        swap(n,m);
    }
    if (n==1){
        if (m%6==0){
            cout<<m/6*6<<"\n";
        }
        if (m%6==1){
            cout<<m/6*6<<"\n";
        }
        if (m%6==2){
            cout<<m/6*6<<"\n";
        }
        if (m%6==3){
            cout<<m/6*6<<"\n";
        }
        if (m%6==4){
            cout<<m/6*6+2<<"\n";
        }
        if (m%6==5){
            cout<<m/6*6+4<<"\n";
        }
    }
    if (n==2){
        if (m==1){
            cout<<0<<"\n";
        }
        if (m==2){
            cout<<0<<"\n";
        }
        if (m==3){
            cout<<4<<"\n";
        }
        if (m==4){
            cout<<8<<"\n";
        }
        if (m==5){
            cout<<10<<"\n";
        }
        if (m==6){
            cout<<12<<"\n";
        }
        if (m==7){
            cout<<12<<"\n";
        }
        if (m>=8){
            cout<<n*m/2*2<<"\n";
        }
    }
    if (n>=3){
        cout<<n*m/2*2<<"\n";
    }
}