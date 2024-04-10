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

    int n;
    cin>>n;
    bool can=1;
    int cnt_cant=0;
    int ans=0;
    deque<pii> q;
    q.push_back(mp(1e9,-1e9));
    int is_prev_gavno=-1;
    int last_our=1e9;
    for (int i=1;i<=n;i++){
//        cout<<"before :: "<<i<<" ::: ans :: "<<ans<<"\n";
        int type;
        cin>>type;
        if (is_prev_gavno!=-1&&type!=1){
            q.pop_back();
            ans++;
        }
        if (type==1){
            int x;
            cin>>x;
            last_our=x;
            if (is_prev_gavno!=-1){
                if (x>is_prev_gavno){
                    ans++;
                    q.pop_back();
                }
            }
            if (x>q.back().fir){
                while (x>q.back().fir){
                    ans++;
                    q.pop_back();
                }
            }
        }
        if (type==2){
            if (!can){
                can=1;
                ans+=cnt_cant;
                cnt_cant=0;
            }
        }
        if (type==3){
            int x;
            cin>>x;
//            cout<<"kek :: "<<last_our<<" "<<x<<"\n";
            if (x<last_our){
                ans++;
            }
            else{
                q.push_back(mp(x,i));
            }
        }
        if (type==4){
            can=1;
            cnt_cant=0;
        }
        if (type==5){
            while (q.size()>1){
                q.pop_back();
            }
        }
        if (type==6){
            can=0;
            cnt_cant++;
        }
    }
    cout<<ans<<"\n";
}