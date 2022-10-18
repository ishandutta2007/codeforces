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

string a[arr];
int cnt1[arr];
int cnt2[arr];

bool cmp(int id1,int id2)
{
    return cnt1[id1]*cnt2[id2]>cnt1[id2]*cnt2[id1];
}

int get(string s)
{
    int res=0;
    int cnt=0;
    for (auto i:s){
        if (i=='s'){
            cnt++;
        }
        else{
            res+=cnt;
        }
    }
    return res;
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        for (auto j:a[i]){
            cnt1[i]+=(j=='s');
            cnt2[i]+=(j=='h');
        }
    }
    vi p(0);
    for (int i=1;i<=n;i++){
        p.pb(i);
    }
    sort(all(p),cmp);
    string res="";
    for (auto i:p){
        res+=a[i];
    }
    cout<<get(res)<<"\n";
}