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
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;

const ll maxll=numeric_limits<ll>::max();
const int maxint=numeric_limits<int>::max();
const int arr=2e5+10;
const int ar=2e3+10;
const ld pi=acos(-1);
const ll md=1e9+7;
const ld eps=1e-6;

///---program start---///

bool x[arr],y[arr];

int main()
{
    ll n,m;
    cin>>n>>m;
    ll all=n*n;
    ll sum1=0;
    ll sum2=0;
    for (int i=0;i<m;i++)
    {
        ll xx,yy;
        cin>>xx>>yy;
        if (x[xx]&&y[yy]) cout<<all<<" ";
        elif (!x[xx]&&!y[yy])
        {
            cout<<all-2*n+1+sum1+sum2<<" ";
            all-=2*n-1-sum1-sum2;
        }
        else
        {
            if (x[xx])
            {
                cout<<all-n+1+sum1-1<<" ";
                all-=n-1-sum1+1;
            }
            else
            {
                cout<<all-n+1+sum2-1<<" ";
                all-=n-1-sum2+1;
            }
        }
        if (!x[xx]) x[xx]=true, sum1++;
        if (!y[yy]) y[yy]=true, sum2++;
    }
}