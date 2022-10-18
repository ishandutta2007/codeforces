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

main()
{
    fast;
    int n,m,k;
    cin>>n>>m>>k;
    int x,s;
    cin>>x>>s;
    vi a;
    a.resize(m);
    for (auto &i:a)
        cin>>i;
    vi b;
    b.resize(m);
    for (auto &i:b)
        cin>>i;
    vi c;
    c.resize(k);
    for (auto &i:c)
        cin>>i;
    vi d;
    d.resize(k);
    for (auto &i:d)
        cin>>i;
    int ans=n*x;
    for (int i=0;i<m;i++)
    {
        if (b[i]<=s)
        {
            //cout<<ans<<" !!\n";
            int cur_ans=n*x;
            int res=upper_bound(all(d),s-b[i])-d.begin()-1;
            int shara=0;
            if (res>=0)
                shara=c[res];
            shara=min(shara,n);
            cur_ans-=shara*x;
            int elsik=n-shara;
            cur_ans-=elsik*(x-a[i]);
            ans=min(ans,cur_ans);
        }
    }
    for (int i=0;i<k;i++)
        if (d[i]<=s)
        {
            //cout<<ans<<" !!\n";
            int cur_ans=n*x;
            int shara=c[i];
            shara=min(shara,n);
            cur_ans-=shara*x;
            ans=min(ans,cur_ans);
        }
    cout<<ans;
}