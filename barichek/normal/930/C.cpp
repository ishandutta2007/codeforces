#pragma GCC optimize("O3")
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
    vi f;

    fenwick_tree() {}
    fenwick_tree(int n)
    {
        this->n=n;
        f.assign(n,0);
    }

    void upd(int pos,int val)
    {
        for (int i=pos;i<n;i|=i+1){
            f[i]=max(f[i],val);
        }
    }
    int get(int pos)
    {
        int res=0;
        for (int i=pos;i>=0;i&=i+1,i--){
            res=max(res,f[i]);
        }
        return res;
    }
};

int cnt[arr];

#define left left_____
#define right right_____

int left[arr];
int right[arr];

main()
{
    #ifdef I_love_Maria_Ivanova
        files("barik");
        freopen("debug.txt","w",stderr);
    #endif

    fast;

    int n,m;
    cin>>n>>m;
    while (n--){
        int l,r;
        cin>>l>>r;
        cnt[l]++;
        cnt[r+1]--;
    }
    for (int i=1;i<=m;i++){
        cnt[i]+=cnt[i-1];
    }
    fenwick_tree f1(arr);
    for (int i=1;i<=m;i++){
        left[i]=1+f1.get(cnt[i]);
        f1.upd(cnt[i],left[i]);
    }
    fenwick_tree f2(arr);
    for (int i=m;i>=1;i--){
        right[i]=1+f2.get(cnt[i]);
        f2.upd(cnt[i],right[i]);
    }
    int ans=0;
    for (int i=1;i<=m;i++){
        ans=max(ans,left[i]+right[i]-1);
    }
    cout<<ans<<"\n";
}