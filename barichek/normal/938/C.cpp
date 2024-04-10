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

void solve()
{
//    cout<<"testtttttt"<<"\n";
    int x;
    cin>>x;
    if (x==0){
        cout<<1<<" "<<1<<"\n";
        return;
    }
    for (int i=1;i*i<=x;i++){
        if (x%i==0){
            int a=i; /// (n-(n/m))
            int b=x/i; /// (n+(n/m))
//            cout<<a<<" "<<b<<" !!\n";
            int sum=a+b;
            if (sum%2==1){
                continue;
            }
            int n=(sum/2);
//            cout<<n<<" !!!\n";
            int n_div_m=n-a;
            if (n_div_m<=0){
                continue;
            }
            int m=n/n_div_m;
            if (m>n){
                continue;
            }
            if (m<=0){
                continue;
            }
            if (n<=0){
                continue;
            }
            if (max(n,m)>1e9){
                continue;
            }
            if (n-(n/m)!=a){
                continue;
            }
            if (n+(n/m)!=b){
                continue;
            }
            cout<<n<<" "<<m<<"\n";
            return;
        }
    }
    cout<<-1<<"\n";
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int test;
    cin>>test;
    while (test--){
        solve();
    }
}