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

#define arr (int)(3e5+10)

const int it=60;

int cnt[arr];
int ans[arr][it];
int val[arr][it];
int l[arr];
int r[arr];
int k[arr];
int want[arr];
vi events1[arr];
vector<char> events3[arr];
int a[arr];
int n,q;
int anss[arr];
map<pair<pii,int>,int> had;
int link[arr];

int rnd(int mx)

{
    int res=rand()^(rand()<<15);
    return res%mx;
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

    srand(time(0));

    scanf("%d",&n);
    scanf("%d",&q);
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for (int i=1;i<=q;i++){
        scanf("%d%d%d",&l[i],&r[i],&k[i]);
        if (had[mp(mp(l[i],r[i]),k[i])]){
            link[i]=had[mp(mp(l[i],r[i]),k[i])];
            continue;
        }
        else{
            had[mp(mp(l[i],r[i]),k[i])]=i;
        }
        int len=r[i]-l[i]+1;
        want[i]=len/k[i];
        for (int j=0;j<it;j++){
            val[i][j]=a[l[i]+rnd(len+1)];
            events1[l[i]-1].pb(-i);
            events3[l[i]-1].pb(j);
            events1[r[i]].pb(i);
            events3[r[i]].pb(j);
        }
    }
    for (int i=1;i<=n;i++){
        cnt[a[i]]++;
        for (int j=0;j<len(events1[i]);j++){
            if (events1[i][j]<0){
                ans[-events1[i][j]][events3[i][j]]-=cnt[val[-events1[i][j]][events3[i][j]]];
            }
            else{
                ans[events1[i][j]][events3[i][j]]+=cnt[val[events1[i][j]][events3[i][j]]];
            }
        }
    }
    for (int i=1;i<=q;i++){
        if (link[i]){
            cout<<anss[link[i]]<<"\n";
            continue;
        }
        int ans=1e9;
        for (int j=0;j<it;j++){
            if (::ans[i][j]>want[i]){
                if (ans==1e9||ans>val[i][j]){
                    ans=val[i][j];
                }
            }
        }
        cout<<(anss[i]=(ans==1e9?-1:ans))<<"\n";
    }
}