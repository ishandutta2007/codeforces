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

int n,k;
vi a;
vi pref;

int get(int l,int r)
{
    return pref[r]-(l==0?0:pref[l-1]);
}

bool check(int x)
{
    for (int i=0;i<=signed(a.size())-x;i++)
        if (x-get(i,i+x-1)<=k)
            return true;
    return false;
}

void set_ans(int x)
{
    for (int i=0;i<=signed(a.size())-x;i++)
        if (x-get(i,i+x-1)<=k)
        {
            for (int j=i;j<i+x;j++)
                a[j]=1;
            return;
        }
}

main()
{
    cin>>n>>k;
    a.resize(n);
    for (auto &i:a)
        cin>>i;
    pref.pb(a.front());
    for (int i=1;i<a.size();i++)
        pref.pb(pref.back()+a[i]);
    int l=0,r=n;
    while (r-l>1)
        if (check((l+r)/2))
            l=(l+r)/2;
        else
            r=(l+r)/2;
    if (check(r))
        set_ans(r),
        cout<<r<<"\n";
    else
        set_ans(l),
        cout<<l<<"\n";
    for (auto i:a)
        cout<<i<<" ";
}