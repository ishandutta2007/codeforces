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

struct node
{
    int sum;
    int da;
    int m2db;
    int da_m2db;
    int m2db_dc;
    int da_m2db_dc;

    node()
    {
        sum=0;
        da=0;
        m2db=0;
        da_m2db=0;
        m2db_dc=0;
        da_m2db_dc=0;
    }

    node(int value)
    {
        sum=value;
        da=value;
        m2db=-2*value;
        da_m2db=-value;
        m2db_dc=-value;
        da_m2db_dc=0;
    }
};

ostream& operator<<(ostream& os,node a)
{
    return os<<"{"<<a.sum<<","<<a.da<<","<<a.m2db<<","<<a.da_m2db<<","
            <<a.m2db_dc<<","<<a.da_m2db_dc<<"}";
}

node merge(node L,node R)
{
    node res;
    res.sum=L.sum+R.sum;
    res.da=max({L.da,L.sum+R.da});
    res.m2db=max({L.m2db,-2*L.sum+R.m2db});
    res.da_m2db=max({L.da_m2db,-L.sum+R.da_m2db,L.da+(-2*L.sum+R.m2db)});
    res.m2db_dc=max({L.m2db_dc,-L.sum+R.m2db_dc,L.m2db+(L.sum+R.da)});
    res.da_m2db_dc=max({L.da_m2db_dc,R.da_m2db_dc,
                       L.da+(-L.sum+R.m2db_dc),
                       L.da_m2db+(L.sum+R.da),
                       });
    return res;
}

node t[4*arr];

void upd(int v,int l,int r,int pos,int val)
{
    if (l==r){
        t[v]=node(val);
//        cout<<v<<" || "<<l<<" "<<r<<" :: "<<t[v]<<"\n";
        return;
    }
    int m=(l+r)/2;
    if (pos<=m){
        upd(v*2,l,m,pos,val);
    }
    else{
        upd(v*2+1,m+1,r,pos,val);
    }
    t[v]=merge(t[v*2],t[v*2+1]);
//    cout<<v<<" || "<<l<<" "<<r<<" :: "<<t[v]<<"\n";
}

main()
{
    #ifdef Barik
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    int q;
    cin>>q>>q;
    string s;
    cin>>s;
    s="#"+s;

    function<void(int,int)> call=[&](int pos,int val)
    {
//        cout<<"call :: "<<pos<<" "<<val<<"\n";
        upd(1,0,len(s)-1,pos,val);
    };

    auto upd=[&](int pos)
    {
        if (s[pos]=='('){
            call(pos,+1);
        }
        if (s[pos]==')'){
            call(pos,-1);
        }
    };

    for (int i=0;i<len(s);i++){
        upd(i);
    }

    function<void(int,int,int)> dfs=[&](int v,int l,int r)
    {
        cout<<v<<" :| "<<l<<" "<<r<<" :: "<<t[v]<<"\n";
        if (l==r){
            return;
        }
        int m=(l+r)/2;
        dfs(v*2,l,m);
        dfs(v*2+1,m+1,r);
    };

//    dfs(1,0,len(s)-1);

    cout<<t[1].da_m2db_dc<<"\n";

    while (q--){

        int p1,p2;
        cin>>p1>>p2;

        swap(s[p1],s[p2]);
        upd(p1);
        upd(p2);

        cout<<t[1].da_m2db_dc<<"\n";
    }
}