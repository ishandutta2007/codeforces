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

int a[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    string b;
    cin>>b;
    int MIN_L=-1e9;
    int MAX_R=1e9;
    for (int i=4;i<n;i++){
        if (b[i]!=b[i-1]){
            if (b[i]=='0'){
                int min_A=min({a[i],a[i-1],a[i-2],a[i-3],a[i-4]});
                MAX_R=min(MAX_R,min_A-1);
            }
            else{
                int max_A=max({a[i],a[i-1],a[i-2],a[i-3],a[i-4]});
                MIN_L=max(MIN_L,max_A+1);
            }
        }
    }
    cout<<MIN_L<<" "<<MAX_R<<"\n";
}