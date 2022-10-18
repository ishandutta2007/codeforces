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

set<int> ans;
vector<pii> a;

int up(int a,int b)
{
    return a/b+(a%b>0);
}

bool check(int x)
{
    for (auto i:a){
        if (up(i.fir,x)!=i.sec){
            return 0;
        }
    }
    return 1;
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

    int n,m;
    cin>>n>>m;
    a.resize(m);
    for (auto& i:a){
        cin>>i.fir>>i.sec;
    }
    for (int i=1;i<200;i++){
        if (check(i)){
            ans.insert(i);
        }
    }
    set<int> ans1;
    ans1.clear();
    for (auto i:ans){
        ans1.insert(up(n,i));
    }
    cout<<(len(ans1)==1?*ans1.begin():-1)<<"\n";
}