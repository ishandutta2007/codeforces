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

#ifdef I_love_Maria_Ivanova
    #define debug if (1)
#else
    #define debug if (0)
#endif

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
    int n,q;
    cin>>n>>q;
    int max_deep=0;
    while ((1ll<<max_deep)!=n+1)
        max_deep++;
    max_deep--;
    cerr<<"max_deep :: "<<max_deep<<"\n";
    while (q--)
    {
        int u;
        string s;
        cin>>u>>s;
        int cur=(n+1)/2;
        int deep=0;
        while (cur!=u)
        {
            if (u<=cur)
                cur-=(1ll<<(max_deep-deep-1));
            else
                cur+=(1ll<<(max_deep-deep-1));
            deep++;
        }
        for (auto i:s)
        {
            //cerr<<u<<" "<<deep<<"\n";
            if (i=='L'){
                if (u%2==0)
                    u-=(1ll<<(max_deep-deep-1)),
                    deep++;
            }
            if (i=='R'){
                if (u%2==0)
                    u+=(1ll<<(max_deep-deep-1)),
                    deep++;
            }
            if (i=='U'){
                if (u!=(n+1)/2){
                    //cerr<<(u-(1ll<<(max_deep-deep)))<<" "<<(1ll<<(max_deep-deep+2))<<" !!\n";
                    if ((u-(1ll<<(max_deep-deep)))%(1ll<<(max_deep-deep+2))==0)
                        u+=(1ll<<(max_deep-deep));
                    else
                        u-=(1ll<<(max_deep-deep));
                    deep--;
                }
            }
            //cerr<<u<<" "<<deep<<"\n";
        }
        cout<<u<<"\n";
    }
}