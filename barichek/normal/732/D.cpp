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
const ld eps=1e-10;

///---program start---///

#define int ll

vi vec[arr];
vi all_[arr];
int a[arr];
vi ex;
vector<pii> time_;
int n,m;

bool bs(int x)
{
    //cerr<<"the most "<<x<<" !!\n";
    ex.assign(m+1,0);
    for (int i=1;i<=m;i++)
    {
        if (all_[i].empty()) exit(!(cout<<-1));
        auto it=upper_bound(all(all_[i]),x);
        if (it==all_[i].begin()) return false;
        it--;
        ex[i]=*it;
        //cerr<<i<<" "<<*it<<" !!!\n";
    }
    time_.clear();
    for (int i=1;i<=m;i++)
        if (ex[i]==0) return false;
        else time_.pb(mp(ex[i],a[i]));
    sort(all(time_));
    int ukaz=0;
    int cnt=0;
    for (int i=1;i<=n;i++)
    {
        int want=0;
        bool ok=false;
        while (ukaz<time_.size()&&time_[ukaz].fir==i)
            want+=time_[ukaz++].sec,
            ok=true;
        cnt-=want;
        //cerr<<" +++ :: "<<i<<" "<<cnt<<" "<<ukaz<<" !\n";
        if (cnt<0) return false;
        if (!ok) cnt++;
    }
    return true;
}

main()
{
    fast;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        int now;
        cin>>now;
        all_[now].pb(i);
    }
    for (int i=1;i<=m;i++)
        cin>>a[i];
    //cerr<<"!";
    int l=1, r=n;
    //cerr<<l<<" "<<r<<" !\n";
    while (r-l>1)
    {
        //cerr<<l<<" "<<r<<" !\n";
        if (bs((l+r)/2)) r=(l+r)/2;
        else l=(l+r)/2;
    }
    if (bs(l)) cout<<l;
    elif (bs(r)) cout<<r;
    else cout<<-1;
}