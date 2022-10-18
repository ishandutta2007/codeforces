#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define files_ds(name) freopen(name".dat","r",stdin); freopen(name".sol","w",stdout);
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

const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ld eps=1e-10;
const ll md=1e9+7;

///---program start---///

int n;
int x[arr];
int v[arr];

bool check(ld time__)
{
    ld max_l=-1e15,min_r=1e15;
    for (int i=1;i<=n;i++)
    {
        ld cur_l=x[i]-v[i]*time__;
        ld cur_r=x[i]+v[i]*time__;
        max_l=max(max_l,cur_l);
        min_r=min(min_r,cur_r);
    }
    return max_l<=min_r;
}

main()
{
    fast;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>x[i];
    for (int i=1;i<=n;i++)
        cin>>v[i];
    ld l=0,r=1e15;
    while (r-l>eps)
    {
        ld m=(l+r)/2.0;
        if (check(m))
            r=m;
        else
            l=m;
    }
    cout<<fixed<<setprecision(10)<<l<<"\n";
}