#include <bits/stdc++.h>

#define fin freopen("rsq.in","r",stdin)
#define fout freopen("rsq.out","w",stdout)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define sqr(x) ((x)*(x))
#define elif else if
#define I "%d"
#define II "%d%d"
#define III "%d%d%d"
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

#ifdef WIN32
    #define L "%I64d"
#else
    #define L "%lld"
#endif

using namespace std;

typedef unsigned long long ull;
typedef pair <int,int> pii;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <pii> vii;
typedef map <int,int> mii;
typedef long long ll;
typedef long double ld;

const ll maxll=numeric_limits<ll>::max();
const int maxint=numeric_limits<int>::max();
const ll md=1e9+7;
const ld eps=1e-6;

int main()
{
    int n,a,b;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int zn;
        cin>>zn;
        if (zn==1) a=i+1;
        if (zn==n) b=i+1;
    }
    int ans1,ans2;
    if (a>b) swap(a,b);
    cout<<max(n-a,b-1);
    return 0;
}