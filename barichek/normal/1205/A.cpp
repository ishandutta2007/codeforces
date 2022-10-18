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

vi operator+(vi a1,vi a2)
{
    vi res(0);
    for (auto i:a1){
        res.pb(i);
    }
    for (auto i:a2){
        res.pb(i);
    }
    return res;
}

bool check(vi a)
{
    int mx=-1e18;
    int mn=1e18;
    int sum=0;
    for (int i=0;i<len(a)/2;i++){
        sum+=a[i];
    }
    for (int i=0;i<len(a);i++){
        mx=max(mx,sum);
        mn=min(mn,sum);
        sum-=a[i];
        sum+=a[(i+len(a)/2)%len(a)];
    }
    return mx-mn<=1;
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n;
    cin>>n;
    if (1){
        vector<int> a(0);
        vector<int> a1(0);
        vector<int> a2(0);
        int cur=1;
        while (cur<=2*n){
            if (cur+3<=2*n){
                a1.pb(cur);
                a1.pb(cur+3);
                a2.pb(cur+1);
                a2.pb(cur+2);
                cur+=4;
            }
            else{
                a1.pb(cur);
                a2.pb(cur+1);
                cur+=2;
            }
        }
        a=a1+a2;
        if (check(a)){
            cout<<"YES"<<"\n";
            for (auto i:a){
                cout<<i<<" ";
            }
            cout<<"\n";
            return 0;
        }
    }
    if (1){
        vector<int> a(0);
        vector<int> a1(0);
        vector<int> a2(0);
        int cur=1;
        while (cur<=2*n){
            if (cur+3<=2*n){
                a1.pb(cur);
                a1.pb(cur+3);
                a2.pb(cur+1);
                a2.pb(cur+2);
                cur+=4;
            }
            else{
                a1.pb(cur+1);
                a2.pb(cur);
                cur+=2;
            }
        }
        a=a1+a2;
        if (check(a)){
            cout<<"YES"<<"\n";
            for (auto i:a){
                cout<<i<<" ";
            }
            cout<<"\n";
            return 0;
        }
    }
    cout<<"NO"<<"\n";
}