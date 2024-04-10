#pragma GCC optimize("O3")
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

int n,T;
int a[arr];
int t[arr];

bool check(int x)
{
    vector<pii> q;
    for (int i=1;i<=n;i++){
        if (a[i]>=x){
            q.pb({t[i],i});
        }
    }
    sort(all(q));
    if (len(q)<x){
        return 0;
    }
    int res=0;
    for (int i=0;i<x;i++){
        res+=q[i].fir;
    }
    return res<=T;
}

void print(int x)
{
    vector<pii> q;
    for (int i=1;i<=n;i++){
        if (a[i]>=x){
            q.pb({t[i],i});
        }
    }
    sort(all(q));
    if (len(q)<x){
        assert(0);
    }
    for (int i=0;i<x;i++){
        cout<<q[i].sec<<" ";
    }
    cout<<"\n";
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;
    cin>>n>>T;
    for (int i=1;i<=n;i++){
        cin>>a[i]>>t[i];
    }
    int l=0,r=n;
    while (r-l>0){
        int m=(l+r+1)/2;
        if (check(m)){
            l=m;
        }
        else{
            r=m-1;
        }
    }
    cout<<l<<"\n";
    cout<<l<<"\n";
    print(l);
}