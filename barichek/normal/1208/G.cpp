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

#define arr (int)(1e6+10)

int phi[arr];
int d[arr];

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    for (int i=2;i<arr;i++){
        if (d[i]==0){
            d[i]=i;
            for (int j=2*i;j<arr;j+=i){
                if (d[j]==0){
                    d[j]=i;
                }
            }
        }
    }

    for (int i=2;i<arr;i++){
        phi[i]=i;
        int cur=i;
        while (cur!=1){
            int dd=d[cur];
            while (cur%dd==0){
                cur/=dd;
            }
            phi[i]=phi[i]-phi[i]/dd;
        }
    }

    int n,k;
    cin>>n>>k;

    if (k==1){
        cout<<3<<"\n";
        return 0;
    }

    vector<int> anses(0);
    for (int i=3;i<=n;i++){
        anses.pb(phi[i]);
    }
    sort(all(anses));
    int res=0;
    for (int i=0;i<k;i++){
        res+=anses[i];
    }
    cout<<res+2<<"\n";
}