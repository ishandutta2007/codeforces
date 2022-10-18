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

vi vh[arr];
set<int> setik_lalka;
vi b;
int n;
int last_[arr];
vector<pii> last;
bool cur_use[arr];
int global_transfer;

bool check(int x)
{
    //cout<<"bool check(int "<<x<<")\n";
    int cnt=0;
    for (auto i:b)
        if (!vh[i].empty())
            cnt+=vh[i].end()-lower_bound(all(vh[i]),x);
    cnt=n-x-cnt;
    //cout<<"  cnt :: "<<cnt<<"\n";
    if (cnt==0) return true;
    int find_any=-1;
    for (auto i:last)
        if (i.fir<x)
            break;
        elif (!cur_use[i.sec])
        {
            find_any=i.sec;
            break;
        }
    //cout<<"  find_any :: "<<find_any<<"\n";
    global_transfer=find_any;
    return vh[find_any].end()-lower_bound(all(vh[find_any]),x)==cnt;
}

main()
{
    fast;
    cin>>n;
    vector<pii> a;
    a.clear();
    for (int i=0;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        last_[u]=max(last_[u],i+1);
        vh[u].pb(i);
        setik_lalka.insert(u);
        a.pb({u,v});
    }
    for (int i=1;i<=n;i++)
        if (last_[i])
        {
            last_[i]--;
            last.pb(mp(last_[i],i));
            last_[i]++;
        }
    sort(all(last),greater<pii>());
    //cout<<"last ::\n";
    //for (auto i:last)
      //  cout<<i.fir<<" "<<i.sec<<"\n";
    //cout<<"\n";
    int q;
    cin>>q;
    while (q--)
    {
        int cnt;
        cin>>cnt;
        b.clear();
        b.resize(cnt);
        for (auto &i:b)
            cin>>i;
        for (auto i:b)
            cur_use[i]=true;
        int cnt00=0;
        for (auto i:b)
            if (last_[i])
                cnt00++;
        if (cnt00==setik_lalka.size())
        {
            cout<<0<<" "<<0<<"\n";
            for (auto i:b)
                cur_use[i]=false;
            continue;
        }
        int l=0,r=n-1;
        while (r-l>1)
            if (!check((l+r)/2))
                l=(l+r)/2;
            else
                r=(l+r)/2;
        //cout<<"l && r :: "<<l<<" "<<r<<"\n";
        if (!check(l))
            l=r;
        //cout<<"anssss l ::"<<l<<" \n";
        //cout<<"global :: "<<global_transfer<<"\n";
        int res=*lower_bound(all(vh[global_transfer]),l);
        cout<<a[res].fir<<" "<<a[res].sec<<"\n";
        for (auto i:b)
            cur_use[i]=false;
    }
}