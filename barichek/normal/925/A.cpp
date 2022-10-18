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

int dist(int x1,int y1,int x2,int y2)
{
    return abs(x1-x2)+abs(y1-y2);
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

    fast;

    int n,m,cl,ce,v;
    cin>>n>>m>>cl>>ce>>v;
    vi pos_l(cl);
    for (auto& i:pos_l){
        cin>>i;
    }
    vi pos_e(ce);
    for (auto& i:pos_e){
        cin>>i;
    }
    sort(all(pos_l));
    sort(all(pos_e));
    int q;
    cin>>q;
    while (q--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        if (x1==x2){
            cout<<abs(y1-y2)<<"\n";
            continue;
        }
        int ans=1e18;
        /// if from l
        auto it=lower_bound(all(pos_l),y1);
        if (it!=pos_l.begin()){
            auto it1=it;
            it1--;
            int cur=0;
            cur+=abs(*it1-y1);
            cur+=dist(x1,*it1,x2,y2);
            ans=min(ans,cur);
        }
        if (it!=pos_l.end()){
            auto it1=it;
            int cur=0;
            cur+=abs(*it1-y1);
            cur+=dist(x1,*it1,x2,y2);
            ans=min(ans,cur);
        }
        /// if from e
        auto IT=lower_bound(all(pos_e),y1);
        if (IT!=pos_e.begin()){
            auto it1=IT;
            it1--;
            int cur=0;
            cur+=abs(*it1-y1);
///            cur+=dist(x1,*it1,x2,y2);
            cur+=up(abs(x1-x2),v);
            cur+=abs(*it1-y2);
            ans=min(ans,cur);
        }
        if (IT!=pos_e.end()){
            auto it1=IT;
            int cur=0;
            cur+=abs(*it1-y1);
///            cur+=dist(x1,*it1,x2,y2);
            cur+=up(abs(x1-x2),v);
            cur+=abs(*it1-y2);
            ans=min(ans,cur);
        }
        cout<<ans<<"\n";
    }
}