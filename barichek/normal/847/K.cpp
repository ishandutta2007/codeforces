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

#define ar (int)(1000+10)

vector<pair<string,string>> a;

map<string,int> vh;

int cnt[ar][ar];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #else
        files("");
        files_ds("");
    #endif

    int n,a,b,k,f;
    cin>>n>>a>>b>>k>>f;
    ::a.resize(n);
    for (auto& i:(::a)){
        cin>>i.fir>>i.sec;
        vh[i.fir];
        vh[i.sec];
    }

    int kek=0;
    for (auto& i:vh){
        i.sec=++kek;
    }

    for (int i=0;i<len(::a);i++){
        if (i==0){
            cnt[vh[::a[i].fir]][vh[::a[i].sec]]+=a;
        }
        elif (::a[i].fir==::a[i-1].sec){
            cnt[vh[::a[i].fir]][vh[::a[i].sec]]+=b;
        }
        else{
            cnt[vh[::a[i].fir]][vh[::a[i].sec]]+=a;
        }
    }
    vector<int> all1(0);
    for (int i=1;i<=kek;i++){
        for (int j=i+1;j<=kek;j++){
            if (cnt[i][j]+cnt[j][i]){
                all1.pb(cnt[i][j]+cnt[j][i]);
            }
        }
    }
    sort(all(all1),greater<int>());
    int ans=0;
    for (auto i:all1){
        ans+=i;
    }
    for (auto i:all1){
        if (k&&i>f){
            k--;
            ans-=i;
            ans+=f;
        }
    }
    cout<<ans<<"\n";
}