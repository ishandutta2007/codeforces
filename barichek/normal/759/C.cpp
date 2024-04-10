#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define all(a) a.begin(),a.end()
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

const int maxint=numeric_limits<int>::max();
const ll maxll=numeric_limits<ll>::max();
const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;

///---program start---///

struct segment_tree
{
    vector<pii> a;
    vi push;
    int size;

    void build(int v,int l,int r)
    {
        if (l==r) return void(a[v]=mp(1e9,l));
        int m=(l+r)/2;
        build(v*2,l,m);
        build(v*2+1,m+1,r);
        a[v]=mp(1e9,l);
    }
    void build()
    {
        int l=1,r=size;
        build(1,l,r);
    }

    segment_tree() {}
    segment_tree(int n)
    {
        size=n;
        push.assign(4*(n+1),0);
        a.resize(4*(n+1));
        build();
    }

    void make_push(int v,int l,int r)
    {
        a[v*2].fir+=push[v];
        a[v*2+1].fir+=push[v];
        push[v*2]+=push[v];
        push[v*2+1]+=push[v];
        push[v]=0;
    }
    void upd(int v,int l,int r,int tl,int tr,int val)
    {
        if (l>r) return;
        if (tl>tr) return;
        if (l>tr||r<tl) return;
        if (l>=tl&&r<=tr)
        {
            a[v].fir+=val;
            push[v]+=val;
            return;
        }
        make_push(v,l,r);
        int m=(l+r)/2;
        upd(v*2,l,m,tl,tr,val);
        upd(v*2+1,m+1,r,tl,tr,val);
        if (a[v*2].fir<a[v*2+1].fir)
            a[v]=a[v*2];
        else
            a[v]=a[v*2+1];
    }
    void upd(int x,int val)
    {
        upd(1,1,size,x,x,val);
    }
    void upd_pref(int x,int val)
    {
        int l=1,r=x;
        upd(1,1,size,l,r,val);
    }
    int lol_kek_cheburek(int v,int l,int r)
    {
        if (l>r) return 0;
        if (a[v].fir>0) return 0;
        if (l==r)
            return a[v].sec;
        make_push(v,l,r);
        int m=(l+r)/2;
        if (a[v*2+1].fir<=0)
            return lol_kek_cheburek(v*2+1,m+1,r);
        else
            return lol_kek_cheburek(v*2,l,m);
    }
    int lol_kek_cheburek()
    {
        return lol_kek_cheburek(1,1,size);
    }
};

int a[arr];

main()
{
    a[0]=-1; /// lol_kek_cheburek
    fast;
    int m;
    cin>>m;
    segment_tree st=*new segment_tree(m);
    while (m--)
    {
        #define time time_______
        int time,type;
        cin>>time>>type;
        if (type==0)
            st.upd_pref(time-1,+1),
            cout<<a[st.lol_kek_cheburek()]<<"\n";
        else
        {
            int x;
            cin>>x;
            a[time]=x;
            st.upd(time,-1e9);
            st.upd_pref(time-1,-1);
            cout<<a[st.lol_kek_cheburek()]<<"\n";
        }
    }
}