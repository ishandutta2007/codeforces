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

const int maxint=numeric_limits<int>::max();
const ll maxll=numeric_limits<ll>::max();
const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ll md=1e9+7;
const ld eps=1e-6;

///---program start---///

map<int,int> last;
int n,m,st[4000000];

void __st(int x,int d,int v,int l,int r)
{
    if (l>x||r<x) return;
    if (l==r)
    {
        st[v]=d;
        return;
    }
    __st(x,d,v*2,l,(l+r)/2);
    __st(x,d,v*2+1,(l+r)/2+1,r);
    st[v]=st[v*2]^st[v*2+1];
}

int _st(int tl,int tr,int v,int l,int r)
{
    if (l>tr||r<tl) return 0;
    if (l>=tl&&r<=tr) return st[v];
    return _st(tl,tr,v*2,l,(l+r)/2)^_st(tl,tr,v*2+1,(l+r)/2+1,r);
}

bool cmp(pair<pii,int>& a,pair<pii,int>& b)
{
    return a.fir.sec<b.fir.sec||(a.fir.sec==b.fir.sec&&a.fir.fir<b.fir.fir);
}

int main()
{
    cin>>n;
    vi vec;
    vec.resize(n+1);
    vi pref;
    pref.resize(n+1);
    pref[0]=0;
    for (int i=1;i<=n;i++)
        scanf("%d",&vec[i]),
        last[vec[i]]=-1,
        pref[i]=i>1?pref[i-1]^vec[i]:vec[i];
    vector< pair<pii,int> > zap;
    cin>>m;
    zap.resize(m);
    for (int i=0;i<m;i++)
        scanf("%d%d",&zap[i].fir.fir,&zap[i].fir.sec),
        zap[i].sec=i;
    sort(all(zap),cmp);
    int cur=0;
    vi all_res;
    all_res.resize(m);
    for (int i=1;i<=n;i++)
    {
        __st(i,vec[i],1,1,n);
        if (last[vec[i]]!=-1) __st(last[vec[i]],0,1,1,n);
        last[vec[i]]=i;
        while (cur<m&&zap[cur].fir.sec==i)
            all_res[zap[cur].sec]=_st(zap[cur].fir.fir,zap[cur].fir.sec,1,1,n)^
                pref[zap[cur].fir.sec]^pref[zap[cur++].fir.fir-1];
    }
    for (auto i:all_res)
        cout<<i<<"\n";
}