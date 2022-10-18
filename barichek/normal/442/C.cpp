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

#define arr (int)(5e5+10)

int a[arr];

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
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    set<int> oryshych;
    oryshych.clear();
    for (int i=0;i<n;i++){
        oryshych.insert(i);
    }
    vector<pii> to_sort(0);
    for (int i=0;i<n;i++){
        to_sort.pb(mp(a[i],i));
    }
    sort(all(to_sort));
    if (!to_sort.empty()){
        to_sort.pop_back();
    }
    if (!to_sort.empty()){
        to_sort.pop_back();
    }
    int ans=0;
    for (auto i:to_sort){
        int pos=i.sec;
        auto it=oryshych.find(pos);
        if (it==oryshych.begin()){
            ans+=a[*it];
            oryshych.erase(it);
            continue;
        }
        auto it1=it;
        it1--;
        auto it2=it;
        it2++;
        if (it2==oryshych.end()){
            ans+=a[*it];
            oryshych.erase(it);
            continue;
        }
        ans+=min(a[*it1],a[*it2]);
        oryshych.erase(it);
    }
    cout<<ans<<"\n";
}