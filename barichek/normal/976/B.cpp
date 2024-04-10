#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
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

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int n,m,k;
    cin>>n>>m>>k;
    if (k<=n){
        if (k!=n){
            cout<<k+1<<" "<<1<<"\n";
        }
        else{
            cout<<n<<" "<<2<<"\n";
        }
    }
    else{
        int len_cycle=0;
        len_cycle=2*(m-2)+2;
        k-=n;
        int cnt_full_cycle=k/len_cycle;
        int xx=n;
        int yy=2;
        xx-=2*cnt_full_cycle;
        k-=cnt_full_cycle*len_cycle;
        if (k<=m-2){
            yy+=k;
            cout<<xx<<" "<<yy<<"\n";
        }
        else{
            yy=m;
            k-=m-2;
            if (k==1){
                xx--;
                cout<<xx<<" "<<yy<<"\n";
            }
            else{
                k--;
                xx--;
                cout<<xx<<" "<<yy-k<<"\n";
            }
        }
    }
}