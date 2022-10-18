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

int ans[arr];

main()
{
    int n,l,r;
    cin>>n>>l>>r;
    set<int> oryshych;
    vi a;
    a.clear();
    a.resize(n);
    for (auto &i:a)
        cin>>i;
    vector<pii> p;
    p.clear();
    for (int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        p.pb(mp(val,i));
    }
    sort(all(p));
    vector<pii> kakaha;
    for (int i=0;i<p.size();i++)
    {
        int val=p[i].sec;
        int want=l-a[val];
        kakaha.pb(mp(want,val));
    }
    int last=-1e15;
    for (int i=0;i<kakaha.size();i++)
    {
        //cerr<<i<<" :: "<<kakaha[i].fir<<" "<<kakaha[i].sec<<" "<<last<<"\n";
        last=max(last+1,kakaha[i].fir);
        ans[kakaha[i].sec]=last;
        //cerr<<"put to "<<kakaha[i].sec<<" val :: "<<last<<"\n";
    }
    for (int i=0;i<n;i++)
        ans[i]+=a[i];
    for (int i=0;i<n;i++)
        if (ans[i]<l||ans[i]>r)
            return cout<<-1, 0;
    for (int i=0;i<n;i++)
        cout<<ans[i]<<" ";
}