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
///#define int long long

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

vi vh[arr];
int a[arr];

inline int get_cnt(int l,int r,int x)
{
    return upper_bound(all(vh[x]),r)-lower_bound(all(vh[x]),l);
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        vh[a[i]].pb(i);
    }
    while (m--){
        int l,r,x;
        scanf("%d%d%d",&l,&r,&x);
        if (get_cnt(l,r,x)==r-l+1){
            cout<<-1<<"\n";
        }
        elif (a[r]!=x){
            cout<<r<<"\n";
        }
        else{
            int L=l,R=r;
            while (R-L>0){
                int m=(L+R)/2;
                if (get_cnt(m,r,x)==r-m+1){
                    R=m;
                }
                else{
                    L=m+1;
                }
            }
            cout<<L-1<<"\n";
        }
    }
}