//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC optimize("unroll-loops")
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

int n;
int a[arr];
int x,A;
int y,B;
int k;

bool check(int c)
{
    int cnt_ab=c/(A*B/__gcd(A,B));
    int cnt_a=c/A-cnt_ab;
    int cnt_b=c/B-cnt_ab;
    int res=0;
    int pos=0;
    while (cnt_ab>0){
        pos++;
        res+=(x+y)*a[pos];
        cnt_ab--;
    }
    while (cnt_b>0){
        pos++;
        res+=(y)*a[pos];
        cnt_b--;
    }
    while (cnt_a>0){
        pos++;
        res+=(x)*a[pos];
        cnt_a--;
    }
    return res>=k;
}

void solve()
{
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        a[i]/=100;
    }
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    cin>>x>>A;
    cin>>y>>B;
    cin>>k;

    if (x>y){
        swap(x,y);
        swap(A,B);
    }
    if (!check(n)){
        cout<<-1<<"\n";
        return;
    }
    int l=1,r=n;
    while (r-l>0){
        int m=(l+r)/2;
        if (check(m)){
            r=m;
        }
        else{
            l=m+1;
        }
    }
    cout<<l<<"\n";
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int q;
    cin>>q;
    while (q--){
        solve();
    }
}