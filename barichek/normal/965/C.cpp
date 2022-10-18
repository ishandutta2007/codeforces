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

int down(int a,int b)
{
    return a/b;
}

int up(int a,int b)
{
    return a/b+(a%b!=0);
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n,k,m,d;
    cin>>n>>k>>m>>d;
    int ans=0;
    for (int I=1;I<=d;I++){
        /// he will take i times
        int r=m+1;
        for (int i=60;i>=0;i--){
            if (r-(1ll<<i)>0&&up(down(n,r-(1ll<<i)),k)<I){
                r-=(1ll<<i);
            }
        }
        r--;
//        cout<<"I :: "<<I<<" r :: "<<r<<"\n";
        if (r!=0&&up(down(n,r),k)==I){
//            cout<<"answers :: "<<r<<" "<<I<<"\n";
            ans=max(ans,r*I);
        }
    }
    cout<<ans<<"\n";
}