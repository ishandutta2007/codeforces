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

bool cmp(pair<pii,int> a,pair<pii,int> b)
{
    return a.fir.fir<b.fir.fir||(a.fir.fir==b.fir.fir&&a.fir.sec>b.fir.sec);
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n;
    cin>>n;
    vector<pair<pii,int>> a(n);
    for (auto& i:a){
        cin>>i.fir.fir>>i.fir.sec;
    }
    for (int i=0;i<len(a);i++){
        a[i].sec=i+1;
    }
    sort(all(a),cmp);
    int max_val=-1e9;
    int max_id=-1;
    for (int i=0;i<len(a);i++){
        if (a[i].fir.sec<=max_val){
            return cout<<a[i].sec<<" "<<max_id<<"\n", 0;
        }
        if (a[i].fir.sec>max_val){
            max_val=a[i].fir.sec;
            max_id=a[i].sec;
        }
    }
    cout<<-1<<" "<<-1<<"\n";
}