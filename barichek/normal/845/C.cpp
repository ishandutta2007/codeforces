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
    vector<pii> vec(0);
    int n;
    cin>>n;
    while (n--){
        int l,r;
        cin>>l>>r;
        vec.pb(mp(l,-1));
        vec.pb(mp(r,+1));
    }
    sort(all(vec));
    int cur=0;
    for (int i=0;i<len(vec);){
        int cur_point=vec[i].fir;
        int j=i;
        cur+=vec[i].sec;
        if (cur<-2){
            return cout<<"NO"<<"\n", 0;
        }
        while (j+1<len(vec)&&vec[j+1].fir==cur_point){
            j++;
            cur+=vec[j].sec;
            if (cur<-2){
                return cout<<"NO"<<"\n", 0;
            }
        }
        i=j+1;
    }
    cout<<"YES"<<"\n";
}