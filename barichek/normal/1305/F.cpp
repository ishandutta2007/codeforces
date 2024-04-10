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
const ll inf=1e18+10;
 
///---program start---///
 
int ans=inf;
 
int n;
int a[arr];
 
void check_prime(int pr)
{
    // cout<<"pr :: "<<pr<<"\n";
    int res=0;
    for (int i=0;i<n;i++){
        if (a[i]<pr){
            res+=pr-a[i];
            continue;
        }
        int ost=a[i]%pr;
        res+=min(ost,pr-ost);
    }
    // cout<<res<<"\n";
    ans=min(ans,res);
}
 
void check(int a)
{
    for (int i=2;i*i<=a;i++){
        if (a%i==0){
            check_prime(i);
            while (a%i==0){
                a/=i;
            }
        }
    }
    if (a!=1){
        check_prime(a);
    }
}
 
main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif
    
    srand(time(0));
    
    auto start = clock();
    
    fast;
    
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    while (double(clock()-start)/CLOCKS_PER_SEC<2.0){
        random_shuffle(a,a+n);
        int cur=a[0];
        check(cur);
        if (cur!=1){
            check(cur-1);
        }
        check(cur+1);
    }
    cout<<ans<<"\n";
}