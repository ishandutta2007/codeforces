#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
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

struct fenwick_tree
{
    int n;
    vi t;

    fenwick_tree()
    {
        n=0;
        t.clear();
    }
    fenwick_tree(int n)
    {
        n++;
        this->n=n;
        t.assign(n,0);
    }

    void upd(int pos,int val)
    {
        for (int i=pos;i<n;i|=i+1){
            t[i]+=val;
        }
    }
    int get(int pos)
    {
        int res=0;
        for (int i=pos;i>=0;i&=i+1,i--){
            res+=t[i];
        }
        return res;
    }
    int get(int l,int r)
    {
        if (l>r){
            return 0;
        }
        return get(r)-get(l-1);
    }
};

#define arr (int)(3e5+10)

pii get(string s)
{
    pii res={1e9,0};
    for (auto i:s){
        if (i=='('){
            res.sec++;
            res.fir=min(res.fir,res.sec);
        }
        else{
            res.sec--;
            res.fir=min(res.fir,res.sec);
        }
    }
    return res;
}

int n;
pii b[arr];

int gett()
{
    vector<int> cnt(2*arr);
    int res=0;
    for (int i=0;i<n;i++){
        if (b[i].fir>=0){
            res+=cnt[b[i].sec];
        }
        if (b[i].sec<=0&&-b[i].sec+b[i].fir>=0){
            cnt[-b[i].sec]++;
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

    cin>>n;
    for (int i=0;i<n;i++){
        string s;
        cin>>s;
        b[i]=get(s);
    }
    int ans=0;
    ans+=gett();
    reverse(b,b+n);
    ans+=gett();
    for (int i=0;i<n;i++){
        if (b[i].sec==0&&b[i].fir>=0){
            ans++;
        }
    }
    cout<<ans<<"\n";
}