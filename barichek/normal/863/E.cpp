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

bool bad[arr];

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
    vector<pii> a(n);
    for (auto& i:a){
        cin>>i.fir>>i.sec;
    }
    set<int> open;
    open.clear();
    vector<pair<pii,int>> events(0);
    for (int i=0;i<len(a);i++){
        events.pb(mp(mp(a[i].fir,+1),i));
        events.pb(mp(mp(a[i].sec+1,-1),i));
    }
    sort(all(events));
//    cout<<"events :: ";
//    for (int j=0;j<len(events);j++){
//        cout<<"J :: "<<events[j].fir.fir<<" "<<events[j].fir.sec<<" "<<events[j].sec<<"\n";
//    }
    for (int i=0;i<len(events);){
        int j=i; /// [i;j)
        while (j<len(events)&&events[j].fir.fir==events[i].fir.fir){
//            cout<<"J :: "<<events[j].fir.fir<<" "<<events[j].fir.sec<<" "<<events[j].sec<<"\n";
            if (events[j].fir.sec==+1){
//                cout<<"insert :: "<<events[j].sec<<"\n";
                open.insert(events[j].sec);
            }
            else{
//                cout<<"insert :: "<<events[j].sec<<"\n";
                open.erase(events[j].sec);
            }
            j++;
        }
//        cout<<"i :: "<<i<<" :: ";
//        cout<<events[i].fir.fir<<"\n";
//        cout<<"open :: ";
//        for (auto k:open){
//            cout<<k<<" ";
//        }
//        cout<<"\n";
        if (len(open)==1){
            bad[*open.begin()+1]=1;
        }
        i=j;
    }
    for (int i=1;i<=n;i++){
        if (!bad[i]){
            return cout<<i<<"\n", 0;
        }
    }
    cout<<-1<<"\n";
}