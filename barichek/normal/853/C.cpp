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

int f[arr];

void upd(int pos,int val)
{
    for (int i=pos;i<arr;i|=i+1){
        f[i]+=val;
    }
}

int get(int pos)
{
    int res=0;
    for (int i=pos;i>=0;i&=(i+1),i--){
        res+=f[i];
    }
    return res;
}

int get(int l,int r)
{
    return get(r)-get(l-1);
}

vector<pair<pii,int>> in[arr];
vector<pair<pii,int>> out[arr];

void add(int x1,int y1,int x2,int y2,int num)
{
    in[x1].pb(mp(mp(y1,y2),num));
    out[x2].pb(mp(mp(y1,y2),num));
}

int ans1[20*arr];
int kek[arr];
int n,q;

void big_do()
{
    for (int i=0;i<=n+1;i++){
        for (auto j:in[i]){
            ans1[j.sec]-=get(j.fir.fir,j.fir.sec);
        }
        if (1<=i&&i<=n){
            upd(kek[i],+1);
//            cout<<"upd :: "<<kek[i]<<"\n";
        }
        for (auto j:out[i]){
            ans1[j.sec]+=get(j.fir.fir,j.fir.sec);
        }
    }
}

vi ans[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #else
        files("");
        files_ds("");
    #endif

    cin>>n>>q;
    for (int i=1;i<=n;i++){
        scanf("%d",&kek[i]);
    }
    int last=0;
    for (int i=1;i<=q;i++){
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

        /// 1
        add(1,1,x1-1,y1-1,last);
        ans[i].pb(last);
        last++;
        add(x1,y1,n,n,last);
        ans[i].pb(last);
        last++;

        /// 2
        add(1,y1,x1-1,y2,last);
        ans[i].pb(last);
        last++;
        add(x1,1,n,n,last);
        ans[i].pb(last);
        last++;

        /// 3
        add(1,y2+1,x1-1,n,last);
        ans[i].pb(last);
        last++;
        add(x1,1,n,y2,last);
        ans[i].pb(last);
        last++;

        /// 4
        add(x1,y2+1,x2,n,last);
        ans[i].pb(last);
        last++;
        add(1,1,n,y2,last);
        ans[i].pb(last);
        last++;

        /// 5
        add(x2+1,y2+1,n,n,last);
        ans[i].pb(last);
        last++;
        add(1,1,x2,y2,last);
        ans[i].pb(last);
        last++;

        /// 6
        add(x2+1,y1,n,y2,last);
        ans[i].pb(last);
        last++;
        add(1,1,x2,n,last);
        ans[i].pb(last);
        last++;

        /// 7
        add(x2+1,1,n,y1-1,last);
        ans[i].pb(last);
        last++;
        add(1,y1,x2,n,last);
        ans[i].pb(last);
        last++;

        /// 8
        add(x1,1,x2,y1-1,last);
        ans[i].pb(last);
        last++;
        add(1,y1,n,n,last);
        ans[i].pb(last);
        last++;

        /// 9
        add(x1,y1,x2,y2,last);
        ans[i].pb(last);
        last++;
    }

    big_do();

    for (int i=1;i<=q;i++){
//        cout<<"ans :: "<<i<<" ::: ";
//        for (auto j:ans[i]){
//            cout<<ans1[j]<<" ";
//        }
//        cout<<"\n";

        ll res=0;
        for (int j=0;j<16;j+=2){
            res+=1ll*ans1[ans[i][j]]*ans1[ans[i][j+1]];
        }
        ll lol=ans1[ans[i][16]];
        res+=lol*(lol-1);
        res+=lol*(n-lol);
        res/=2;
        cout<<res<<"\n";
    }
}