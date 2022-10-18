#include <bits/stdc++.h>
#include <ext/rope>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define files(name) freopen(name".in","r",stdin); freopen(name".out","w",stdout);
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define stop system("pause");
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
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef set<int> si;
typedef set<pii> sii;
typedef map<int,int> mii;
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

int main()
{
    int t,x,s;
    cin>>t>>x>>s;
    if (s<t) return cout<<"NO", 0;
    if (s==t) return cout<<"YES", 0;
    if (s==t+1)
    {
        if (x<=1) cout<<"YES";
        else cout<<"NO";
        return 0;
    }
    if (x==0)
    {
        if (s==t+1) cout<<"YES";
        else cout<<"NO";
        return 0;
    }
    if ((s-t)%x==0) return cout<<"YES", 0;
    if ((s-1-t)%x==0&&s-1-t!=0) return cout<<"YES", 0;
    cout<<"NO";
}