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

int ans[arr];

int le(int l,int r)
{
    return r-l+1;
}

void set_ans(int L,int R,int bit)
{
    for (int i=L;i<=R;i++){
        ans[i]|=(1ll<<bit);
    }
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #else
        files("");
        files_ds("");
    #endif

    int n,x;
    cin>>n>>x;
    vector<pii> q(0);
    q.pb(mp(1,n));
    for (int i=0;i<18;i++){
//        cout<<"q ::: "<<"\n";
//        for (auto j:q){
//            cout<<j.fir<<" "<<j.sec<<"\n";
//        }
        int cur=0;
        vi d(len(q));
        for (int j=0;j<len(q);j++){
            d[j]=le(q[j].fir,q[j].sec)/2;
            cur+=d[j];
        }
        bool ok=0;
        if (cur%2!=((x&(1ll<<i))>0)){
            ok=1;
        }
        bool is_any_1=0;
        for (auto j:q){
            is_any_1|=((le(j.fir,j.sec)&1)==1);
        }
        vector<pii> new_q(0);
        for (auto j:q){
            if (!(ok&&(is_any_1?le(j.fir,j.sec)%2==1:1))){
                /// divide easy
                int L=j.fir;
                int R=j.sec;
                int m=L+le(L,R)/2;
//                cout<<"divide easy :: "<<L<<" "<<R<<" :: m :: "<<m<<"\n";
                if (L<=m-1){
                    new_q.pb(mp(L,m-1));
                    set_ans(L,m-1,i);
                }
                if (m<=R){
                    new_q.pb(mp(m,R));
                }
            }
            else{
                /// divide hard
                int L=j.fir;
                int R=j.sec;
                int m=L+le(L,R)/2+1; /// +1 !!!!!!!!!!!!! harrrrrd
//                cout<<"divide hard :: "<<L<<" "<<R<<" :: m :: "<<m<<"\n";
                if (L<=m-1){
                    new_q.pb(mp(L,m-1));
                    set_ans(L,m-1,i);
                }
                if (m<=R){
                    new_q.pb(mp(m,R));
                }

                ok=0;
            }
        }
        q=new_q;
    }
    int xorik=0;
    for (int i=1;i<=n;i++){
        xorik^=ans[i];
    }
//    cout<<"xorik :: "<<xorik<<"\n";
    if (xorik!=x){
//        assert(0);
        return cout<<"NO"<<"\n", 0;
    }
    set<int> setik;
    for (int i=1;i<=n;i++){
        setik.insert(ans[i]);
    }
    if (len(setik)!=n){
//        assert(0);
        return cout<<"NO"<<"\n", 0;
    }
    if (*setik.rbegin()>1e6){
//        assert(0);
        return cout<<"NO"<<"\n", 0;
    }
    cout<<"YES"<<"\n";
    for (int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
//    cout<<*max_element(ans+1,ans+n+1)<<"\n";
}