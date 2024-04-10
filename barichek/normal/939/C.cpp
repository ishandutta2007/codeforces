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

int n;
int a[arr];
int pref[arr];

int get(int l,int r)
{
    if (l<=r){
        return pref[r]-pref[l-1];
    }
    return pref[n]-pref[l-1]+pref[r];
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        pref[i]=pref[i-1]+a[i];
    }
    int s,f;
    cin>>s>>f;
    f--;
    pii ans={-1e9,-1};
    for (int i=1;i<=n;i++){
        int cur=0;
        int L=s-i+1;
        int R=f-i+1;
        if (L<=0){
            L+=n;
        }
        if (R<=0){
            R+=n;
        }
//        cout<<i<<" "<<L<<" "<<R<<" !!!\n";
        cur=get(L,R);
//        cout<<i<<" "<<cur<<"\n";
        ans=max(ans,{cur,-i});
    }
    cout<<-ans.sec<<"\n";
}