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

#define ld double

bool cmp(pair<ld,int>& a,pair<ld,int>& b)
{
    return a.fir>b.fir||(a.fir==b.fir&&a.sec<b.sec);
}

main()
{
    int n;
    cin>>n;
    ld t1,t2,k;
    cin>>t1>>t2>>k;
    vector< pair<ld,int> > ans;
    for (int i=1;i<=n;i++)
    {
        ld u,v;
        cin>>u>>v;
        ans.pb(mp(max(((u*t1)*(100.0-k)/100.0)+t2*v,((v*t1)*(100.0-k)/100.0)+t2*u),i));
    }
    sort(all(ans),cmp);
    for (auto i:ans)
        cout<<i.sec<<" "<<fixed<<setprecision(2)<<i.fir<<"\n";
}