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

#define arr (int)(1e6+10)

bool had[arr];
bool had1[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n;
    cin>>n;
    vi a(n);
    for (auto& i:a){
        cin>>i;
        had[i]=1;
    }
    if (had[1]){
        vi ans(0);
        for (auto i:a){
            ans.pb(i);
            ans.pb(1);
        }
        cout<<len(ans)<<"\n";
        for (auto i:ans){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    else{
        vi ans(0);
        for (auto i:a){
            ans.pb(i/a[0]);
            ans.pb(1);
        }
        for (int i=0;i<len(ans);i++){
            int kek=0;
            for (int j=i;j<len(ans);j++){
                kek=__gcd(kek,a[0]*ans[j]);
                had1[kek]=1;
            }
        }
        for (int i=0;i<arr;i++){
            if (had[i]!=had1[i]){
                return cout<<-1<<"\n", 0;
            }
        }
        cout<<len(ans)<<"\n";
        for (auto i:ans){
            cout<<i*a[0]<<" ";
        }
        cout<<"\n";
    }
}