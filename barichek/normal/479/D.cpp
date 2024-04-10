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

int main()
{
    set<int> setik;
    vi a;
    int n,l,x,y;
    cin>>n>>l>>x>>y;
    a.resize(n);
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        setik.insert(a[i]);
    }
    bool had1=false;
    for (int i=0;i<n;i++)
        had1|=(setik.count(a[i]-x)||setik.count(a[i]+x));
    bool had2=false;
    for (int i=0;i<n;i++)
        had2|=(setik.count(a[i]-y)||setik.count(a[i]+y));
    if (!had1+!had2<2)
    {
        cout<<(!had1+!had2)<<"\n";
        if (!had1) cout<<x<<" ";
        if (!had2) cout<<y<<" ";
        return 0;
    }
    for (int i=0;i<n;i++)
        if (setik.count(a[i]-y-x))
            return cout<<1<<"\n"<<a[i]-x, 0;
        elif (setik.count(a[i]+y+x))
            return cout<<1<<"\n"<<a[i]+x, 0;
        elif (setik.count(a[i]+y-x)&&a[i]+y<=l)
            return cout<<1<<"\n"<<a[i]+y, 0;
        elif (setik.count(a[i]-y+x)&&a[i]-y>=0)
            return cout<<1<<"\n"<<a[i]-y, 0;
    cout<<(!had1+!had2)<<"\n";
    if (!had1) cout<<x<<" ";
    if (!had2) cout<<y<<" ";
    return 0;
}