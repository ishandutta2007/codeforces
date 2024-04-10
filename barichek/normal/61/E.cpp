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

typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const ll maxll=numeric_limits<ll>::max();
const int maxint=numeric_limits<int>::max();
const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ll md=1e9+7;
const ld eps=1e-6;

///---program start---///

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<typename type>
    using ordered_set=tree<type,null_type,less<type>,rb_tree_tag,tree_order_statistics_node_update>;

map<int,int> vh;
ull n,st[4*1000001];

void __st(int x,ll d,int v,int l,int r)
{
    if (l>x||r<x) return;
    if (l==r)
    {
        st[v]+=d;
        return;
    }
    __st(x,d,v*2,l,(l+r)/2);
    __st(x,d,v*2+1,(l+r)/2+1,r);
    st[v]=st[v*2]+st[v*2+1];
}

ll _st(int tl,int tr,int v,int l,int r)
{
    //cout<<v<<" "<<l<<" "<<r<<"\n";
    if (tl>tr) return 0;
    if (l>tr||r<tl) return 0;
    if (l>=tl&&r<=tr) return st[v];
    return _st(tl,tr,v*2,l,(l+r)/2)+_st(tl,tr,v*2+1,(l+r)/2+1,r);
}

int main()
{
    ordered_set<ll> setik;
    cin>>n;
    vi rem;
    vi all_rem;
    for (int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        rem.pb(a);
        all_rem.pb(a);
    }
    sort(all(rem));
    for (int i=0;i<n;i++)
        vh[rem[i]]=i;
    vi rem_ans(n,0);
    for (int i=0;i<n;i++)
    {
        rem_ans[i]=i-setik.order_of_key(all_rem[i]);
        //cout<<"update== "<<vh[all_rem[i]]<<" "<<i-setik.order_of_key(all_rem[i])<<"\n";
        //__st(vh[all_rem[i]],i-setik.order_of_key(all_rem[i]),1,1,n);
        setik.insert(all_rem[i]);
    }
    ull ans=0;
    for (int i=0;i<n;i++)
    {
        ans=ans+_st(vh[all_rem[i]]+1,1000001,1,1,1000001);
        //cout<<"ans=="<<ans<<"\n";
        //cout<<"update == "<<vh[all_rem[i]]<<" "<<rem_ans[i]<<"\n";
        __st(vh[all_rem[i]],rem_ans[i],1,1,1000001);
    }
    cout<<ans;
}