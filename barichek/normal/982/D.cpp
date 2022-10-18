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

    fast;

    int n;
    cin>>n;
    set<pii> kek;
    kek.clear();
    for (int i=1;i<=n;i++){
        int a;
        cin>>a;
        kek.insert({a,i});
    }
    set<pii> seg;
    seg.clear();
    multiset<int> len_seg;
    len_seg.clear();

    pii ans={-1e9,-1};

    for (auto i:kek){
//        cout<<"kek :: "<<i.fir<<" "<<i.sec<<"\n";
        int id=i.sec;
        seg.insert(mp(id,id));
        len_seg.insert(1);
        auto it=seg.find(mp(id,id));
        if (it!=seg.begin()&&prev(it)->sec==id-1){
            int L=prev(it)->fir;
            int R=it->sec;

            len_seg.erase(len_seg.find((prev(it)->sec)-(prev(it)->fir)+1));
            len_seg.erase(len_seg.find((it->sec)-(it->fir)+1));
            seg.erase(prev(it));
            seg.erase(it);

            len_seg.insert(R-L+1);
            seg.insert(mp(L,R));

            it=seg.find(mp(L,R));
        }
        if (next(it)!=seg.end()&&next(it)->fir==id+1){
            int L=it->fir;
            int R=next(it)->sec;

            len_seg.erase(len_seg.find((next(it)->sec)-(next(it)->fir)+1));
            len_seg.erase(len_seg.find((it->sec)-(it->fir)+1));
            seg.erase(next(it));
            seg.erase(it);

            len_seg.insert(R-L+1);
            seg.insert(mp(L,R));

            it=seg.find(mp(L,R));
        }

        if ((*(len_seg.begin()))==(*(--len_seg.end()))){
            ans=max(ans,{len(len_seg),-(i.fir+1)});
        }
    }

    cout<<-ans.sec<<"\n";
}