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

    fast;
    int n,q1,m;
    cin>>n>>q1>>m;
    vi a(n+1);
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<pair<int,pii>> q(q1);
    for (auto& i:q){
        cin>>i.fir>>i.sec.fir>>i.sec.sec;
    }
    reverse(all(q));
    while (m--){
        int pos;
        cin>>pos;
        for (auto i:q){
            int type=i.fir;
            int L=i.sec.fir;
            int R=i.sec.sec;
            if (L>pos||R<pos){
                continue;
            }
            if (type==1){
                if (pos==L){
                    pos=R;
                }
                else{
                    pos--;
                }
            }
            else{
                pos=L+(R-pos);
            }
        }
        cout<<a[pos]<<" ";
    }
    cout<<"\n";
}