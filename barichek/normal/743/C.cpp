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

main()
{
    int n;
    cin>>n;
    for (int x=1;x<=1e4+1;x++)
        for (int y=x+1;y<=1e4+2;y++)
            if (2*x*y!=n*(x+y))
                if ((n*x*y)%(2*x*y-n*(x+y))==0&&(n*x*y)/(2*x*y-n*(x+y))>=1&&(n*x*y)/(2*x*y-n*(x+y))<=1e9)
                     if ((n*x*y)/(2*x*y-n*(x+y))!=x&&(n*x*y)/(2*x*y-n*(x+y))!=y)
                        return cout<<x<<" "<<y<<" "<<(n*x*y)/(2*x*y-n*(x+y)), 0;
    cout<<-1;
}