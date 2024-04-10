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

    void del(int pos)
    {
        int lol=get(pos,pos);
        upd(pos,-lol);
    }
};

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n,k;
    cin>>n>>k;
    fenwick_tree cnt(arr);
    fenwick_tree sum(arr);
    int min_val=1e9;
    int max_val=-1e9;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        cnt.upd(a,+1);
        sum.upd(a,a);
        min_val=min(min_val,a);
        max_val=max(max_val,a);
    }
    int cur=max_val;
    int ans=0;
    while (cnt.get(min_val+1,arr-1)>0){
        ans++;

        #define lol(aa) (sum.get(aa,arr-1)-cnt.get(aa,arr-1)*(aa)<=k)

        int kek=cur;
        while (lol(cur-1)&&cur-1>=min_val){
//            cout<<"before :: "<<sum.get(cur,arr-1)-cnt.get(cur,arr-1)*cur<<" !!\n";
            cur--;
//            cout<<"after :: "<<sum.get(cur,arr-1)-cnt.get(cur,arr-1)*cur<<" !!\n";
        }

//        cout<<sum.get(cur,arr-1)-cnt.get(cur,arr-1)*cur<<" !!\n";

        /// [cur+1;kek]
//        cout<<"cur kek :: "<<cur<<" "<<kek<<"\n";
        int cur_cnt=cnt.get(cur+1,kek);
        for (int i=cur+1;i<=kek;i++){
            cnt.del(i);
            sum.del(i);
        }
        cnt.upd(cur,cur_cnt);
        sum.upd(cur,cur_cnt*cur);
    }
    cout<<ans<<"\n";
}