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

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #else
        files("");
        files_ds("");
    #endif

    int n;
    cin>>n;
    int ans=1e15;
    for (int i=1;i<=n;i++){
        int x=i,y=n/i;
        if (x<y){
            swap(x,y);
        }
        int cur_ans=2*x+2*y;
        int another=n-x*y;
        if (another>x){
            cur_ans+=2;
            cur_ans+=2;
        }
        elif (another){
            cur_ans+=2;
        }
//        cout<<i<<" :: "<<cur_ans<<"\n";
        ans=min(ans,cur_ans);
    }
    cout<<ans<<"\n";
}