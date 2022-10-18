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

int a[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n,s;
    cin>>n>>s;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int k=n/2;
    int ans=0;
    if (a[k]!=s){
        if (a[k]<s){
            for (int i=k;i<n;i++){
                if (a[i]<s){
                    ans+=s-a[i];
                }
            }
        }
        else{
            for (int i=0;i<=k;i++){
                if (a[i]>s){
                    ans+=a[i]-s;
                }
            }
        }
    }
    cout<<ans<<"\n";
}