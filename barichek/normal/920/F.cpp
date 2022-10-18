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

#define arr (int)(1e6+10)

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

int a[arr];
int d[arr];
int dil[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    for (int i=2;i<arr;i++){
        if (!dil[i]){
            dil[i]=i;
            for (int j=2*i;j<arr;j+=i){
                if (!dil[j]){
                    dil[j]=i;
                }
            }
        }
    }

    for (int i=1;i<arr;i++){
        int cur=i;
        d[i]=1;
        while (cur!=1){
            int cur_dil=dil[cur];
            int s=0;
            while (cur%cur_dil==0){
                cur/=cur_dil;
                s++;
            }
            d[i]*=s+1;
        }
    }

    fast;

    int n,m;
    cin>>n>>m;

    fenwick_tree f(n);

    set<int> kek;
    kek.clear();

    for (int i=1;i<=n;i++){
        cin>>a[i];
        f.upd(i,a[i]);
        if (d[a[i]]!=a[i]){
            kek.insert(i);
        }
    }

    for (int i=0;i<m;i++){
        int type,l,r;
        cin>>type>>l>>r;
        if (type==1){
            vi to_del(0);
            auto it=kek.lower_bound(l);
            while (it!=kek.end()&&*it<=r){
                f.upd(*it,-a[*it]);
                a[*it]=d[a[*it]];
                f.upd(*it,+a[*it]);

                if (a[*it]==d[a[*it]]){
                    to_del.pb(*it);
                }

                it++;
            }
            for (auto i:to_del){
                kek.erase(i);
            }
        }
        else{
            cout<<f.get(l,r)<<"\n";
        }
    }
}