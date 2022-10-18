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

string s,t;
map<int,int> cnt_s;
map<int,int> cnt_t;
string ans;

bool check(int x)
{
    int cnt_want=0;
    for (auto i:cnt_t){
        cnt_want+=max(0ll,x*i.sec-cnt_s[i.fir]);
    }
    return cnt_want<=cnt_s['?'];
}

void b_check(int x)
{
    int pos=0;
    int cnt_want=0;
    for (auto i:cnt_t){
        for (int j=0;j<x*i.sec-cnt_s[i.fir];j++){
            while (ans[pos]!='?'){
                pos++;
            }
            ans[pos]=i.fir;
        }
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

    cin>>s>>t;
    ans=s;
    for (auto i:s){
        cnt_s[i]++;
    }
    for (auto i:t){
        cnt_t[i]++;
    }
    int l=0,r=1e6;
    while (r-l>1){
        int m=(l+r)/2;
        if (check(m)){
            l=m;
        }
        else{
            r=m;
        }
    }
    int res=l;
    if (check(r)){
        res=r;
    }
    b_check(res);
    for (auto& i:ans){
        if (i=='?'){
            i='h';
        }
    }
    cout<<ans<<"\n";
}