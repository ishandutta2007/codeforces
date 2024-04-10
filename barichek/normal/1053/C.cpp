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

int add(int& a,int b)
{
    a+=b;
    a%=md;
    if (a<0){
        a+=md;
    }
}

int sum(int a,int b)
{
    add(a,b);
    return a;
}

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
            add(t[i],val);
        }
    }
    int get(int pos)
    {
        int res=0;
        for (int i=pos;i>=0;i&=i+1,i--){
            add(res,t[i]);
        }
        return res;
    }
    int get(int l,int r)
    {
        if (l>r){
            return 0;
        }
        return sum(get(r),-get(l-1));
    }
};

struct fenwick_tree_special
{
    int n;
    vi t;

    fenwick_tree_special()
    {
        n=0;
        t.clear();
    }
    fenwick_tree_special(int n)
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

int a[arr];
int w[arr];

fenwick_tree_special f_w(arr);
fenwick_tree f_b(arr); /// b[i]=a[i]*w[i]

int get_ans(int l,int r,int k)
{
    int res=0;
    add(res,f_b.get(r));
    add(res,f_b.get(l-1));
    add(res,-a[k]*(f_w.get(r)%md)%md);
    add(res,-a[k]*(f_w.get(l-1)%md)%md);
    add(res,-2*f_b.get(k)%md);
    add(res,a[k]*2%md*(f_w.get(k)%md)%md);
    return res;
}

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n,q;
    cin>>n>>q;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        a[i]-=i;
    }
    for (int i=1;i<=n;i++){
        cin>>w[i];
    }
    for (int i=1;i<=n;i++){
        f_w.upd(i,w[i]);
        f_b.upd(i,w[i]*a[i]%md);
    }
    while (q--){
        int x,y;
        cin>>x>>y;
        if (x<0){
            x=-x;
            f_w.upd(x,y-w[x]);
            f_b.upd(x,((y-w[x])*a[x]%md+md)%md);
            w[x]=y;
        }
        else{
            int l=x;
            int r=y;
            int L=l,R=r;
            while (R-L>0){
                int m=(L+R+1)/2;
                if (2*f_w.get(l,m-1)<=f_w.get(l,r)){
                    L=m;
                }
                else{
                    R=m-1;
                }
            }
            int k=L;

//            cerr<<"for ["<<l<<";"<<r<<"] optimal k :: "<<k<<" :: "<<get_ans(l,r,k)<<"\n";
//            cerr<<"and now ..."<<"\n";
//            for (int i=l;i<=r;i++){
//                cerr<<"i :: "<<i<<" :: "<<get_ans(l,r,i)<<"\n";
//                cerr<<"and :: "<<f_w.get(l,i)<<" "<<f_w.get(i+1,r)<<"\n";
//            }
//            cerr<<"so ... "<<"\n";

            int ans=get_ans(l,r,k);

            cout<<ans<<"\n";
        }
    }
}