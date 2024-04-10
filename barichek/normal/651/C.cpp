#include <bits/stdc++.h>
#include <ext/rope>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define all(a) a.begin(),a.end()
#define elif else if
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;
using namespace __gnu_cxx;

typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

const ll maxll=numeric_limits<ll>::max();
const int maxint=numeric_limits<int>::max();
const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ll md=1e9+7;
const ld eps=1e-6;

///---program start---///

map<int,ll> cntx, cnty;
map<pii,ll> cnt;

int main()
{
    int n;
    cin>>n;
    while (n--)
    {
        int xx,yy;
        cin>>xx>>yy;
        cntx[xx]++;
        cnty[yy]++;
        cnt[mp(xx,yy)]++;
    }
    ll res=0;
    for (auto i:cntx)
        res+=i.sec*(i.sec-1)/2;
    for (auto i:cnty)
        res+=i.sec*(i.sec-1)/2;
    for (auto i:cnt)
        res-=i.sec*(i.sec-1)/2;
    cout<<res;
}