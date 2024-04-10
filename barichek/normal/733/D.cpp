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

map<pii,multiset<pii>> mapka;

main()
{
    int n;
    cin>>n;
    vector<pair<pii,int>> vec;
    vec.clear();
    int ans=0;
    int res1=0;
    int res2=-1;
    for (int i=0;i<n;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        int a[3]={x,y,z};
        sort(a,a+3);
        x=a[0];
        y=a[1];
        z=a[2];
        vec.pb(mp(mp(x,y),z));
        mapka[mp(x,y)].insert(mp(z,i));
        mapka[mp(y,z)].insert(mp(x,i));
        mapka[mp(x,z)].insert(mp(y,i));
        if (ans<min(min(x,y),z))
            ans=min(min(x,y),z),
            res1=i;
    }
    for (int i=0;i<n;i++)
    {
        int x=vec[i].fir.fir;
        int y=vec[i].fir.sec;
        int z=vec[i].sec;
        mapka[mp(x,y)].erase(mapka[mp(x,y)].find(mp(z,i)));
        mapka[mp(x,z)].erase(mapka[mp(x,z)].find(mp(y,i)));
        mapka[mp(y,z)].erase(mapka[mp(y,z)].find(mp(x,i)));
        if (!mapka[mp(x,y)].empty()&&ans<min(min(x,y),mapka[mp(x,y)].rbegin()->fir+z))
            ans=min(min(x,y),mapka[mp(x,y)].rbegin()->fir+z),
            res1=i,
            res2=mapka[mp(x,y)].rbegin()->sec;
        if (!mapka[mp(y,z)].empty()&&ans<min(min(y,z),mapka[mp(y,z)].rbegin()->fir+x))
            ans=min(min(y,z),mapka[mp(y,z)].rbegin()->fir+x),
            res1=i,
            res2=mapka[mp(y,z)].rbegin()->sec;
        if (!mapka[mp(x,z)].empty()&&ans<min(min(x,z),mapka[mp(x,z)].rbegin()->fir+y))
            ans=min(min(x,z),mapka[mp(x,z)].rbegin()->fir+y),
            res1=i,
            res2=mapka[mp(x,z)].rbegin()->sec;
        mapka[mp(x,y)].insert(mp(z,i));
        mapka[mp(y,z)].insert(mp(x,i));
        mapka[mp(x,z)].insert(mp(y,i));
    }
    cout<<1+(res2!=-1)<<"\n";
    cout<<res1+1<<" ";
    if (res2!=-1)
        cout<<res2+1;
}