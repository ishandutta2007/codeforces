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

map<int,set<int>> kek;

int res[arr];

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
        int a;
        cin>>a;
        kek[a].insert(i);
    }
    for (auto it=kek.begin();it!=kek.end();it++){
//        cout<<"keeek :: "<<it->fir<<"\n";
        while (len(it->sec)>=2){
            int pos1=*(it->sec).begin();
            (it->sec).erase((it->sec).begin());
            int pos2=*(it->sec).begin();
            (it->sec).erase((it->sec).begin());
            kek[2*(it->fir)].insert(pos2);
        }
    }
    for (auto i:kek){
        for (auto j:i.sec){
            res[j]=i.fir;
        }
    }
    vi ans(0);
    for (int i=0;i<n;i++){
        if (res[i]){
            ans.pb(res[i]);
        }
    }
    cout<<len(ans)<<"\n";
    for (auto i:ans){
        cout<<i<<" ";
    }
    cout<<"\n";
}