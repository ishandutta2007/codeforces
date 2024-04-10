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

#define int ll

int n,m,k;
ll want_plus[arr];
ll want_minus[arr];
int cnt_use[arr];
int cnt_in[arr];
int cnt_out[arr];
vector<ll> a;

vector< pair<pii,int> > zap;

main()
{
    cin>>n>>m>>k;
    a.resize(n);
    for (int i=0;i<n;i++)
        cin>>a[i];
    for (int i=0;i<m;i++)
    {
        int l,r,d;
        cin>>l>>r>>d;
        l--;
        r--;
        zap.pb(mp(mp(l,r),d));
    }
    while (k--)
    {
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        cnt_in[l]++;
        cnt_out[r]++;
    }
    int cur=0;
    for (int i=0;i<m;i++)
    {
        cur+=cnt_in[i];
        cnt_use[i]=cur;
        cur-=cnt_out[i];
    }
    for (int i=0;i<m;i++)
    {
        want_plus[zap[i].fir.fir]+=cnt_use[i]*zap[i].sec;
        want_minus[zap[i].fir.sec]+=cnt_use[i]*zap[i].sec;
    }
    ll cur_plus=0;
    for (int i=0;i<n;i++)
    {
        cur_plus+=want_plus[i];
        a[i]+=cur_plus;
        cur_plus-=want_minus[i];
    }
    for (auto i:a)
        cout<<i<<" ";
}