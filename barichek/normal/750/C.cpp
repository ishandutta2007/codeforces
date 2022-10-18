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

vector<pii> a;

int check(int x)
{
    for (auto i:a)
    {
        if (x<1900&&i.sec==1) return 2;
        if ((x>=1900)^(i.sec==1)) return 1;
        x+=i.fir;
    }
    return 0;
}

int ans(int x)
{
    for (auto i:a)
        x+=i.fir;
    return x;
}

main()
{
    int n;
    cin>>n;
    a.clear();
    a.resize(n);
    for (auto &i:a)
        cin>>i.fir>>i.sec;
    int l=-1e9;
    int r=1e9;
    while (r-l>1)
    {
        //cout<<l<<" "<<r<<" !\n";
        int cur=check((l+r)/2);
        if (cur==0||cur==2) l=(l+r)/2;
        if (cur==1) r=(l+r)/2;
    }
    int cur=check(r);
    if (r==1e9) return cout<<"Infinity", 0;
    if (cur==0) return cout<<ans(r), 0;
    cur=check(l);
    if (cur==0) return cout<<ans(l), 0;
    return cout<<"Impossible", 0;
}